/*
 * @lc app=leetcode id=3442 lang=cpp
 *
 * [3442] Maximum Difference Between Even and Odd Frequency I
 */

// @lc code=start
class Solution {
public:
  int maxDifference(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
      freq[c - 'a']++;
    }
    int maxOdd = INT_MIN, minEven = INT_MAX;
    // Find all odd and even frequencies
    vector<int> oddFreqs, evenFreqs;
    for (int f : freq) {
      if (f > 0) {
        if (f % 2 == 1)
          oddFreqs.push_back(f);
        else
          evenFreqs.push_back(f);
      }
    }
    int res = INT_MIN;
    for (int odd : oddFreqs) {
      for (int even : evenFreqs) {
        res = max(res, odd - even);
      }
    }
    return res;
  }
};
// @lc code=end
