/*
 * @lc app=leetcode id=2574 lang=cpp
 *
 * [2574] Left and Right Sum Differences
 */

// @lc code=start
class Solution {
public:
  vector<int> leftRightDifference(vector<int> &nums) {
    int n = nums.size();
    vector<int> leftSum(n, 0), rightSum(n, 0), answer(n, 0);

    // Compute leftSum
    for (int i = 1; i < n; ++i) {
      leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }

    // Compute rightSum
    for (int i = n - 2; i >= 0; --i) {
      rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }

    // Compute answer
    for (int i = 0; i < n; ++i) {
      answer[i] = abs(leftSum[i] - rightSum[i]);
    }

    return answer;
  }
};
// @lc code=end
