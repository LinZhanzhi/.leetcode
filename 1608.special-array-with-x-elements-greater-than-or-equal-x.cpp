/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution {
public:
  int specialArray(vector<int> &nums) {
    // INSERT_YOUR_CODE
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int x = 1; x <= n; ++x) {
      // Number of elements >= x is n - (lower_bound(nums.begin(), nums.end(),
      // x) - nums.begin())
      int cnt = n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
      if (cnt == x)
        return x;
    }
    return -1;
  }
};
// @lc code=end
