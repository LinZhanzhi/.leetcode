/*
 * @lc app=leetcode id=2562 lang=cpp
 *
 * [2562] Find the Array Concatenation Value
 */

// @lc code=start
class Solution {
public:
  long long findTheArrayConcVal(vector<int> &nums) {
    long long ans = 0;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int first = nums[l], last = nums[r];
      int temp = last;
      int mul = 1;
      while (temp > 0) {
        mul *= 10;
        temp /= 10;
      }
      ans += (long long)first * mul + last;
      l++;
      r--;
    }
    if (l == r) {
      ans += nums[l];
    }
    return ans;
  }
};
// @lc code=end
