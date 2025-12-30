/*
 * @lc app=leetcode id=2644 lang=cpp
 *
 * [2644] Find the Maximum Divisibility Score
 */

// @lc code=start
class Solution {
public:
  int maxDivScore(vector<int> &nums, vector<int> &divisors) {
    int maxScore = -1;
    int result = INT_MAX;
    for (int d : divisors) {
      int score = 0;
      for (int n : nums) {
        if (n % d == 0) {
          score++;
        }
      }
      if (score > maxScore || (score == maxScore && d < result)) {
        maxScore = score;
        result = d;
      }
    }
    return result;
  }
};
// @lc code=end
