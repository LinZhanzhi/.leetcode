/*
 * @lc app=leetcode id=2303 lang=cpp
 *
 * [2303] Calculate Amount Paid in Taxes
 */

// @lc code=start
class Solution {
public:
  double calculateTax(vector<vector<int>> &brackets, int income) {
    double tax = 0.0;
    int prev = 0;
    for (const auto &bracket : brackets) {
      int upper = bracket[0];
      int percent = bracket[1];
      int taxable = min(income, upper) - prev;
      if (taxable > 0) {
        tax += taxable * (percent / 100.0);
      }
      prev = upper;
      if (income <= upper)
        break;
    }
    return tax;
  }
};
// @lc code=end
