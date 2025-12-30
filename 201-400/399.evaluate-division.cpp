/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given equations like "a / b = 2.0" and must answer queries like "a / c
 * = ?". Each variable is a string, and the equations form a network of
 * relationships. For each query, we need to find the value of the division if
 * possible, or return -1.0 if not. If a variable in the query is not present in
 * any equation, the answer is -1.0. The problem is essentially about finding a
 * path between two variables in a graph, where each edge has a weight (the
 * division value).
 */

/*
 * High-Level Summary:
 * ----
 * We model the equations as a weighted, bidirectional graph:
 *   - Each variable is a node.
 *   - Each equation "a / b = k" creates two edges: a->b (weight k) and b->a
 * (weight 1/k). To answer a query "x / y", we search for a path from x to y and
 * multiply the edge weights along the path. We use Depth-First Search (DFS) to
 * find such a path, keeping track of visited nodes to avoid cycles. For each
 * query, if either variable is missing or no path exists, we return -1.0.
 *
 * Time Complexity:
 *   - Building the graph: O(E), where E is the number of equations.
 *   - Each query: In the worst case, O(N), where N is the number of variables
 * (since we may visit all nodes).
 *   - For Q queries: O(Q * N)
 *
 * Space Complexity:
 *   - O(E + N), for the graph and visited set.
 */

#include <string>        // For std::string
#include <unordered_map> // For std::unordered_map
#include <unordered_set> // For std::unordered_set
#include <vector>        // For std::vector

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to evaluate the queries based on the given equations and
  // values
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    // Build the graph: each variable maps to its neighbors and the division
    // value
    unordered_map<string, unordered_map<string, double>> graph;

    // Construct the bidirectional graph from the equations and values
    for (int i = 0; i < equations.size(); ++i) {
      const string &A = equations[i][0];
      const string &B = equations[i][1];
      double k = values[i];
      // Add edge A -> B with weight k
      graph[A][B] = k;
      // Add edge B -> A with weight 1/k
      graph[B][A] = 1.0 / k;
    }

    vector<double> results; // To store the answer for each query

    // Process each query
    for (const auto &query : queries) {
      const string &src = query[0];
      const string &dst = query[1];

      // If either variable is not in the graph, answer is -1.0
      if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) {
        results.push_back(-1.0);
      } else if (src == dst) {
        // If both variables are the same and exist, answer is 1.0
        results.push_back(1.0);
      } else {
        unordered_set<string> visited; // To avoid revisiting nodes in DFS
        double val = dfs(graph, src, dst, 1.0, visited);
        results.push_back(val);
      }
    }
    return results;
  }

private:
  // Helper function: DFS to find a path from current to target, accumulating
  // the product of weights
  double dfs(const unordered_map<string, unordered_map<string, double>> &graph,
             const string &current, const string &target, double accProduct,
             unordered_set<string> &visited) {
    // Mark the current node as visited
    visited.insert(current);

    // If we have reached the target, return the accumulated product
    if (current == target) {
      return accProduct;
    }

    // Explore all neighbors of the current node
    for (const auto &neighbor : graph.at(current)) {
      const string &nextNode = neighbor.first;
      double weight = neighbor.second;
      // Only visit unvisited neighbors to avoid cycles
      if (visited.find(nextNode) == visited.end()) {
        // Recursively search for the target from the neighbor
        double result =
            dfs(graph, nextNode, target, accProduct * weight, visited);
        // If a valid path is found, return the result
        if (result != -1.0) {
          return result;
        }
      }
    }
    // If no path is found, return -1.0
    return -1.0;
  }
};
// @lc code=end
