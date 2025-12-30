/*
 * @lc app=leetcode id=2341 lang=cpp
 *
 * [2341] Maximum Number of Pairs in Array
 */

// @lc code=start
class Solution {
public:
  vector<int> numberOfPairs(vector<int> &nums) {
    vector<int> freq(101, 0);
    for (int num : nums) {
      freq[num]++;
    }
    int pairs = 0, leftovers = 0;
    for (int count : freq) {
      pairs += count / 2;
      leftovers += count % 2;
    }
    return {pairs, leftovers};
  }
};
// @lc code=end
