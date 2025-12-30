/*
 * @lc app=leetcode id=2908 lang=cpp
 *
 * [2908] Minimum Sum of Mountain Triplets I
 */

#include <algorithm>
#include <climits>
#include <vector>

// @lc code=start
class Solution {
public:
  int minimumSum(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> leftMin(n, INT_MAX), rightMin(n, INT_MAX);

    // Compute leftMin[i]: min value to the left of i (strictly less than
    // nums[i])
    int currMin = INT_MAX;
    for (int i = 0; i < n; ++i) {
      leftMin[i] = currMin;
      currMin = std::min(currMin, nums[i]);
    }

    // Compute rightMin[i]: min value to the right of i (strictly less than
    // nums[i])
    currMin = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
      rightMin[i] = currMin;
      currMin = std::min(currMin, nums[i]);
    }

    int res = INT_MAX;
    for (int j = 1; j < n - 1; ++j) {
      int l = leftMin[j];
      int r = rightMin[j];
      if (l < nums[j] && r < nums[j]) {
        res = std::min(res, l + nums[j] + r);
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};
// @lc code=end
