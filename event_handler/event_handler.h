#pragma once
#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>

namespace EldenTree {
template <typename EventType> class EventHandler {
public:
  using EventCallback = std::function<void(const EventType &)>;

  EventHandler();

  ~EventHandler();

  void registerEvent(const std::string &godName, const EventCallback &callback);

  void addEvent(const std::string &godName, const EventType &event);

  void dispatchEvents();

private:
  std::queue<std::pair<std::string, EventType>> m_eventQueue;
  std::unordered_map<std::string, EventCallback> m_godCallbacks;

  std::mutex m_queueMutex;
  std::condition_variable m_cv;
  std::atomic<bool> m_done;
  std::thread m_worker;
};
} // namespace EldenTree
