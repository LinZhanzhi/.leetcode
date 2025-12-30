/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
class Solution {
public:
  int smallestRangeI(vector<int> &nums, int k) {
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    int res = mx - mn - 2 * k;
    return res > 0 ? res : 0;
  }
};
// @lc code=end
