/*
 * @lc app=leetcode id=2347 lang=cpp
 *
 * [2347] Best Poker Hand
 */

// @lc code=start
class Solution {
public:
  string bestHand(vector<int> &ranks, vector<char> &suits) {
    // Check for Flush
    if (suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] &&
        suits[3] == suits[4]) {
      return "Flush";
    }
    // Count ranks
    unordered_map<int, int> rankCount;
    for (int r : ranks) {
      rankCount[r]++;
    }
    int maxCount = 0;
    for (auto &p : rankCount) {
      if (p.second > maxCount)
        maxCount = p.second;
    }
    if (maxCount >= 3)
      return "Three of a Kind";
    if (maxCount == 2)
      return "Pair";
    return "High Card";
  }
};
// @lc code=end
