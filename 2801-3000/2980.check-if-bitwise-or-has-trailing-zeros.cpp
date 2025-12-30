/*
 * @lc app=leetcode id=2980 lang=cpp
 *
 * [2980] Check if Bitwise OR Has Trailing Zeros
 */

// @lc code=start
class Solution {
public:
  bool hasTrailingZeros(vector<int> &nums) {
    // To have at least one trailing zero in the OR, the result must be even
    // (i.e., last bit is 0). That means, among any two or more selected
    // numbers, at least one must be even. If there are at least two even
    // numbers, their OR is even (trailing zero). If there is at least one even
    // and at least one odd, their OR is also even. So, if there are at least
    // two even numbers, or at least one even and one odd, return true. But if
    // all numbers are odd, it's impossible.

    int evenCount = 0;
    for (int n : nums) {
      if ((n & 1) == 0)
        evenCount++;
    }
    return evenCount >= 2;
  }
};
// @lc code=end
