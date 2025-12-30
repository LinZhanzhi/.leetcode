/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

/*
 * Brief Digested Understanding:
 * ----
 * The core of this problem is to count how many substrings of a given string
 * are palindromes. A palindrome is a sequence that reads the same forwards and
 * backwards. Every single character is a palindrome by itself, but we also need
 * to count longer substrings that are palindromic. The challenge is to do this
 * efficiently, since the string can be up to 1000 characters long, and there
 * are O(n^2) possible substrings.
 *
 * High-Level Summary:
 * ----
 * The most efficient and intuitive approach is to use the "expand around
 * center" technique. For each character (and each gap between characters), we
 * treat it as the center of a possible palindrome and expand outwards as long
 * as the substring remains a palindrome. This way, we count all palindromic
 * substrings in O(n^2) time and O(1) extra space. We modularize the code by
 * writing a helper function to expand around a given center and count
 * palindromes. This approach is efficient enough for the given constraints.
 */

#include <string> // For std::string
using std::string;

// @lc code=start
class Solution {
public:
  // Main function to count all palindromic substrings in the input string
  int countSubstrings(string s) {
    int n = s.size();   // Length of the input string
    int totalCount = 0; // Total number of palindromic substrings

    // Loop through each possible center for palindromes
    // There are 2n-1 centers: n for odd-length, n-1 for even-length
    for (int center = 0; center < 2 * n - 1; ++center) {
      // For odd-length palindromes, left == right
      // For even-length palindromes, right = left + 1
      int left = center / 2;
      int right = left + (center % 2);

      // Expand around the current center and count palindromes
      totalCount += countFromCenter(s, left, right);
    }
    return totalCount;
  }

private:
  // Helper function to expand around a center and count palindromic substrings
  int countFromCenter(const string &s, int left, int right) {
    int count = 0;
    int n = s.size();

    // Expand as long as the substring is a palindrome
    while (left >= 0 && right < n && s[left] == s[right]) {
      // s[left..right] is a palindrome
      ++count;
      --left;  // Move left pointer outward
      ++right; // Move right pointer outward
    }
    return count;
  }
};
// @lc code=end
