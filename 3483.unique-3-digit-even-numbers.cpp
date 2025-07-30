/*
 * @lc app=leetcode id=3483 lang=cpp
 *
 * [3483] Unique 3-Digit Even Numbers
 */

// @lc code=start
class Solution {
public:
  int totalNumbers(vector<int> &digits) {
    // INSERT_YOUR_CODE
    int n = digits.size();
    set<int> uniqueNumbers;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == i)
          continue;
        for (int k = 0; k < n; ++k) {
          if (k == i || k == j)
            continue;
          int d1 = digits[i], d2 = digits[j], d3 = digits[k];
          if (d1 == 0)
            continue; // no leading zero
          if (d3 % 2 != 0)
            continue; // must be even
          int num = d1 * 100 + d2 * 10 + d3;
          uniqueNumbers.insert(num);
        }
      }
    }
    return uniqueNumbers.size();
  }
};
// @lc code=end
