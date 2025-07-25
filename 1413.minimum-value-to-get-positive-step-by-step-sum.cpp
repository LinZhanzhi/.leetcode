/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
public:
  int minStartValue(vector<int> &nums) {
    int min_sum = 0, curr_sum = 0;
    for (int num : nums) {
      curr_sum += num;
      min_sum = std::min(min_sum, curr_sum);
    }
    return 1 - min_sum;
  }
};
// @lc code=end
