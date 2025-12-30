/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
  int removePalindromeSub(string s) {
    // If the string is empty, no operation is needed
    if (s.empty())
      return 0;

    // Check if the string is a palindrome
    int n = s.size();
    int left = 0, right = n - 1;
    bool isPalindrome = true;
    while (left < right) {
      if (s[left] != s[right]) {
        isPalindrome = false;
        break;
      }
      left++;
      right--;
    }

    // If the string is a palindrome, we can remove it in one operation
    if (isPalindrome)
      return 1;

    // Otherwise, since the string only contains 'a' and 'b', we can remove all
    // 'a's in one operation and all 'b's in another So, the answer is 2
    return 2;
  }
};
// @lc code=end
