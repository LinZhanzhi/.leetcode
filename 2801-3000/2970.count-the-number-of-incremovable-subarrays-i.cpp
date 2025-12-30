/*
 * @lc app=leetcode id=2970 lang=cpp
 *
 * [2970] Count the Number of Incremovable Subarrays I
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  // Check if the array is strictly increasing after removing nums[l..r]
  bool isStrictlyIncreasingAfterRemove(const vector<int> &nums, int l, int r) {
    // check if nums[0, l-1] is strictly increasing
    for (int i = 1; i < l; ++i) {
      if (nums[i] <= nums[i - 1])
        return false;
    }
    // check if nums[r+1, n-1] is strictly increasing
    for (int i = r + 2; i < nums.size(); ++i) {
      if (nums[i] <= nums[i - 1])
        return false;
    }
    // check if nums[l-1] is strictly smaller than nums[r+1]
    if (l > 0 && r < nums.size() - 1 && nums[l - 1] >= nums[r + 1])
      return false;
    return true;
  }

  int incremovableSubarrayCount(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (int l = 0; l < n; ++l) {
      for (int r = l; r < n; ++r) {
        if (isStrictlyIncreasingAfterRemove(nums, l, r))
          ++ans;
      }
    }
    return ans;
  }
};
// @lc code=end
