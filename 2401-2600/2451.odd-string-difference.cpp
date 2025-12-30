/*
 * @lc app=leetcode id=2451 lang=cpp
 *
 * [2451] Odd String Difference
 */

// @lc code=start
class Solution {
public:
  string oddString(vector<string> &words) {
    int m = words.size(), n = words[0].size();
    vector<vector<int>> diffs(m, vector<int>(n - 1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n - 1; ++j) {
        diffs[i][j] = words[i][j + 1] - words[i][j];
      }
    }
    // Find the odd one out
    // Compare first three to determine the common pattern
    int oddIdx = 0;
    if (diffs[0] == diffs[1]) {
      // 0 and 1 are same, so find the one that differs
      for (int i = 2; i < m; ++i) {
        if (diffs[i] != diffs[0]) {
          oddIdx = i;
          break;
        }
      }
    } else if (diffs[0] == diffs[2]) {
      // 0 and 2 are same, so 1 is odd
      oddIdx = 1;
    } else {
      // 1 and 2 are same, so 0 is odd
      oddIdx = 0;
    }
    return words[oddIdx];
  }
};
// @lc code=end
