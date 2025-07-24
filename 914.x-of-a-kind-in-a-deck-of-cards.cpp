/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
class Solution {
public:
  bool hasGroupsSizeX(vector<int> &deck) {
    // INSERT_YOUR_CODE
    if (deck.size() < 2)
      return false;
    unordered_map<int, int> count;
    for (int card : deck) {
      count[card]++;
    }
    int g = 0;
    for (auto &p : count) {
      g = gcd(g, p.second);
    }
    return g >= 2;
  }
};
// @lc code=end
