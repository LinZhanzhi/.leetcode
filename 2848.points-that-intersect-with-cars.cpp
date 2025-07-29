/*
 * @lc app=leetcode id=2848 lang=cpp
 *
 * [2848] Points That Intersect With Cars
 */

// @lc code=start
class Solution {
public:
  int numberOfPoints(vector<vector<int>> &nums) {
    // INSERT_YOUR_CODE
    // Use a set to store all unique points covered by cars
    unordered_set<int> covered;
    for (const auto &car : nums) {
      for (int i = car[0]; i <= car[1]; ++i) {
        covered.insert(i);
      }
    }
    return covered.size();
  }
};
// @lc code=end
