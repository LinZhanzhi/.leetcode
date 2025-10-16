/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// Brief Digested Understanding:
// ----
// This problem is really about finding and listing *all* possible paths
// from the starting node (0) to the ending node (n-1) in a directed acyclic
// graph (DAG), where the graph is represented as adjacency lists. Instead of
// just computing a count or checking if a path exists, we must generate every
// route (ordered list of nodes) that leads from 0 to n-1. Since the input is a
// DAG, there’s no risk of infinite cycles, and all paths are guaranteed to
// terminate.

// High-Level Summary:
// ----
// We'll approach this using backtracking (depth-first search - DFS):
// at each node, we recursively try every possible next node, keep track of
// the current route, and whenever we reach the target (n-1), we record the
// resulting path. To ensure clarity and modularity, the recursive path-building
// will live in a dedicated helper function, which accumulates finished paths
// into a results vector. Because the graph size is small (n ≤ 15), this
// approach is efficient enough. We require only O(#paths * n) time and space,
// since every path gets explored, but the total remains modest for small n. No
// visited array is required in a DAG for this task.

#include <vector> // To use std::vector for graph and paths

using std::vector; // Make vector available directly for readability

// @lc code=start
class Solution {
public:
  // Main function to find all paths from node 0 to node n-1 in the DAG
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> paths; // To store all the valid paths found
    vector<int> currentPath;   // Tracks one path as we traverse
    int target = static_cast<int>(graph.size()) - 1; // Target node is n-1
    // Start DFS traversal from node 0 with an empty path
    dfs(graph, 0, target, currentPath, paths);
    return paths;
  }

private:
  // Helper function for backtracking DFS
  // - graph: adjacency list of the DAG
  // - node: current node we're visiting
  // - target: node we want to reach (n-1)
  // - currentPath: holds the nodes along the current traversal path
  // - paths: accumulates all discovered paths from source to target
  void dfs(const vector<vector<int>> &graph, int node, int target,
           vector<int> &currentPath, vector<vector<int>> &paths) {
    currentPath.push_back(node); // Add the current node to the path

    if (node == target) {
      // If we've reached the target, save a copy of the path
      paths.push_back(currentPath);
    } else {
      // Otherwise, explore all neighbors recursively
      for (int neighbor : graph[node]) {
        dfs(graph, neighbor, target, currentPath, paths);
      }
    }

    // Backtrack: remove the current node before returning to previous state
    currentPath.pop_back();
    // This ensures that each recursive call gets its own path state
  }
};
// @lc code=end
