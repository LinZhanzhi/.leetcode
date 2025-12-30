/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int findLHS(vector<int> &nums) {
    if (nums.empty())
      return 0;
    sort(nums.begin(), nums.end());
    int res = 0, start = 0;
    for (int end = 0; end < nums.size(); ++end) {
      while (nums[end] - nums[start] > 1) {
        ++start;
      }
      if (nums[end] - nums[start] == 1) {
        res = max(res, end - start + 1);
      }
    }
    return res;
  }
};
// @lc code=end
