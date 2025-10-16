/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// Brief Digested Understanding:
// ---
// This problem asks us, given a set of one-way connections between computer
// nodes each with a defined travel time, to compute the shortest time it takes
// for a signal sent from a given node (k) to reach every other node in the
// network. If it’s impossible for some node(s) to receive the signal, we return
// -1. Essentially, this is a single-source shortest path problem on a directed,
// weighted graph: we want the longest shortest time from k to any node, or -1
// if not all nodes are reachable.

// High-Level Summary:
// ---
// We model the network as a directed weighted graph. We'll use Dijkstra's
// algorithm since all edge weights are non-negative and the number of nodes is
// small (<= 100). We're interested in the minimum time from k to every other
// node. We'll keep track of visited nodes and their shortest arrival times. If,
// after running the algorithm, any node hasn't been reached, we return -1.
// Otherwise, our answer is the highest arrival time found among all nodes. For
// implementation, we'll use a min-heap (priority queue) to efficiently pick the
// next node with the shortest current distance.
//
// Time Complexity: O(E * log N), where E is the number of edges and N is the
// number of nodes. Space Complexity: O(N + E) for the graph representation and
// data structures.
//
// The solution is modularized for clarity, with helper functions for building
// the adjacency list and running Dijkstra’s algorithm.

#include <limits>
#include <queue>
#include <utility>
#include <vector>

using std::pair;
using std::priority_queue;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main entry point for the LeetCode problem
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // Build the graph as an adjacency list for efficient edge lookup.
    vector<vector<pair<int, int>>> graph = buildGraph(times, n);

    // Run Dijkstra's algorithm from node k to compute shortest arrival times.
    vector<int> dist = dijkstra(graph, n, k);

    // Find the maximal time to reach any node.
    int maxTime = getMaxTime(dist);

    // If any node is still unreachable (distance is infinite), return -1.
    return maxTime == std::numeric_limits<int>::max() ? -1 : maxTime;
  }

private:
  // Builds a directed weighted graph from the input edge list.
  // graph[u] = list of pairs (v, w) meaning edge u->v with time w.
  vector<vector<pair<int, int>>> buildGraph(const vector<vector<int>> &times,
                                            int n) {
    // Initialize empty adjacency list.
    vector<vector<pair<int, int>>> graph(n + 1); // nodes are 1-indexed
    for (const auto &edge : times) {
      int u = edge[0], v = edge[1], w = edge[2];
      // Add directed edge from u to v with weight w.
      graph[u].emplace_back(v, w);
    }
    return graph;
  }

  // Standard Dijkstra's Algorithm: computes shortest distance from source to
  // all nodes.
  vector<int> dijkstra(const vector<vector<pair<int, int>>> &graph, int n,
                       int start) {
    // Distance to each node; start at infinite (unreachable).
    vector<int> dist(n + 1, std::numeric_limits<int>::max());

    // Min-heap: stores (current_dist, node). Uses greater<int> for min
    // behavior.
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   std::greater<pair<int, int>>>
        minHeap;

    // Dijkstra initialization: signal starts at 'start'
    dist[start] = 0;
    minHeap.emplace(0, start); // Distance to itself is 0

    // Track which nodes have already been finalized.
    vector<bool> visited(n + 1, false);

    while (!minHeap.empty()) {
      int timeSoFar = minHeap.top().first;
      int u = minHeap.top().second;
      minHeap.pop();

      // If we've finalized this node, skip it.
      if (visited[u])
        continue;
      visited[u] = true;

      // Explore all outgoing edges.
      for (const auto &[v, w] : graph[u]) {
        // If reaching v via u gives a shorter time, update and push.
        if (dist[v] > timeSoFar + w) {
          dist[v] = timeSoFar + w;
          minHeap.emplace(dist[v], v);
        }
      }
    }
    return dist;
  }

  // Returns the maximum distance among all reachable nodes (skipping unused
  // index 0).
  int getMaxTime(const vector<int> &dist) {
    int maxTime = 0;
    for (size_t i = 1; i < dist.size(); ++i) {
      if (dist[i] == std::numeric_limits<int>::max())
        return std::numeric_limits<int>::max(); // Unreachable node
      if (dist[i] > maxTime)
        maxTime = dist[i]; // Track the slowest-receiving node
    }
    return maxTime;
  }
};
// @lc code=end
