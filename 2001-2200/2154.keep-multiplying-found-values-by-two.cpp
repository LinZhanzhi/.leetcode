/*
 * @lc app=leetcode id=2154 lang=cpp
 *
 * [2154] Keep Multiplying Found Values by Two
 */

// @lc code=start
class Solution {
public:
  int findFinalValue(vector<int> &nums, int original) {
    unordered_set<int> s(nums.begin(), nums.end());
    while (s.find(original) != s.end()) {
      original *= 2;
    }
    return original;
  }
};
// @lc code=end
