/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
class Solution {
public:
  string largestGoodInteger(string num) {
    string res = "";
    for (int i = 0; i <= num.size() - 3; ++i) {
      if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
        string curr = num.substr(i, 3);
        if (curr > res)
          res = curr;
      }
    }
    return res;
  }
};
// @lc code=end
