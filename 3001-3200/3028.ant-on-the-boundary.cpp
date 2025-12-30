/*
 * @lc app=leetcode id=3028 lang=cpp
 *
 * [3028] Ant on the Boundary
 */

// @lc code=start
class Solution {
public:
  int returnToBoundaryCount(vector<int> &nums) {
    int pos = 0;
    int count = 0;
    for (int n : nums) {
      pos += n;
      if (pos == 0)
        count++;
    }
    return count;
  }
};
// @lc code=end
