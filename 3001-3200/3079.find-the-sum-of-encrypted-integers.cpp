/*
 * @lc app=leetcode id=3079 lang=cpp
 *
 * [3079] Find the Sum of Encrypted Integers
 */

// @lc code=start
class Solution {
public:
  int sumOfEncryptedInt(vector<int> &nums) {
    int total = 0;
    for (int x : nums) {
      int maxDigit = 0, temp = x, len = 0;
      while (temp > 0) {
        maxDigit = std::max(maxDigit, temp % 10);
        temp /= 10;
        len++;
      }
      if (len == 0)
        len = 1; // for x == 0, but per constraints x >= 1
      int encrypted = 0;
      for (int i = 0; i < len; ++i) {
        encrypted = encrypted * 10 + maxDigit;
      }
      total += encrypted;
    }
    return total;
  }
};
// @lc code=end
