/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

/*
 * Brief Digested Understanding:
 * ----
 * The heart of this problem is to decide if a sorted array can be split into
 * one or more subsequences, where each subsequence is a sequence of consecutive
 * integers (each number is exactly one more than the previous), and every
 * subsequence must have a length of at least 3. The challenge is to assign each
 * number to a valid subsequence, possibly starting new ones or extending
 * existing ones, such that all subsequences meet the minimum length
 * requirement.
 *
 * High-Level Summary:
 * ----
 * The main idea is to greedily extend existing subsequences whenever possible,
 * and only start a new subsequence if necessary. We use two hash maps:
 *   - `freq`: counts how many times each number appears and how many are left
 *     to assign.
 *   - `need`: tracks how many subsequences are currently "waiting" for a
 *     specific number to extend them.
 * For each number, if it can extend an existing subsequence (i.e., `need[num] >
 * 0`), we do so. Otherwise, we try to start a new subsequence with `num,
 * num+1, num+2` (if those numbers are available). If neither is possible, we
 * return false. This approach ensures all subsequences are at least length 3.
 * Time complexity is O(n), and space complexity is O(n), where n is the length
 * of the input array.
 */

#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  bool isPossible(vector<int> &nums) {
    // freq: counts how many times each number is available to use
    unordered_map<int, int> freq;
    // need: counts how many subsequences are waiting for a number to extend
    // them
    unordered_map<int, int> need;

    // Step 1: Count the frequency of each number in nums
    for (int num : nums) {
      freq[num]++;
    }

    // Step 2: Try to assign each number to a subsequence
    for (int num : nums) {
      // If this number has already been used up, skip it
      if (freq[num] == 0)
        continue;

      // If there is a subsequence ending with num-1 that needs num, extend it
      if (need[num] > 0) {
        // Use num to extend the subsequence
        need[num]--;     // One less subsequence waiting for num
        need[num + 1]++; // Now, a subsequence is waiting for num+1
        freq[num]--;     // Use up one occurrence of num
      }
      // Otherwise, try to start a new subsequence num, num+1, num+2
      else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
        // Use num, num+1, num+2 to form a new subsequence
        freq[num]--;
        freq[num + 1]--;
        freq[num + 2]--;
        // Now, this new subsequence will need num+3 next
        need[num + 3]++;
      }
      // If neither is possible, we cannot split as required
      else {
        return false;
      }
    }
    // If we assigned all numbers successfully, return true
    return true;
  }
};
// @lc code=end
