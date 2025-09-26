/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a tree (an undirected, connected, acyclic graph) with n nodes
 * labeled 0 to n-1. We can choose any node as the root, and the height of the
 * tree is the longest path from the root to a leaf. Our goal is to find all
 * nodes that, when chosen as the root, result in the minimum possible tree
 * height. These nodes are called the roots of Minimum Height Trees (MHTs). The
 * task is to return a list of all such root labels.
 */

/*
 * High-Level Summary:
 * ----
 * The key insight is that the roots of MHTs are always the "center(s)" of the
 * tree. If we repeatedly remove all leaves (nodes with only one connection)
 * layer by layer, the last one or two nodes left are the centers. These are the
 * only possible roots for MHTs. This is similar to finding the center(s) of a
 * graph, and works because a tree has no cycles. The algorithm works as
 * follows:
 *   1. Build the adjacency list for the tree.
 *   2. Initialize a list of all leaves (nodes with only one neighbor).
 *   3. Iteratively remove leaves, updating the degree of their neighbors.
 *   4. Continue until 1 or 2 nodes remain; these are the MHT roots.
 *
 * Time Complexity: O(n), since each node and edge is processed at most once.
 * Space Complexity: O(n), for the adjacency list and auxiliary data structures.
 */

#include <queue>  // For std::queue
#include <vector> // For std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find all roots of Minimum Height Trees in a given tree.
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    // Edge case: If there is only one node, it is the only root.
    if (n == 1)
      return {0};

    // Step 1: Build the adjacency list for the tree.
    vector<vector<int>> adj(n); // adj[i] contains all neighbors of node i.
    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    // Step 2: Initialize a list of all leaves (nodes with only one neighbor).
    vector<int> leaves;
    for (int i = 0; i < n; ++i) {
      if (adj[i].size() == 1) {
        leaves.push_back(i);
      }
    }

    // Step 3: Iteratively remove leaves layer by layer.
    int remainingNodes = n;
    while (remainingNodes > 2) {
      int leavesCount = leaves.size();
      remainingNodes -= leavesCount; // Remove current leaves from the tree.
      vector<int> newLeaves;         // To store the next layer of leaves.

      // Remove each leaf and update its neighbor.
      for (int leaf : leaves) {
        // Each leaf has only one neighbor in a tree.
        int neighbor = adj[leaf][0];
        // Remove the leaf from its neighbor's adjacency list.
        adj[neighbor].erase(
            std::find(adj[neighbor].begin(), adj[neighbor].end(), leaf));
        // If the neighbor has become a leaf, add it to newLeaves.
        if (adj[neighbor].size() == 1) {
          newLeaves.push_back(neighbor);
        }
      }
      // Prepare for the next round.
      leaves = newLeaves;
    }

    // Step 4: The remaining 1 or 2 nodes are the roots of MHTs.
    return leaves;
  }
};
// @lc code=end
