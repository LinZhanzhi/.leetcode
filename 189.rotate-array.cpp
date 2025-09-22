/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0)
      return;
    k = k % n;
    if (k == 0)
      return;
    // Reverse the whole array
    reverse(nums.begin(), nums.end());
    // Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);
    // Reverse the rest
    reverse(nums.begin() + k, nums.end());
  }
};
// @lc code=end
