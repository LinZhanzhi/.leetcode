/*
 * @lc app=leetcode id=3206 lang=cpp
 *
 * [3206] Alternating Groups I
 */

// @lc code=start
class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &colors) {
    // INSERT_YOUR_CODE
    int n = colors.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
      int a = colors[i];
      int b = colors[(i + 1) % n];
      int c = colors[(i + 2) % n];
      if (a != b && b != c && a == c) {
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
