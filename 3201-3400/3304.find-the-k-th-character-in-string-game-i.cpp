/*
 * @lc app=leetcode id=3304 lang=cpp
 *
 * [3304] Find the K-th Character in String Game I
 */

// @lc code=start
class Solution {
public:
  char kthCharacter(int k) {
    // find how many times we need to append the word to get the length of the
    // string greater than or equal to k
    int len = 1;
    while (len < k) {
      len *= 2;
    }
    int shift = 0;
    while (len > 1) {
      if (k > len / 2) {
        k -= len / 2;
        shift += 1;
      }
      len /= 2;
    }
    return 'a' + (shift % 26);
  }
};
// @lc code=end
