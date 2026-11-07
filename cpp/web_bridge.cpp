// Browser interface only. The graph, class, and Dijkstra algorithm
// are implemented in client.cpp and travelplanner.cpp

#include <bits/stdc++.h>
#include "travelplanner.hpp"

extern int original_main();

namespace {
constexpr int N = 11;
const char* const names[N] = {
  "Bhubaneswar Railway Station", "Lingaraj Temple",
  "Udayagiri and Khandagiri Caves", "Nandankanan Zoological Park",
  "Dhauli Shanti Stupa", "Kalinga Stadium", "Regional Science Centre",
  "Odisha State Museum", "Ekamra Kanan Botanical Gardens",
  "Pathani Samanta Planetarium", "Rajarani Temple"
};
bool ready = false;
std::string last_result;
}

extern "C" {
// The client initializes the singleton with its graph data.

int tp_init() {
  if (ready) return 1;
  std::istringstream fake_input("N\n");
  std::ostringstream discarded_output;
  std::streambuf* old_input = std::cin.rdbuf(fake_input.rdbuf());
  std::streambuf* old_output = std::cout.rdbuf(discarded_output.rdbuf());
  std::cin.clear();
  original_main();
  std::cout.flush();
  std::cin.rdbuf(old_input);
  std::cout.rdbuf(old_output);
  std::cin.clear();
  ready = true;
  return 1;
}

const char* tp_route_text(int from, int to) {
  if (!ready && !tp_init()) return "Engine initialization failed.";
  if (from < 0 || from >= N || to < 0 || to >= N) {
    last_result = "Invalid source or destination.";
    return last_result.c_str();
  }
  std::ostringstream captured;
  std::streambuf* old_output = std::cout.rdbuf(captured.rdbuf());
  TravelPlanner::getTravelPlanner(0, {}, {})->shortestPathWithMinimumStops(names[from], names[to]);
  std::cout.flush();
  std::cout.rdbuf(old_output);
  last_result = captured.str();
  return last_result.c_str();
}
}
