#include "event_handler.h"
#include <gtest/gtest.h>
#include <string>

class EventHandlerTest : public ::testing::Test {};

TEST(EventHandlerTest, handleMultipleEvents) {
  std::vector<std::string> receivedEvents;

  EldenTree::EventHandler<std::string> handler;

  // Register callbacks
  handler.registerEvent("TestGod", [&receivedEvents](const std::string &event) {
    receivedEvents.push_back(event);
  });

  // Add multiple events
  handler.addEvent("TestGod", "Event 1");
  handler.addEvent("TestGod", "Event 2");

  // Give some time for the events to be processed
  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  // Verify that all events were received
  ASSERT_EQ(receivedEvents.size(), 2);
  EXPECT_EQ(receivedEvents[0], "Event 1");
  EXPECT_EQ(receivedEvents[1], "Event 2");
}

TEST(EventHandlerTest, godRegistrationCheck) {

  EldenTree::EventHandler<std::string> handler;

  // Register callbacks
  EXPECT_NO_THROW(
      handler.registerEvent("TestGod", [&](const std::string &event) {}););
  EXPECT_ANY_THROW(
      handler.registerEvent("TestGod", [&](const std::string &event) {}););
}