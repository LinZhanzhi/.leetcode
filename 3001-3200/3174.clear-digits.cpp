/*
 * @lc app=leetcode id=3174 lang=cpp
 *
 * [3174] Clear Digits
 */

// @lc code=start
class Solution {
public:
  string clearDigits(string s) {
    vector<char> stk;
    for (char c : s) {
      if (isdigit(c)) {
        if (!stk.empty()) {
          stk.pop_back(); // remove the closest non-digit to the left
        }
        // do not push the digit
      } else {
        stk.push_back(c);
      }
    }
    return string(stk.begin(), stk.end());
  }
};
// @lc code=end
