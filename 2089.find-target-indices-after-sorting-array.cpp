/*
 * @lc app=leetcode id=2089 lang=cpp
 *
 * [2089] Find Target Indices After Sorting Array
 */

// @lc code=start
class Solution {
public:
  vector<int> targetIndices(vector<int> &nums, int target) {
    vector<int> res;
    int count = 0, less = 0;
    for (int n : nums) {
      if (n < target)
        less++;
      if (n == target)
        count++;
    }
    for (int i = 0; i < count; ++i) {
      res.push_back(less + i);
    }
    return res;
  }
};
// @lc code=end
