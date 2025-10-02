/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// Brief, Digested Understanding:
// ----
// The problem asks us to determine if any substring of s2 is a permutation
// (i.e., rearrangement) of s1. In other words, we need to check if s2 contains
// a substring with exactly the same character counts as s1, regardless of
// order. Both strings only contain lowercase English letters, and the substring
// must be contiguous.

// High-Level Summary:
// ----
// The solution uses a sliding window approach with two frequency count arrays
// (one for s1, one for the current window in s2). We slide a window of length
// equal to s1 over s2, updating the window's character counts as we go. If at
// any point the window's character counts match s1's, we return true. This
// approach is efficient, running in O(N) time (where N is the length of s2),
// and uses O(1) space (since the alphabet size is fixed). The code is
// modularized with helper functions for frequency counting and window
// comparison, and includes detailed comments for clarity.

#include <string> // For std::string
#include <vector> // For std::vector
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to check if s2 contains a permutation of s1
  bool checkInclusion(string s1, string s2) {
    // Edge case: if s1 is longer than s2, no permutation is possible
    if (s1.size() > s2.size())
      return false;

    // Helper function to build a frequency count for a string
    auto buildCharCount = [](const string &s) -> vector<int> {
      vector<int> count(26, 0); // 26 for each lowercase letter
      for (char c : s) {
        count[c - 'a']++;
      }
      return count;
    };

    // Helper function to compare two frequency count arrays
    auto isSameCount = [](const vector<int> &a, const vector<int> &b) -> bool {
      for (int i = 0; i < 26; ++i) {
        if (a[i] != b[i])
          return false;
      }
      return true;
    };

    // Build the frequency count for s1
    vector<int> s1Count = buildCharCount(s1);

    // Initialize the frequency count for the first window in s2
    vector<int> windowCount(26, 0);
    for (int i = 0; i < s1.size(); ++i) {
      windowCount[s2[i] - 'a']++;
    }

    // Check if the first window is a permutation
    if (isSameCount(s1Count, windowCount))
      return true;

    // Slide the window over s2, one character at a time
    for (int i = s1.size(); i < s2.size(); ++i) {
      // Add the new character to the window
      windowCount[s2[i] - 'a']++;
      // Remove the character that is no longer in the window
      windowCount[s2[i - s1.size()] - 'a']--;
      // Check if the current window matches s1's character count
      if (isSameCount(s1Count, windowCount))
        return true;
    }

    // If no window matched, return false
    return false;
  }
};
// @lc code=end
