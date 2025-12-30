/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());
    vector<bool> result;
    for (int i = 0; i < candies.size(); ++i) {
      result.push_back(candies[i] + extraCandies >= maxCandies);
    }
    return result;
  }
};
// @lc code=end
