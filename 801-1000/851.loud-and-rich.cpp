/*
 * @lc app=leetcode id=851 lang=cpp
 *
 * [851] Loud and Rich
 */

// @lc code=start

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about propagating the knowledge of "who is richer than whom"
 * among a set of people and determining, for every person x, who among all
 * people who have at least as much money as x is the quietest. "Quietest" means
 * having the lowest 'quiet[x]' value. We need to account for indirect
 * relationships (e.g., if A > B and B > C, then A > C) and respect all richer
 * relations' implications.
 *
 * In essence, for each person x, we want to find in the graph of "can reach via
 * richer relation" starting at x, the person (including x) with the minimal
 * quietness.
 *
 * High-Level Summary:
 * ----
 * We model the richer relationships as a directed acyclic graph (DAG), where an
 * edge from A to B means A is richer than B. We want for every person x, to
 * find along all paths from x through richer people, the person with the
 * smallest quiet value.
 *
 * The core algorithm will use memoized Depth-First Search (DFS) on this DAG:
 *   - For each person x, recursively compute the quietest person among x and
 * everyone richer than x.
 *   - Memoization avoids redundant computation since the same person can be
 * reached through different paths.
 *   - The construction is O(N + E), where N is number of people and E is the
 * number of richer relations.
 *   - Per-person DFS ensures every edge is traversed at most once in practice,
 * so the total time is O(N + E).
 *   - Space complexity: O(N + E) for graph and O(N) for memoization structures.
 */

#include <algorithm> // For std::min if needed.
#include <vector>    // For std::vector to store input/output data.

using std::vector; // To simplify notation in class and methods.

class Solution {
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    // Number of people
    int n = quiet.size();

    // Adjacency list: graph[person] contains a list of people that person is
    // richer than.
    vector<vector<int>> graph(n);
    for (const vector<int> &rel : richer) {
      // rel[0] is richer than rel[1], so we record that 'rel[0]' -> 'rel[1]'
      graph[rel[1]].push_back(rel[0]);
    }

    // answer[x]: the index of the quietest person at least as rich as x
    vector<int> answer(n, -1);

    // Helper function for DFS with memoization.
    // Returns the quietest person at least as rich as 'x'.
    std::function<int(int)> dfs = [&](int x) -> int {
      // If answer[x] is computed, simply return it (memoization).
      if (answer[x] != -1)
        return answer[x];

      // By default, the quietest is the person themselves.
      int min_person = x;

      // Explore all people richer than x.
      for (int richer_person : graph[x]) {
        // Recursively find the quietest for the richer person.
        int candidate = dfs(richer_person);
        // If this candidate is quieter, update.
        if (quiet[candidate] < quiet[min_person]) {
          min_person = candidate;
        }
      }

      // Memoize result.
      answer[x] = min_person;
      return min_person;
    };

    // Initiate DFS for each person to compute their answer.
    for (int i = 0; i < n; ++i) {
      dfs(i);
    }
    return answer;
  }
};

// @lc code=end
