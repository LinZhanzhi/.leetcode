/*
 * @lc app=leetcode id=3158 lang=cpp
 *
 * [3158] Find the XOR of Numbers Which Appear Twice
 */

// @lc code=start
class Solution {
public:
  int duplicateNumbersXOR(vector<int> &nums) {
    unordered_map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }
    int res = 0;
    for (auto &[num, cnt] : count) {
      if (cnt == 2)
        res ^= num;
    }
    return res;
  }
};
// @lc code=end
