/*
 * @lc app=leetcode id=1893 lang=cpp
 *
 * [1893] Check if All the Integers in a Range Are Covered
 */

// @lc code=start
class Solution {
public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    // INSERT_YOUR_CODE
    // Since the range is small (1..50), we can use a simple array to mark
    // covered numbers.
    bool covered[51] = {false};
    for (const auto &range : ranges) {
      int start = range[0], end = range[1];
      for (int i = start; i <= end; ++i) {
        covered[i] = true;
      }
    }
    for (int i = left; i <= right; ++i) {
      if (!covered[i])
        return false;
    }
    return true;
  }
};
// @lc code=end
