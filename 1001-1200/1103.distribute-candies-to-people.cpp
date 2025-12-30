/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> res(num_people, 0);
    int give = 1, i = 0;
    while (candies > 0) {
      int idx = i % num_people;
      int to_give = min(give, candies);
      res[idx] += to_give;
      candies -= to_give;
      give++;
      i++;
    }
    return res;
  }
};
// @lc code=end
