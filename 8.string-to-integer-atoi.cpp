/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
  int myAtoi(string s) {
    int i = 0, n = s.size();
    // 1. Skip leading whitespace
    while (i < n && s[i] == ' ')
      ++i;

    // 2. Check for sign
    int sign = 1;
    if (i < n && (s[i] == '-' || s[i] == '+')) {
      if (s[i] == '-')
        sign = -1;
      ++i;
    }

    // 3. Read digits
    long long num = 0;
    bool digit_found = false;
    while (i < n && s[i] == '0') { // skip leading zeros
      digit_found = true;
      ++i;
    }
    while (i < n && isdigit(s[i])) {
      digit_found = true;
      num = num * 10 + (s[i] - '0');
      // Check for overflow
      if (sign == 1 && num > INT_MAX) {
        num = INT_MAX;
        break;
      }
      if (sign == -1 && -num < INT_MIN) {
        num = (long long)INT_MAX + 1; // -2147483648
        break;
      }
      ++i;
    }
    if (!digit_found)
      return 0;

    num *= sign;
    if (num > INT_MAX)
      return INT_MAX;
    if (num < INT_MIN)
      return INT_MIN;
    return (int)num;
  }
};
// @lc code=end
