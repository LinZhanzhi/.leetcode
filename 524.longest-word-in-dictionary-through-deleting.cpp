/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a string `s` and a list of words (`dictionary`). Our goal is to
 * find the longest word in the dictionary that can be formed by deleting some
 * (possibly zero) characters from `s` without reordering the remaining
 * characters. If there are multiple words of the same maximum length, we return
 * the one that comes first in lexicographical (dictionary) order. If no word
 * can be formed, we return an empty string.
 *
 * High-Level Summary:
 * ----
 * The solution checks, for each word in the dictionary, whether it is a
 * subsequence of `s` (i.e., can be formed by deleting some characters from
 * `s`). We do this efficiently using a two-pointer technique. We keep track of
 * the best candidate found so far, updating it if we find a longer word or a
 * lexicographically smaller word of the same length. The time complexity is O(N
 * * L), where N is the number of words in the dictionary and L is the average
 * length of the words, since for each word we may scan all of `s`. The space
 * complexity is O(1) extra (not counting the input and output).
 */

#include <algorithm> // For std::sort, std::min
#include <string>    // For std::string
#include <vector>    // For std::vector

using std::string;
using std::vector;

class Solution {
public:
  // Main function to find the longest word in the dictionary that is a
  // subsequence of s
  string findLongestWord(string s, vector<string> &dictionary) {
    string best = ""; // Stores the best candidate found so far

    // Iterate through each word in the dictionary
    for (const string &word : dictionary) {
      // Check if the current word is a subsequence of s
      if (isSubsequence(word, s)) {
        // If the word is longer than the current best, or same length but
        // lexicographically smaller, update best
        if (word.length() > best.length() ||
            (word.length() == best.length() && word < best)) {
          best = word;
        }
      }
    }
    return best; // Return the best candidate found, or empty string if none
  }

private:
  // Helper function to check if 'word' is a subsequence of 's'
  bool isSubsequence(const string &word, const string &s) {
    // Two pointers: i for word, j for s
    int i = 0, j = 0;
    int n = word.length(), m = s.length();

    // Move through both strings
    while (i < n && j < m) {
      if (word[i] == s[j]) {
        // If characters match, move both pointers
        ++i;
      }
      // Always move pointer in s
      ++j;
    }
    // If we've matched all characters in word, it's a subsequence
    return i == n;
  }
};
// @lc code=end
