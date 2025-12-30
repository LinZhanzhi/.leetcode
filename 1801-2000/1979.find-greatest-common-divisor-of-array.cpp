/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
class Solution {
public:
  int findGCD(vector<int> &nums) {
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    // Helper function to compute GCD
    auto gcd = [](int a, int b) {
      while (b) {
        int t = b;
        b = a % b;
        a = t;
      }
      return a;
    };
    return gcd(mn, mx);
  }
};
// @lc code=end
