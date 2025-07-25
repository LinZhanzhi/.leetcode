/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */

#include <algorithm>
#include <vector>

class Solution {
public:
  int getMaximumGenerated(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    std::vector<int> nums(n + 1, 0);
    nums[0] = 0;
    nums[1] = 1;
    int res = 1;
    for (int i = 2; i <= n; ++i) {
      if (i % 2 == 0) {
        nums[i] = nums[i / 2];
      } else {
        nums[i] = nums[i / 2] + nums[i / 2 + 1];
      }
      res = std::max(res, nums[i]);
    }
    return res;
  }
};
