/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    unordered_map<int, int> count;
    int res = 0;
    for (int num : nums) {
      res += count[num];
      count[num]++;
    }
    return res;
  }
};
// @lc code=end
