/*
 * @lc app=leetcode id=3024 lang=cpp
 *
 * [3024] Type of Triangle
 */

// @lc code=start
class Solution {
public:
  string triangleType(vector<int> &nums) {
    // Check if the sides can form a triangle
    int a = nums[0], b = nums[1], c = nums[2];
    if (a + b <= c || a + c <= b || b + c <= a) {
      return "none";
    }
    if (a == b && b == c) {
      return "equilateral";
    }
    if (a == b || b == c || a == c) {
      return "isosceles";
    }
    return "scalene";
  }
};
// @lc code=end
