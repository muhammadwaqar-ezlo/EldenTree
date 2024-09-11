#include "event_handler.h"
#include <thread>

namespace EldenTree {
template <typename EventType>
EventHandler<EventType>::EventHandler() : m_done(false) {
  m_worker = std::thread([this]() { this->dispatchEvents(); });
}

template <typename EventType> EventHandler<EventType>::~EventHandler() {
  {
    std::unique_lock<std::mutex> lock(m_queueMutex);
    m_done = true;
    m_cv.notify_all();
  }
  m_worker.join();
}

template <typename EventType>
void EventHandler<EventType>::registerEvent(const std::string &godName,
                                            const EventCallback &callback) {
  std::unique_lock<std::mutex> lock(m_queueMutex);
  if (m_godCallbacks.find(godName) != m_godCallbacks.end()) {
    throw std::runtime_error("God with this name already registered");
  }
  m_godCallbacks[godName] = callback;
}

template <typename EventType>
void EventHandler<EventType>::addEvent(const std::string &godName,
                                       const EventType &event) {
  std::unique_lock<std::mutex> lock(m_queueMutex);
  m_eventQueue.push({godName, event});
  m_cv.notify_one();
}

template <typename EventType> void EventHandler<EventType>::dispatchEvents() {
  while (!m_done) {
    std::unique_lock<std::mutex> lock(m_queueMutex);
    m_cv.wait(lock, [this]() { return !m_eventQueue.empty() || m_done; });

    if (!m_eventQueue.empty()) {
      auto eventPair = m_eventQueue.front();
      m_eventQueue.pop();

      if (m_godCallbacks.find(eventPair.first) != m_godCallbacks.end()) {
        m_godCallbacks[eventPair.first](eventPair.second);
      }
    }
  }
}

// Explicit instantiation for common event types
template class EventHandler<std::string>;

template class EventHandler<int>;
} // namespace EldenTree