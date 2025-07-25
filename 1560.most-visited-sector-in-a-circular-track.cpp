/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

// @lc code=start
class Solution {
public:
  vector<int> mostVisited(int n, vector<int> &rounds) {
    // Instead of using a count array for all sectors, we can deduce that
    // the most visited sectors are those between rounds[0] and rounds.back()
    // (inclusive), when traversing in ascending order, wrapping around.
    vector<int> res;
    int start = rounds[0], end = rounds.back();
    if (start <= end) {
      for (int i = start; i <= end; ++i)
        res.push_back(i);
    } else {
      for (int i = 1; i <= end; ++i)
        res.push_back(i);
      for (int i = start; i <= n; ++i)
        res.push_back(i);
    }
    return res;
  }
};
// @lc code=end
