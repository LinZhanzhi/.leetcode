/*
 * @lc app=leetcode id=2784 lang=cpp
 *
 * [2784] Check if Array is Good
 */

// @lc code=start
class Solution {
public:
  bool isGood(vector<int> &nums) {
    int n = *max_element(nums.begin(), nums.end());
    if (nums.size() != n + 1)
      return false;
    vector<int> count(n + 1, 0);
    for (int num : nums) {
      if (num < 1 || num > n)
        return false;
      count[num]++;
    }
    for (int i = 1; i < n; ++i) {
      if (count[i] != 1)
        return false;
    }
    if (count[n] != 2)
      return false;
    return true;
  }
};
// @lc code=end
