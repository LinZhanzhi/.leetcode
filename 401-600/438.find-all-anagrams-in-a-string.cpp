/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given two strings, s and p. Our goal is to find all starting indices
 * in s where a substring of length equal to p is an anagram of p. An anagram
 * means the substring contains the same characters as p, just possibly in a
 * different order. We need to efficiently check every substring of s of length
 * p for this property and return all valid starting indices.
 *
 * High-Level Summary:
 * ----
 * The solution uses a sliding window approach with character frequency
 * counting. We maintain two frequency arrays (or hash maps): one for the target
 * string p, and one for the current window in s. As we slide the window over s,
 * we update the window's frequency counts and compare them to p's counts. If
 * they match, the current window is an anagram, and we record its starting
 * index. This approach is efficient, running in O(N) time where N is the length
 * of s, since each character is processed a constant number of times. Space
 * complexity is O(1) because the frequency arrays are fixed size (26 for
 * lowercase letters).
 */

#include <string> // Include string for input types
#include <vector> // Include vector for returning the list of indices

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    // Result vector to store starting indices of anagrams
    vector<int> result;

    // Edge case: if p is longer than s, no anagrams are possible
    if (p.size() > s.size())
      return result;

    // Frequency arrays for 'a' to 'z' (26 lowercase English letters)
    int pCount[26] = {0}; // Frequency of each character in p
    int sCount[26] = {0}; // Frequency of each character in current window of s

    // Build the frequency array for p and the first window of s
    for (int i = 0; i < p.size(); ++i) {
      pCount[p[i] - 'a']++; // Count character in p
      sCount[s[i] - 'a']++; // Count character in the first window of s
    }

    // If the first window is an anagram, record index 0
    if (memcmp(pCount, sCount, sizeof(pCount)) == 0) {
      result.push_back(0);
    }

    // Slide the window over s, one character at a time
    for (int i = p.size(); i < s.size(); ++i) {
      // Add the new character to the window
      sCount[s[i] - 'a']++;
      // Remove the character that is no longer in the window
      sCount[s[i - p.size()] - 'a']--;

      // Compare the frequency arrays; if equal, it's an anagram
      if (memcmp(pCount, sCount, sizeof(pCount)) == 0) {
        // The starting index of the current window is (i - p.size() + 1)
        result.push_back(i - p.size() + 1);
      }
    }

    // Return all starting indices where anagrams of p begin in s
    return result;
  }
};
// @lc code=end
