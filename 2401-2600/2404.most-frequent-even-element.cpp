/*
 * @lc app=leetcode id=2404 lang=cpp
 *
 * [2404] Most Frequent Even Element
 */

// @lc code=start
class Solution {
public:
  int mostFrequentEven(vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
      if (num % 2 == 0) {
        freq[num]++;
      }
    }
    int maxFreq = 0;
    int res = -1;
    for (auto &[num, count] : freq) {
      if (count > maxFreq || (count == maxFreq && num < res)) {
        maxFreq = count;
        res = num;
      }
    }
    return res;
  }
};
// @lc code=end
