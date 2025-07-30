/*
 * @lc app=leetcode id=3238 lang=cpp
 *
 * [3238] Find the Number of Winning Players
 */

// @lc code=start
class Solution {
public:
  int winningPlayerCount(int n, vector<vector<int>> &pick) {
    // INSERT_YOUR_CODE
    vector<unordered_map<int, int>> player_color_count(n);
    for (const auto &p : pick) {
      int player = p[0], color = p[1];
      player_color_count[player][color]++;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (const auto &[color, cnt] : player_color_count[i]) {
        if (cnt > i) {
          res++;
          break;
        }
      }
    }
    return res;
  }
};
// @lc code=end
