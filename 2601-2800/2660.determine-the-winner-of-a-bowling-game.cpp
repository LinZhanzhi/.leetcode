/*
 * @lc app=leetcode id=2660 lang=cpp
 *
 * [2660] Determine the Winner of a Bowling Game
 */

// @lc code=start
class Solution {
public:
  int isWinner(vector<int> &player1, vector<int> &player2) {
    auto calcScore = [](const vector<int> &player) {
      int n = player.size();
      int score = 0;
      for (int i = 0; i < n; ++i) {
        bool doubleScore = false;
        if (i - 1 >= 0 && player[i - 1] == 10)
          doubleScore = true;
        if (i - 2 >= 0 && player[i - 2] == 10)
          doubleScore = true;
        if (doubleScore)
          score += 2 * player[i];
        else
          score += player[i];
      }
      return score;
    };
    int score1 = calcScore(player1);
    int score2 = calcScore(player2);
    if (score1 > score2)
      return 1;
    if (score2 > score1)
      return 2;
    return 0;
  }
};
// @lc code=end
