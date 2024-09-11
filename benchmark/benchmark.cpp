#include "event_handler.h"
#include <benchmark/benchmark.h>
#include <string>

// Benchmark for adding and dispatching string events
static void BM_AddAndDispatchStringEvent(benchmark::State &state) {
  EldenTree::EventHandler<std::string> eventHandler;

  // Register event handlers for two gods
  eventHandler.registerEvent("Zeus", [](const std::string &event) {
    benchmark::DoNotOptimize(event); // Simulate event processing for Zeus
  });
  eventHandler.registerEvent("Athena", [](const std::string &event) {
    benchmark::DoNotOptimize(event); // Simulate event processing for Athena
  });

  for (auto _ : state) {
    eventHandler.addEvent("Zeus", "Thunder Strike");
    eventHandler.addEvent("Athena", "Wisdom Blessing");
  }
}

// Benchmark for adding and dispatching integer events
static void BM_AddAndDispatchIntEvent(benchmark::State &state) {
  EldenTree::EventHandler<int> eventHandler;

  // Register event handlers for two gods
  eventHandler.registerEvent("Zeus", [](int event) {
    benchmark::DoNotOptimize(event); // Simulate event processing for Zeus
  });
  eventHandler.registerEvent("Athena", [](int event) {
    benchmark::DoNotOptimize(event); // Simulate event processing for Athena
  });

  for (auto _ : state) {
    eventHandler.addEvent("Zeus", 1);   // Add integer event for Zeus
    eventHandler.addEvent("Athena", 2); // Add integer event for Athena
  }
}

// Register the benchmarks
BENCHMARK(BM_AddAndDispatchStringEvent);
BENCHMARK(BM_AddAndDispatchIntEvent);

BENCHMARK_MAIN();
