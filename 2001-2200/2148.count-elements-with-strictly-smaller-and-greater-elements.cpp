/*
 * @lc app=leetcode id=2148 lang=cpp
 *
 * [2148] Count Elements With Strictly Smaller and Greater Elements
 */

// @lc code=start
class Solution {
public:
  int countElements(vector<int> &nums) {
    if (nums.size() < 3)
      return 0;
    int mn = nums[0], mx = nums[0];
    for (int n : nums) {
      if (n < mn)
        mn = n;
      if (n > mx)
        mx = n;
    }
    int count = 0;
    for (int n : nums) {
      if (n > mn && n < mx)
        ++count;
    }
    return count;
  }
};
// @lc code=end
