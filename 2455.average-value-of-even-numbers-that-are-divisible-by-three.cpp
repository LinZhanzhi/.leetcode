/*
 * @lc app=leetcode id=2455 lang=cpp
 *
 * [2455] Average Value of Even Numbers That Are Divisible by Three
 */

// @lc code=start
class Solution {
public:
  int averageValue(vector<int> &nums) {
    int sum = 0, count = 0;
    for (int num : nums) {
      if (num % 2 == 0 && num % 3 == 0) {
        sum += num;
        count++;
      }
    }
    return count == 0 ? 0 : sum / count;
  }
};
// @lc code=end
