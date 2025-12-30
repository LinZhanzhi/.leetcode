/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// Brief, Digested Understanding:
//
// The problem asks us to find all unique non-decreasing subsequences of length
// at least two from a given integer array. A non-decreasing subsequence is a
// sequence where each element is not less than the previous one, and the
// elements are taken in order from the original array (but not necessarily
// consecutively). We must avoid duplicate subsequences in the result, even if
// the input contains repeated numbers.
//
// High-Level Summary:
//
// The solution uses backtracking to explore all possible subsequences. At each
// step, we decide whether to include the current number in the subsequence,
// ensuring that the sequence remains non-decreasing. To avoid duplicates
// (especially when the same number appears multiple times at the same recursion
// level), we use a set to track which numbers have already been used at the
// current depth. The main function initializes the process, and a helper
// function performs the recursive backtracking. The time complexity is O(2^n *
// n), since each number can be included or not, and we may need to copy
// subsequences of up to n elements. The space complexity is also O(2^n * n) for
// storing all possible subsequences.
//
// The code is modularized: the main function delegates the backtracking to a
// helper, and the helper uses a set to avoid duplicate subsequences.

#include <set>    // For std::set to avoid duplicates at each recursion level
#include <vector> // For std::vector

using std::set;
using std::vector;

class Solution {
public:
  // Main function to find all unique non-decreasing subsequences of length >= 2
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> result;          // Stores all valid subsequences
    vector<int> current;                 // Current subsequence being built
    backtrack(nums, 0, current, result); // Start backtracking from index 0
    return result;
  }

private:
  // Helper function for backtracking
  // - nums: input array
  // - start: current index in nums to consider
  // - current: current subsequence being built
  // - result: stores all valid subsequences found so far
  void backtrack(const vector<int> &nums, int start, vector<int> &current,
                 vector<vector<int>> &result) {
    // If the current subsequence has at least two elements, add it to the
    // result
    if (current.size() >= 2) {
      result.push_back(current);
    }

    // Use a set to avoid using the same number at this recursion level (to
    // prevent duplicates)
    set<int> used;

    // Iterate through the remaining elements starting from 'start'
    for (int i = start; i < nums.size(); ++i) {
      // If the number has already been used at this level, skip it to avoid
      // duplicate subsequences
      if (used.count(nums[i])) {
        continue;
      }
      // If current is empty or the current number is >= the last number in the
      // subsequence, we can include it
      if (current.empty() || nums[i] >= current.back()) {
        used.insert(nums[i]);       // Mark this number as used at this level
        current.push_back(nums[i]); // Include nums[i] in the subsequence
        backtrack(nums, i + 1, current, result); // Recurse to the next index
        current.pop_back(); // Backtrack: remove the last number and try the
                            // next possibility
      }
      // If nums[i] < current.back(), we skip it to maintain non-decreasing
      // order
    }
  }
};
// @lc code=end
