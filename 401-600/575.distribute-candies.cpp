/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution {
public:
  int distributeCandies(vector<int> &candyType) {
    unordered_set<int> types(candyType.begin(), candyType.end());
    int maxCandies = candyType.size() / 2;
    return min((int)types.size(), maxCandies);
  }
};
// @lc code=end
