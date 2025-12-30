/*
 * @lc app=leetcode id=3492 lang=cpp
 *
 * [3492] Maximum Containers on a Ship
 */

// @lc code=start
class Solution {
public:
  int maxContainers(int n, int w, int maxWeight) {
    // The maximum number of containers is the minimum of:
    // - total cells on the deck (n * n)
    // - the maximum number of containers that can be loaded without exceeding
    // maxWeight (maxWeight / w)
    return std::min(n * n, maxWeight / w);
  }
};
// @lc code=end
