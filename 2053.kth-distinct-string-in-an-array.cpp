/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
class Solution {
public:
  string kthDistinct(vector<string> &arr, int k) {
    unordered_map<string, int> freq;
    for (const string &s : arr) {
      freq[s]++;
    }
    int count = 0;
    for (const string &s : arr) {
      if (freq[s] == 1) {
        count++;
        if (count == k)
          return s;
      }
    }
    return "";
  }
};
// @lc code=end
