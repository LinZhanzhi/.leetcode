/*
 * @lc app=leetcode id=2108 lang=cpp
 *
 * [2108] Find First Palindromic String in the Array
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  // Helper function to check if a string is a palindrome
  bool isPalindrome(const string &word) {
    int left = 0, right = word.size() - 1;
    while (left < right) {
      if (word[left] != word[right]) {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }

  string firstPalindrome(vector<string> &words) {
    for (const string &word : words) {
      if (isPalindrome(word))
        return word;
    }
    return "";
  }
};
// @lc code=end
