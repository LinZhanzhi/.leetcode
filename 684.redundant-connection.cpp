/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// Brief Digested Understanding:
// -----
// This problem boils down to maintaining a tree-like structure (no cycles,
// fully connected) by removing one extra edge that introduces a cycle. We're
// given an undirected connected graph in edge-list form, with exactly one
// redundant edge. Our task is to return that edge. The intuition is that any
// edge that causes two nodes from the same connected group to connect again
// would form a cycle, so we detect such cases.

// High-Level Summary:
// -----
// We'll use the Disjoint Set Union (Union-Find) data structure with path
// compression and union by rank for efficiency. As we process each edge,
// we'll unite their nodes if they're not already in the same component. If
// they are already connected (i.e., find(u) == find(v)), then that edge forms
// a cycle and is redundant, so we return it. We use helper functions
// (`findRoot` and `unionSet`) instead of lambdas, since lambdas with recursion
// involving themselves can cause compilation errors in C++ (as in this
// problem). Time: O(N*α(N)), Space: O(N).

#include <utility> // For std::pair
#include <vector> // Include the C++ vector class for edge lists and DSU arrays.


using std::pair;
using std::vector;

class Solution {
public:
  // Main function to find the edge whose removal will restore the tree property
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size(); // There are n edges, so nodes are labeled from 1 to n

    // Create parent and rank arrays for DSU; 1-based indexing
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 1);
    initializeDSU(parent, n);

    // Iterate over each edge and apply union-find algorithm
    for (const vector<int> &edge : edges) {
      int u = edge[0];
      int v = edge[1];

      // If u and v are already connected, the edge is redundant (forms a cycle)
      if (!unionSet(parent, rank, u, v)) {
        // Return the redundant edge immediately
        return edge;
      }
      // If not connected, unionSet has merged the two sets; continue checking
    }

    // The input always guarantees at least one redundant edge, so this should
    // never be reached
    return {};
  }

private:
  // Helper function to initialize the DSU parent array
  void initializeDSU(vector<int> &parent, int n) {
    // Each node is initially its own parent (standalone component)
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    // Rank is already initialized by the caller
  }

  // Helper function to find the root representative of x with path compression
  int findRoot(vector<int> &parent, int x) {
    // If x is not its own parent, recursively find its root
    if (parent[x] != x) {
      // Path compression: flatten the tree for future efficiency
      parent[x] = findRoot(parent, parent[x]);
    }
    return parent[x];
  }

  // Helper function to attempt to union two sets
  // Returns true if union performed (no cycle), false if already in same set
  // (cycle detected)
  bool unionSet(vector<int> &parent, vector<int> &rank, int x, int y) {
    int rootX = findRoot(parent, x);
    int rootY = findRoot(parent, y);

    // If roots are same, x and y are already connected, so adding this edge
    // forms a cycle
    if (rootX == rootY) {
      return false;
    }

    // Union by rank: attach the smaller tree to the larger one for efficiency
    if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
      // No need to update rank[rootY] since its height won't change
    } else if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else {
      // Same rank: choose one as new root and increment its rank
      parent[rootY] = rootX;
      rank[rootX]++;
    }
    return true; // Union successful; no cycle formed
  }
};
// @lc code=end
