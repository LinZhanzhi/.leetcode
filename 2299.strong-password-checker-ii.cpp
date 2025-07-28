/*
 * @lc app=leetcode id=2299 lang=cpp
 *
 * [2299] Strong Password Checker II
 */

// @lc code=start
class Solution {
public:
  bool strongPasswordCheckerII(string password) {
    if (password.length() < 8)
      return false;

    bool hasLower = false, hasUpper = false, hasDigit = false,
         hasSpecial = false;
    string special = "!@#$%^&*()-+";

    for (int i = 0; i < password.length(); ++i) {
      char c = password[i];
      if (i > 0 && c == password[i - 1])
        return false;
      if (islower(c))
        hasLower = true;
      else if (isupper(c))
        hasUpper = true;
      else if (isdigit(c))
        hasDigit = true;
      else if (special.find(c) != string::npos)
        hasSpecial = true;
    }

    return hasLower && hasUpper && hasDigit && hasSpecial;
  }
};
// @lc code=end
