/*
 * @lc app=leetcode id=2006 lang=cpp
 *
 * [2006] Count Number of Pairs With Absolute Difference K
 */

// @lc code=start
class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    int count = 0;
    for (int num : nums) {
      // For each num, check if num - k and num + k have appeared before
      count += freq[num - k];
      count += freq[num + k];
      freq[num]++;
    }
    return count;
  }
};
// @lc code=end
