/*
 * @lc app=leetcode id=3536 lang=cpp
 *
 * [3536] Maximum Product of Two Digits
 */

// @lc code=start
class Solution {
public:
  int maxProduct(int n) {
    vector<int> digits;
    int temp = n;
    while (temp > 0) {
      digits.push_back(temp % 10);
      temp /= 10;
    }
    int maxProd = 0;
    int sz = digits.size();
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        int prod = digits[i] * digits[j];
        if (prod > maxProd)
          maxProd = prod;
      }
    }
    return maxProd;
  }
};
// @lc code=end
