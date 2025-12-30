/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// Brief Digested Understanding:
// This problem asks us whether it's possible to divide n people into two groups
// so that no two people who dislike each other are in the same group. Each
// edge in the dislikes list represents a mutual dislike (conflict). At its
// core, this is asking whether a specific graph is bipartite—that is, can we
// color the graph using two colors so that no two connected nodes have the same
// color?

// High-Level Summary:
// We'll model dislikes as an undirected graph, with each person as a node and
// each dislike as an edge. To determine if this graph can be split into two
// groups (bipartitioned without conflicts), we'll try to color the graph with
// two colors using a BFS (breadth-first search) or DFS. If we can color all
// nodes such that every edge connects nodes of different colors (without
// contradiction), the partition is possible (bipartite). We'll modularize by
// building an adjacency list and using a helper function to color each
// unvisited component. Time complexity is O(N + M) where M is dislikes.size();
// space is O(N + M) for the adjacency list and coloring array.

#include <queue>  // Needed for std::queue used in BFS
#include <vector> // Needed for std::vector

using std::queue;
using std::vector;

class Solution {
public:
  // Main function to determine possible bipartition
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    // Build adjacency list for the graph. Index 1-based.
    vector<vector<int>> adj(n + 1); // Person labels: 1 to n
    buildAdjacencyList(n, dislikes, adj);

    // This vector will keep track of the "color" (or group) of each node
    // 0: uncolored/unvisited, 1: group A, -1: group B
    vector<int> color(n + 1, 0);

    // Go through each person (since the graph may be disconnected)
    for (int person = 1; person <= n; ++person) {
      if (color[person] == 0) { // If not yet colored, need to start BFS/DFS
        if (!bfsCheckBipartite(person, adj, color))
          return false; // Conflict found; not bipartite
      }
    }
    // All groups colored without conflict; possible bipartition
    return true;
  }

private:
  // Helper function to build an adjacency list from the dislikes matrix
  void buildAdjacencyList(int n, const vector<vector<int>> &dislikes,
                          vector<vector<int>> &adj) {
    // dislikes[i] = [a, b] means there is an edge between a and b
    for (const auto &pair : dislikes) {
      int a = pair[0];
      int b = pair[1];
      // Add edge both ways (undirected)
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  // Helper function to check bipartiteness in a component using BFS
  // Returns true if successful, false if a conflict is found
  bool bfsCheckBipartite(int start, const vector<vector<int>> &adj,
                         vector<int> &color) {
    // Start BFS from this unvisited node with one color, say 1
    queue<int> q;
    q.push(start);
    color[start] = 1; // Assign to first group

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      // Check all neighbors of the current node
      for (int neighbor : adj[curr]) {
        if (color[neighbor] == 0) {
          // If not colored, assign the opposite color and add to queue
          color[neighbor] = -color[curr];
          q.push(neighbor);
        } else if (color[neighbor] == color[curr]) {
          // Found same color on both endpoints of an edge; not bipartite
          return false;
        }
        // If already colored with the correct color, keep going
      }
    }
    // No conflicts found; this component is bipartite
    return true;
  }
};
// @lc code=end
