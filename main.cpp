#include "event_handler.h"
#include <iostream>
#include <string>

void godEventCallback(const std::string &event) {
  std::cout << "Ares event: " << event << std::endl;
}

int main() {
  EldenTree::EventHandler<std::string> eldenTree;

  // Register gods and their event callbacks
  eldenTree.registerEvent("Ares", godEventCallback);
  eldenTree.registerEvent("Irene", [](const std::string &event) {
    std::cout << "Irene event: " << event << std::endl;
  });

  // Add events for the gods
  eldenTree.addEvent("Ares", "Battle started!");
  eldenTree.addEvent("Irene", "Truce declared!");
  eldenTree.addEvent("Ares", "Battle started again!");

  // Give some time for the events to be processed
  std::this_thread::sleep_for(std::chrono::microseconds(2));

  return 0;
}
