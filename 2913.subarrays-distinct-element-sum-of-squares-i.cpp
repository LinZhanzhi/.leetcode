/*
 * @lc app=leetcode id=2913 lang=cpp
 *
 * [2913] Subarrays Distinct Element Sum of Squares I
 */

// @lc code=start
class Solution {
public:
  int sumCounts(vector<int> &nums) {
    // INSERT_YOUR_CODE
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      std::unordered_set<int> s;
      for (int j = i; j < n; ++j) {
        s.insert(nums[j]);
        int cnt = s.size();
        res += cnt * cnt;
      }
    }
    return res;
  }
};
// @lc code=end
