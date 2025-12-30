/*
 * @lc app=leetcode id=2748 lang=cpp
 *
 * [2748] Number of Beautiful Pairs
 */

// @lc code=start
class Solution {
public:
  int countBeautifulPairs(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    // Helper lambda to get first digit
    auto first_digit = [](int x) {
      while (x >= 10)
        x /= 10;
      return x;
    };
    // Helper lambda to get last digit
    auto last_digit = [](int x) { return x % 10; };
    // Helper lambda for gcd
    auto gcd = [](int a, int b) {
      while (b) {
        int t = b;
        b = a % b;
        a = t;
      }
      return a;
    };
    for (int i = 0; i < n; ++i) {
      int fd = first_digit(nums[i]);
      for (int j = i + 1; j < n; ++j) {
        int ld = last_digit(nums[j]);
        if (gcd(fd, ld) == 1) {
          ++res;
        }
      }
    }
    return res;
  }
};
// @lc code=end
