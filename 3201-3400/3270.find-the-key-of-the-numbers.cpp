/*
 * @lc app=leetcode id=3270 lang=cpp
 *
 * [3270] Find the Key of the Numbers
 */

// @lc code=start
class Solution {
public:
  int generateKey(int num1, int num2, int num3) {
    // Pad numbers to 4 digits with leading zeros
    char s1[5], s2[5], s3[5];
    snprintf(s1, 5, "%04d", num1);
    snprintf(s2, 5, "%04d", num2);
    snprintf(s3, 5, "%04d", num3);

    int key = 0;
    for (int i = 0; i < 4; ++i) {
      int d1 = s1[i] - '0';
      int d2 = s2[i] - '0';
      int d3 = s3[i] - '0';
      int min_d = std::min({d1, d2, d3});
      key = key * 10 + min_d;
    }
    // Remove leading zeros
    int res = key;
    while (res >= 10 && res % 10 == 0) {
      res /= 10;
    }
    // But the above removes trailing zeros, not leading. Instead, just return
    // key as int, which drops leading zeros.
    return key;
  }
};
// @lc code=end
