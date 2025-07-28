/*
 * @lc app=leetcode id=1848 lang=cpp
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
class Solution {
public:
  int getMinDistance(vector<int> &nums, int target, int start) {
    int minDist = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        int dist = abs(i - start);
        if (dist < minDist) {
          minDist = dist;
        }
      }
    }
    return minDist;
  }
};
// @lc code=end
