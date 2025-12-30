/*
 * @lc app=leetcode id=3226 lang=cpp
 *
 * [3226] Number of Bit Changes to Make Two Integers Equal
 */

// @lc code=start
class Solution {
public:
  int minChanges(int n, int k) {
    // INSERT_YOUR_CODE
    // We can only turn 1s in n to 0s, so k must have 0s wherever n has 0s.
    // If k has a 1 where n has a 0, it's impossible.
    if ((n | k) != n)
      return -1;
    // Count the number of 1s in n that need to be turned off (i.e., where n has
    // 1 and k has 0)
    int changes = 0;
    int x = n, y = k;
    while (x > 0 || y > 0) {
      int nb = x & 1;
      int kb = y & 1;
      if (nb == 1 && kb == 0)
        changes++;
      x >>= 1;
      y >>= 1;
    }
    return changes;
  }
};
// @lc code=end
