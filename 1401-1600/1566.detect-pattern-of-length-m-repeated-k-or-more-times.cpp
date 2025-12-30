/*
 * @lc app=leetcode id=1566 lang=cpp
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
 */

// @lc code=start
class Solution {
public:
  bool containsPattern(vector<int> &arr, int m, int k) {
    int n = arr.size();
    // We need at least m*k elements to have k repeats of length m
    for (int i = 0; i <= n - m * k; ++i) {
      bool match = true;
      // Check for k-1 repeats after the first pattern
      for (int j = 0; j < m * (k - 1); ++j) {
        if (arr[i + j] != arr[i + j + m]) {
          match = false;
          break;
        }
      }
      if (match)
        return true;
    }
    return false;
  }
};
// @lc code=end
