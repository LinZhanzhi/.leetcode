/*
 * @lc app=leetcode id=3232 lang=cpp
 *
 * [3232] Find if Digit Game Can Be Won
 */

// @lc code=start
class Solution {
public:
  bool canAliceWin(vector<int> &nums) {
    int single_sum = 0, double_sum = 0;
    int total_sum = 0;
    for (int n : nums) {
      total_sum += n;
      if (n < 10)
        single_sum += n;
      else
        double_sum += n;
    }
    // Alice can choose all single-digit or all double-digit numbers
    // and the rest go to Bob
    int bob_sum_single = total_sum - single_sum;
    int bob_sum_double = total_sum - double_sum;
    return (single_sum > bob_sum_single) || (double_sum > bob_sum_double);
  }
};
// @lc code=end
