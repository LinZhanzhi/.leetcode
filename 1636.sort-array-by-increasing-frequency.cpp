/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int n : nums) {
      freq[n]++;
    }
    sort(nums.begin(), nums.end(), [&](int a, int b) {
      if (freq[a] != freq[b]) {
        return freq[a] < freq[b];
      }
      return a > b;
    });
    return nums;
  }
};
// @lc code=end
