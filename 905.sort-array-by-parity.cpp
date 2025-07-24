/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      // find the first odd number from the left
      while (left < right && nums[left] % 2 == 0)
        ++left;
      // find the first even number from the right
      while (left < right && nums[right] % 2 != 0)
        --right;
      // swap the two numbers
      if (left < right) {
        std::swap(nums[left], nums[right]);
        ++left;
        --right;
      }
    }
    return nums;
  }
};
// @lc code=end
