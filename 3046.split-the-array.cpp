/*
 * @lc app=leetcode id=3046 lang=cpp
 *
 * [3046] Split the Array
 */

// @lc code=start
class Solution {
public:
  bool isPossibleToSplit(vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
      if (freq[num] > 2)
        return false;
    }
    return true;
  }
};
// @lc code=end
