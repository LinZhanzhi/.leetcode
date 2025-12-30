/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */

// @lc code=start

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * In this problem, you are asked to decide if you can build a pyramid of blocks
 * from a given base ("bottom") upwards, where each block on a higher row is
 * formed from specific allowed triplets (patterns). Each pattern is a
 * three-letter string: its first two letters describe two adjacent blocks
 * below, and the third letter is the possible block that can sit above them.
 * You have a set of allowed patterns, and you must figure out if it is possible
 * to go from the given bottom row to the top of the pyramid (where there is
 * only one block) by stacking in accordance with the patterns.
 *
 * High-Level Summary:
 * ----
 * We'll solve the problem using a recursive depth-first search (DFS) with
 * memoization.
 *
 * 1. First, we preprocess the allowed list to map each (left, right) pair
 *    to all possible top blocks (forming a map: pair -> set of possible next
 * blocks).
 *
 * 2. The main idea is: starting from the given bottom row, we want to
 * recursively try to build the next row (one block shorter), trying all valid
 * possibilities for each adjacent pair.
 *
 * 3. At each recursion, for the current row, generate all possible upper rows
 *    by considering all combinations for every adjacent block pair using the
 * allowed mapping.
 *
 * 4. We use memoization to cache subproblem results for a specific row,
 *    so we do not recompute the same configuration again (crucial for
 * pruning!).
 *
 * Time Complexity: O(6^N * N), where N is the length of bottom,
 *   as the branching factor is potentially large with all arrangements.
 * Space Complexity: O(6^N) for memoization and recursion stack.
 */

// Helper typedef for readability: mapping from a pair to allowed block chars.
typedef unordered_map<string, unordered_set<char>> PairToCharsMap;

class Solution {
public:
  bool pyramidTransition(string bottom, vector<string> &allowed) {
    // Preprocess the allowed list to build the mapping from pair to possible
    // top chars
    PairToCharsMap allowedMap = buildAllowedMap(allowed);

    // Memoization map: stores whether a given row can lead to a complete
    // pyramid
    unordered_map<string, bool> memo;

    // Start the recursive search from the bottom row
    return canBuildPyramid(bottom, allowedMap, memo);
  }

private:
  // Helper function to preprocess allowed patterns into a usable mapping
  // structure
  PairToCharsMap buildAllowedMap(const vector<string> &allowed) {
    PairToCharsMap map;
    for (const string &triple : allowed) {
      // The key is the first two chars (pair on the lower level)
      string key = triple.substr(0, 2);
      char val = triple[2];
      // Add the allowed top char to the set for this pair
      map[key].insert(val);
    }
    return map;
  }

  // The core recursive function:
  // Given a current level, determines if a pyramid can be built to the top from
  // here.
  bool canBuildPyramid(const string &current, const PairToCharsMap &allowedMap,
                       unordered_map<string, bool> &memo) {
    // If we've reached the top (just one block), pyramid is complete!
    if (current.length() == 1) {
      return true;
    }
    // If we've already computed the result for this level, return it
    if (memo.count(current))
      return memo[current];

    // Generate all possible next-level candidates
    vector<string> nextRows;
    generateNextRows(current, 0, "", allowedMap, nextRows);

    // Try to build the pyramid from each possible candidate next row
    for (const string &next : nextRows) {
      if (canBuildPyramid(next, allowedMap, memo)) {
        memo[current] = true; // Cache and return
        return true;
      }
    }

    // If no next row leads to the top, cache and return false
    memo[current] = false;
    return false;
  }

  // Helper function: generate all possible next rows (one level above)
  // recursively
  // - idx: current index in the current row
  // - path: constructed so far for the upper row
  // - nextRows: collects all valid next-level strings
  void generateNextRows(const string &current, int idx, string path,
                        const PairToCharsMap &allowedMap,
                        vector<string> &nextRows) {
    // When we've constructed a candidate for the next row of appropriate size
    if (idx == current.length() - 1) {
      nextRows.push_back(path);
      return;
    }
    // Form the pair from current and look up all possible chars for the next
    // level
    string key = current.substr(idx, 2);
    if (allowedMap.count(key) == 0)
      return; // No allowed top block for this pair, dead end
    for (char c : allowedMap.at(key)) {
      // For each possible next char, continue building the upper row
      generateNextRows(current, idx + 1, path + c, allowedMap, nextRows);
    }
    // If no possible blocks, this branch will not append to nextRows
  }
};
// @lc code=end
