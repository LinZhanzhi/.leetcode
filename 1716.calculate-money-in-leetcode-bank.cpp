/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution {
public:
  int totalMoney(int n) {
    int weeks = n / 7; // number of complete weeks, also number of Mondays
    int days = n % 7;  // number of days in the last week
    int total = 0;
    for (int i = 1; i <= weeks; ++i) {
      // in i-th week, Monday gives $i, Tuesday gives $i+1, ..., Sunday gives
      // $i+6 summing them is 7 * (i) + 21 for this whole week
      total += 7 * (i) + 21;
    }
    // in the last week, Monday gives $weeks+1, Tuesday gives $weeks+2, ...,
    // Sunday gives $weeks+7
    for (int i = 1; i <= days; ++i) {
      total += weeks + i;
    }
    return total;
  }
};
// @lc code=end