/*
 * @lc app=leetcode id=2248 lang=cpp
 *
 * [2248] Intersection of Multiple Arrays
 */

// @lc code=start
class Solution {
public:
  vector<int> intersection(vector<vector<int>> &nums) {
    vector<int> count(1001, 0);
    int n = nums.size();
    for (const auto &arr : nums) {
      for (int num : arr) {
        count[num]++;
      }
    }
    vector<int> res;
    for (int i = 1; i <= 1000; ++i) {
      if (count[i] == n) {
        res.push_back(i);
      }
    }
    return res;
  }
};
// @lc code=end
