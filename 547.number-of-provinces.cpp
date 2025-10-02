/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a matrix representing direct connections between cities. If two
 * cities are directly or indirectly connected (through a chain of connections),
 * they belong to the same "province." Our goal is to count how many such
 * provinces (connected groups) exist in the network. This is equivalent to
 * finding the number of connected components in an undirected graph, where each
 * city is a node and each direct connection is an edge.
 *
 * High-Level Summary:
 * ----
 * The solution treats the matrix as an adjacency matrix of an undirected graph.
 * We use Depth-First Search (DFS) to explore all cities connected to a given
 * city, marking them as visited. Each time we start a DFS from an unvisited
 * city, we have found a new province. We repeat this process for all cities,
 * counting the number of times we initiate a DFS. The time complexity is
 * O(n^2), since we may visit every cell in the matrix, and the space complexity
 * is O(n) for the visited array and recursion stack.
 */

#include <vector> // For std::vector
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to count the number of provinces (connected components)
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();     // Number of cities
    vector<bool> visited(n, false); // Track which cities have been visited
    int provinceCount = 0;          // Result: number of provinces

    // Iterate through each city
    for (int city = 0; city < n; ++city) {
      // If the city has not been visited, it's a new province
      if (!visited[city]) {
        dfs(isConnected, visited, city); // Visit all cities in this province
        ++provinceCount;                 // Increment province count
      }
    }
    return provinceCount;
  }

private:
  // Helper function to perform DFS and mark all cities in the same province
  void dfs(const vector<vector<int>> &isConnected, vector<bool> &visited,
           int city) {
    visited[city] = true; // Mark the current city as visited

    // Explore all possible connections from this city
    for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {
      // If there is a direct connection and the neighbor hasn't been visited
      if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
        dfs(isConnected, visited, neighbor); // Recursively visit the neighbor
      }
    }
  }
};
// @lc code=end
