/*
 * @lc app=leetcode id=2367 lang=cpp
 *
 * [2367] Number of Arithmetic Triplets
 */

// @lc code=start
class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    int count = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for (int x : nums) {
      if (s.count(x + diff) && s.count(x + 2 * diff)) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
