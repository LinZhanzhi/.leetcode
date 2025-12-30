/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a string s and need to count how many unique non-empty
 * substrings of s are present in the infinite wraparound string
 * "abcdefghijklmnopqrstuvwxyz...". A substring is present in the wraparound
 * string if its characters are consecutive in the alphabet, wrapping from 'z'
 * to 'a' if needed (e.g., "zab" is valid). The challenge is to efficiently
 * count all such unique substrings, even for large s.
 *
 * High-Level Summary:
 * ----
 * The key insight is that for each ending character (from 'a' to 'z'), we only
 * need to track the maximum length of a valid consecutive substring ending with
 * that character. This is because all shorter substrings ending at that
 * character are also present. We iterate through s, keeping track of the
 * current length of a valid consecutive substring, and update the maximum for
 * each character. The final answer is the sum of these maxima, which gives the
 * total number of unique substrings.
 *
 * Time Complexity: O(N), where N is the length of s.
 * Space Complexity: O(1), since we only use a fixed-size array of 26 for the
 * alphabet.
 */

#include <algorithm> // For std::max
#include <string>    // For std::string
#include <vector>    // For std::vector

using std::max;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the number of unique substrings in wraparound string
  int findSubstringInWraproundString(string s) {
    // Edge case: if s is empty, return 0 (though per constraints, s is
    // non-empty)
    if (s.empty())
      return 0;

    // maxLen[i] will store the maximum length of a valid substring ending with
    // 'a'+i
    vector<int> maxLen(26, 0);

    // curLen tracks the current length of a valid consecutive substring
    int curLen = 0;

    // Iterate through the string s
    for (int i = 0; i < s.size(); ++i) {
      // If current character continues a consecutive sequence from previous
      // character
      if (i > 0 && isConsecutive(s[i - 1], s[i])) {
        // Increase the length of the current valid substring
        ++curLen;
      } else {
        // Otherwise, start a new valid substring of length 1
        curLen = 1;
      }
      // Update the maximum length for the ending character s[i]
      int idx = s[i] - 'a';
      maxLen[idx] = max(maxLen[idx], curLen);
    }

    // The answer is the sum of all maximum lengths for each character
    int totalUnique = 0;
    for (int len : maxLen) {
      totalUnique += len;
    }
    return totalUnique;
  }

private:
  // Helper function to check if two characters are consecutive in wraparound
  // order
  bool isConsecutive(char prev, char curr) {
    // Returns true if curr follows prev in the alphabet, wrapping from 'z' to
    // 'a' For example, 'a' after 'z' is valid, as is 'b' after 'a'
    return (curr - prev == 1) || (prev == 'z' && curr == 'a');
  }
};
// @lc code=end
