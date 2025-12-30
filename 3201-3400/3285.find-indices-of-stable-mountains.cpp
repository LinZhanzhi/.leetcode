/*
 * @lc app=leetcode id=3285 lang=cpp
 *
 * [3285] Find Indices of Stable Mountains
 */

// @lc code=start
class Solution {
public:
  vector<int> stableMountains(vector<int> &height, int threshold) {
    vector<int> res;
    int n = height.size();
    for (int i = 1; i < n; ++i) {
      if (height[i - 1] > threshold) {
        res.push_back(i);
      }
    }
    return res;
  }
};
// @lc code=end
