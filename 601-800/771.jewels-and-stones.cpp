/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    // INSERT_YOUR_CODE
    unordered_set<char> jewelSet(jewels.begin(), jewels.end());
    int count = 0;
    for (char c : stones) {
      if (jewelSet.count(c)) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
