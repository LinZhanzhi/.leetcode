/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
class Solution {
public:
  int minCostToMoveChips(vector<int> &position) {
    int even = 0, odd = 0;
    for (int pos : position) {
      if (pos % 2 == 0)
        even++;
      else
        odd++;
    }
    return min(even, odd);
  }
};
// @lc code=end
