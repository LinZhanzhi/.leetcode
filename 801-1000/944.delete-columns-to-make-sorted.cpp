/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    int m = strs.size();
    int n = strs[0].size();
    int count = 0;
    for (int col = 0; col < n; ++col) {
      for (int row = 1; row < m; ++row) {
        if (strs[row][col] < strs[row - 1][col]) {
          ++count;
          break;
        }
      }
    }
    return count;
  }
};
// @lc code=end
