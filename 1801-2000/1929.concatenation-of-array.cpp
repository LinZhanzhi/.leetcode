/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
public:
  vector<int> getConcatenation(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(2 * n);
    for (int i = 0; i < n; ++i) {
      ans[i] = nums[i];
      ans[i + n] = nums[i];
    }
    return ans;
  }
};
// @lc code=end
