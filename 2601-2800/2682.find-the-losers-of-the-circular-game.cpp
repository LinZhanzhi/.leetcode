/*
 * @lc app=leetcode id=2682 lang=cpp
 *
 * [2682] Find the Losers of the Circular Game
 */

// @lc code=start
class Solution {
public:
  vector<int> circularGameLosers(int n, int k) {
    vector<bool> visited(n, false);
    int curr = 0; // 0-based index for friend 1
    int step = 1;
    while (!visited[curr]) {
      visited[curr] = true;
      curr = (curr + step * k) % n;
      step++;
    }
    vector<int> losers;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        losers.push_back(i + 1);
      }
    }
    return losers;
  }
};
// @lc code=end
