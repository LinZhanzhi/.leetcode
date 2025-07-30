/*
 * @lc app=leetcode id=3304 lang=cpp
 *
 * [3304] Find the K-th Character in String Game I
 */

// @lc code=start
class Solution {
public:
  char kthCharacter(int k) {
    // INSERT_YOUR_CODE
    // The process is: word = word + next(word)
    // We need to find the k-th character after enough operations.
    // Instead of building the whole string, we can work backwards.

    // Find the length of the string after enough operations
    int len = 1;
    while (len < k) {
      len *= 2;
    }

    // The first character is always 'a'
    int shift = 0;
    while (len > 1) {
      if (k > len / 2) {
        // In the appended part, so move to the corresponding position in the
        // first half
        k -= len / 2;
        shift += 1;
      }
      len /= 2;
    }
    // The character is 'a' + shift, wrap around if needed
    char res = 'a' + (shift % 26);
    return res;
  }
};
// @lc code=end
