/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// Brief Digested Understanding:
// -----
// This problem gives a directed graph and asks: which nodes are "safe"—meaning,
// if you start at that node, you cannot ever get stuck in a cycle, no matter
// what path you follow. Officially, a node is safe if every path starting
// from it only leads eventually to a terminal node (a node with no outgoing
// edges) or to other already-known safe nodes. In other words, "which nodes
// can't possibly reach a cycle, even indirectly?"

// High-Level Summary:
// -----
// We'll approach this problem using a combination of graph traversal and
// cycle detection. A standard and efficient way is to use DFS with a
// coloring/marking scheme, where we mark nodes as: unvisited, visiting (on
// stack), or safe. If during DFS we encounter a "visiting" node, we've found a
// cycle. Nodes confirmed not part of any cycle are marked as safe and memoized.
// We modularize the DFS into a helper function for clarity and maintain a
// state array per node.
// Time complexity: O(V + E), where V = number of nodes, E = number of edges.
// Space complexity: O(V) for the state, visitation, and call stacks.

// @lc code=start
#include <vector> // Include vector for using std::vector
using std::vector;

class Solution {
public:
  /**
   * Function to find all eventual safe nodes in a directed graph.
   * @param graph: Adjacency list representation of the directed graph.
   * @return Sorted vector of safe node indices.
   */
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();    // Number of nodes in the graph
    vector<int> state(n, 0); // State per node: 0=unvisited, 1=visiting, 2=safe

    // Helper function: True if node is safe, false if it can reach a cycle.
    auto isSafe = [&](int node, auto &&isSafe) -> bool {
      if (state[node] == 1) {
        // If node is currently visiting (recursion stack), we've found a cycle.
        return false;
      }
      if (state[node] == 2) {
        // Node is already confirmed as safe, reuse memoization.
        return true;
      }
      state[node] = 1; // Mark as visiting

      // Visit all outgoing neighbors of the current node.
      for (int neighbor : graph[node]) {
        if (!isSafe(neighbor, isSafe)) {
          // If any neighbor is unsafe (in a cycle), so is this node.
          return false;
        }
      }
      state[node] = 2; // Mark as safe; all paths from here lead to safe nodes.
      return true;
    };

    vector<int> result; // To collect safe nodes

    // Evaluate every node in the graph
    for (int i = 0; i < n; ++i) {
      // If isSafe returns true (node is not part of or leading to any cycle),
      // add it to result
      if (isSafe(i, isSafe)) {
        result.push_back(i);
      }
    }
    // The result vector grows in ascending order (since we iterate from 0 to
    // n-1)
    return result;
  }
};
// @lc code=end
