/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
class Solution {
public:
  int findLucky(vector<int> &arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
      freq[num]++;
    }
    int res = -1;
    for (const auto &p : freq) {
      if (p.first == p.second) {
        res = max(res, p.first);
      }
    }
    return res;
  }
};
// @lc code=end
