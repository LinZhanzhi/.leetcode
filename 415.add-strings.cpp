/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
  string addStrings(string num1, string num2) {
    // Pad the shorter string with leading zeros
    int n1 = num1.size(), n2 = num2.size();
    if (n1 < n2) {
      num1 = string(n2 - n1, '0') + num1;
    } else if (n2 < n1) {
      num2 = string(n1 - n2, '0') + num2;
    }
    int n = max(n1, n2);
    int carry = 0;
    string result;
    for (int i = n - 1; i >= 0; --i) {
      int digit1 = num1[i] - '0';
      int digit2 = num2[i] - '0';
      int sum = digit1 + digit2 + carry;
      result.push_back((sum % 10) + '0');
      carry = sum / 10;
    }
    if (carry) {
      result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
