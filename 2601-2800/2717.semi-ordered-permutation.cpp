/*
 * @lc app=leetcode id=2717 lang=cpp
 *
 * [2717] Semi-Ordered Permutation
 */

// @lc code=start
class Solution {
public:
  int semiOrderedPermutation(vector<int> &nums) {
    int n = nums.size();
    int pos1 = 0, posn = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 1)
        pos1 = i;
      if (nums[i] == n)
        posn = i;
    }
    // If 1 is before n, moving 1 to front and n to back are independent
    // If 1 is after n, moving 1 to front will shift n right by 1, so subtract 1
    if (pos1 < posn) {
      return pos1 + (n - 1 - posn);
    } else {
      return pos1 + (n - 1 - posn) - 1;
    }
  }
};
// @lc code=end
