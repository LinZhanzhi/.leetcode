/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
class Solution {
public:
  int findShortestSubArray(vector<int> &nums) {
    unordered_map<int, int> count, first, last;
    int degree = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int n = nums[i];
      if (count.find(n) == count.end())
        first[n] = i;
      last[n] = i;
      count[n]++;
      degree = max(degree, count[n]);
    }
    int minLen = nums.size();
    for (auto &kv : count) {
      if (kv.second == degree) {
        minLen = min(minLen, last[kv.first] - first[kv.first] + 1);
      }
    }
    return minLen;
  }
};
// @lc code=end
