/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.empty())
      return 0;
    unordered_set<int> num_set(nums.begin(), nums.end());
    int longest = 0;
    for (int num : num_set) {
      // Only start counting if num is the start of a sequence
      if (num_set.find(num - 1) == num_set.end()) {
        int current_num = num;
        int current_streak = 1;
        while (num_set.find(current_num + 1) != num_set.end()) {
          current_num += 1;
          current_streak += 1;
        }
        longest = max(longest, current_streak);
      }
    }
    return longest;
  }
};
// @lc code=end
