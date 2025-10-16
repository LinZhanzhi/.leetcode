/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start

#include <queue>         // For std::queue (BFS)
#include <string>        // For std::string
#include <unordered_set> // For std::unordered_set (to check visited/deadends)
#include <vector>        // For std::vector

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * This problem is all about navigating a state-space (the lock's 4-wheel
 * state) while avoiding "deadend" states, and trying to reach a specific
 * target state from the starting state "0000". Each move consists of turning
 * any one wheel up or down by one (with wraparound from 0⇆9). Reaching any
 * deadend locks you out permanently; so, you must find the shortest sequence
 * (if any exists) that turns "0000" to your target, never passing through
 * forbidden codes.
 *
 * High-Level Summary:
 * ----
 * We'll use Breadth-First Search (BFS) to efficiently find the minimum moves
 * required to reach the target from "0000", avoiding all deadends. BFS is
 * ideal here because each move has equal cost, and we want the shortest path.
 * - First, quickly check if the start ("0000") or the target is a deadend.
 * - Store all deadends in an unordered_set (hash set) for O(1) lookup.
 * - Store visited states to avoid revisiting.
 * - At each step, generate all possible next states by turning each of the
 *   4 wheels up or down.
 * - If we reach the target, return the move count at that point.
 * - If the BFS queue is exhausted, return -1 (impossible).
 * Time complexity: O(10^4) (all possible codes, each processed once at most).
 * Space complexity: O(10^4) for visited/deadends/queue.
 */

class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    // Use unordered_set for O(1) lookup of deadends and visited states
    unordered_set<string> dead(deadends.begin(), deadends.end());
    unordered_set<string> visited;

    string start = "0000"; // The initial state

    // Edge case: If the start is a deadend, cannot start
    if (dead.count(start))
      return -1;
    // Edge case: If the target is the start, 0 moves needed
    if (start == target)
      return 0;

    // Set up BFS queue: each element is a state string and move count
    queue<std::pair<string, int>> q;
    q.push({start, 0});
    visited.insert(start);

    // Helper lambda to generate all next states from a given code
    auto get_neighbors = [](const string &code) -> vector<string> {
      vector<string> neighbors;
      // For each of the 4 wheels
      for (int i = 0; i < 4; ++i) {
        // For each direction: +1 and -1 (with wrap-around)
        for (int d = -1; d <= 1; d += 2) {
          string next = code;
          // Convert current digit to int, apply change, wrap-around using
          // modulo
          int digit = (code[i] - '0' + d + 10) % 10;
          next[i] = digit + '0';
          neighbors.push_back(next); // Add this new state
        }
      }
      return neighbors;
    };

    // Begin BFS loop
    while (!q.empty()) {
      // Pop the next state and moves so far
      auto [state, moves] = q.front();
      q.pop();

      // Try all possible next moves from this state
      vector<string> next_states = get_neighbors(state);
      for (const string &next_code : next_states) {
        // If next state is a deadend or already visited, skip
        if (dead.count(next_code) || visited.count(next_code))
          continue;
        // If reached target, return moves+1
        if (next_code == target)
          return moves + 1;
        // Mark as visited and enqueue for next level processing
        visited.insert(next_code);
        q.push({next_code, moves + 1});
      }
    }

    // If queue is empty and target not reached, impossible
    return -1;
  }
};
// @lc code=end
