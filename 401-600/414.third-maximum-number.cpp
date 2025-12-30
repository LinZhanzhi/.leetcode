/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
public:
  int thirdMax(vector<int> &nums) {
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
    for (int num : nums) {
      if (num == first || num == second || num == third)
        continue;
      if (num > first) {
        third = second;
        second = first;
        first = num;
      } else if (num > second) {
        third = second;
        second = num;
      } else if (num > third) {
        third = num;
      }
    }
    return third == LONG_MIN ? first : third;
  }
};
// @lc code=end
