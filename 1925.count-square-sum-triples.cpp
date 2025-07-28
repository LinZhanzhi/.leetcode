/*
 * @lc app=leetcode id=1925 lang=cpp
 *
 * [1925] Count Square Sum Triples
 */

// @lc code=start
class Solution {
public:
  int countTriples(int n) {
    int count = 0;
    for (int a = 1; a <= n; ++a) {
      for (int b = 1; b <= n; ++b) {
        int c2 = a * a + b * b;
        int c = (int)sqrt(c2);
        if (c <= n && c * c == c2) {
          count++;
        }
      }
    }
    return count;
  }
};
// @lc code=end
