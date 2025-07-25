/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
class Solution {
public:
  bool isPathCrossing(string path) {
    set<pair<int, int>> visited;
    int x = 0, y = 0;
    visited.insert({x, y});
    for (char dir : path) {
      if (dir == 'N')
        y++;
      else if (dir == 'S')
        y--;
      else if (dir == 'E')
        x++;
      else if (dir == 'W')
        x--;
      if (visited.count({x, y}))
        return true;
      visited.insert({x, y});
    }
    return false;
  }
};
// @lc code=end
