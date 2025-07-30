/*
 * @lc app=leetcode id=3005 lang=cpp
 *
 * [3005] Count Elements With Maximum Frequency
 */

// @lc code=start
class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    for (int num : nums) {
      freq[num]++;
      if (freq[num] > maxFreq) {
        maxFreq = freq[num];
      }
    }
    int total = 0;
    for (const auto &[num, f] : freq) {
      if (f == maxFreq) {
        total += f;
      }
    }
    return total;
  }
};
// @lc code=end
