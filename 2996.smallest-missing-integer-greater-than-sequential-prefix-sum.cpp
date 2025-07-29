/*
 * @lc app=leetcode id=2996 lang=cpp
 *
 * [2996] Smallest Missing Integer Greater Than Sequential Prefix Sum
 */

// @lc code=start
class Solution {
public:
  int missingInteger(vector<int> &nums) {
    // Find the longest sequential prefix
    int n = nums.size();
    int prefix_sum = nums[0];
    int i = 1;
    while (i < n && nums[i] == nums[i - 1] + 1) {
      prefix_sum += nums[i];
      ++i;
    }
    // Store all numbers in a set for O(1) lookup
    unordered_set<int> s(nums.begin(), nums.end());
    // Find the smallest missing integer >= prefix_sum
    int x = prefix_sum;
    while (s.count(x))
      ++x;
    return x;
  }
};
// @lc code=end
