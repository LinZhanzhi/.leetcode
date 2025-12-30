/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

/*
 * Brief Digested Understanding:
 * --------------------------------------
 * The core question here is: Can you color every node in the given undirected
 * graph with just two colors (think "group A" and "group B"), so that no two
 * directly connected (adjacent) nodes ever share the same color?
 * This is the definition of a bipartite graph. If it's possible, the graph is
 * bipartite; otherwise, it's not. Since the graph may have several disconnected
 * components, we need to check each part separately. The problem boils down to
 * whether we can perform this coloring globally, for all nodes, following the
 * rules.
 *
 * Key constraints: The input is given as adjacency lists; graphs may be
 * disconnected; n is up to 100; no self-loops or multiple edges.
 *
 *
 * High-Level Summary:
 * --------------------------------------
 * We'll solve the bipartiteness check via a coloring algorithm, traversing the
 * graph and trying to assign colors (0 or 1) such that adjacent nodes never get
 * the same color. We'll use BFS (breadth-first search) for traversal and
 * coloring, since it naturally helps spot conflicts. For each unvisited node,
 * we launch BFS from that node, coloring it and enforcing its neighbors take
 * the alternate color. If we ever find two neighbors with the same color, the
 * graph is not bipartite. Since the graph might be disconnected, we'll run BFS
 * for every node that hasn't been colored yet. Time complexity is O(N + E);
 * space is O(N).
 */

#include <queue>  // For std::queue, used in BFS
#include <vector> // For std::vector, used for the adjacency list and coloring

using std::queue;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to check if the graph is bipartite.
  // Returns true if the graph can be colored with two colors so that
  // no two adjacent nodes share the same color.
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size(); // Number of nodes in the graph
    vector<int> color(n,
                      -1); // Color of each node: -1=uncolored, 0 & 1 are colors

    // Helper function to perform BFS coloring from a given node
    // Returns false if a coloring conflict is found
    auto bfsColor = [&](int start) -> bool {
      queue<int> q;
      q.push(start);
      color[start] = 0; // Start with color 0

      // Standard BFS loop
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
          if (color[neighbor] == -1) {
            // If neighbor hasn't been colored, assign opposite color
            color[neighbor] = 1 - color[node];
            q.push(neighbor);
          } else if (color[neighbor] == color[node]) {
            // If neighbor is colored the same as current, not bipartite
            return false;
          }
          // Otherwise, if neighbor is colored with opposite color, OK, continue
        }
      }
      return true;
    };

    // Main loop: ensure every node in every component is checked
    for (int i = 0; i < n; ++i) {
      if (color[i] == -1) {
        // If node i hasn't been colored, it starts a new component
        if (!bfsColor(i)) {
          // If any component fails bipartiteness, whole graph is not bipartite
          return false;
        }
      }
    }
    // If all components pass, graph is bipartite!
    return true;
  }
};
// @lc code=end
