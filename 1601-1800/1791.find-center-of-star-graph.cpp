/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    // The center of the star graph must appear in both of the first two edges.
    // So, the common node between edges[0] and edges[1] is the center.
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
      return edges[0][0];
    } else {
      return edges[0][1];
    }
  }
};
// @lc code=end
