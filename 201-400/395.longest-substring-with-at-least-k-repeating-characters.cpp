/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the length of the longest substring in a given
 * string `s` where every character in that substring appears at least `k`
 * times. If no such substring exists, we should return 0. The string only
 * contains lowercase English letters.
 *
 * In other words, we want the largest possible substring such that, for every
 * character in it, its count within the substring is at least `k`.
 */

/*
 * High-Level Summary:
 * ----
 * The most efficient approach for this problem is a recursive
 * divide-and-conquer strategy. The idea is:
 *   - For the current substring, count the frequency of each character.
 *   - If every character in the substring appears at least `k` times, the whole
 * substring is valid.
 *   - Otherwise, for any character that appears less than `k` times, it cannot
 * be part of any valid substring. We split the string at those characters and
 * recursively solve for each segment.
 *   - The answer is the maximum length found among all such segments.
 *
 * This approach ensures that we only consider substrings where all characters
 * meet the frequency requirement, and we efficiently skip over impossible
 * regions.
 *
 * Time Complexity: O(N^2), where N is the length of the string, because in the
 * worst case, we may split at every character. Space Complexity: O(N) for the
 * recursion stack and frequency arrays.
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
  // Main function to find the longest substring where every character appears
  // at least k times
  int longestSubstring(string s, int k) {
    // Call the helper function on the entire string
    return longestSubstringHelper(s, 0, s.size(), k);
  }

private:
  // Helper function that works on the substring s[l:r] (inclusive of l,
  // exclusive of r)
  int longestSubstringHelper(const string &s, int l, int r, int k) {
    // If the substring is shorter than k, it can't possibly be valid
    if (r - l < k)
      return 0;

    // Count the frequency of each character in the current substring
    vector<int> freq(26, 0);
    for (int i = l; i < r; ++i) {
      freq[s[i] - 'a']++;
    }

    // For every character in the substring, check if it appears at least k
    // times
    for (int i = l; i < r; ++i) {
      // If this character appears less than k times, it cannot be part of any
      // valid substring
      if (freq[s[i] - 'a'] > 0 && freq[s[i] - 'a'] < k) {
        // Split the string at this character and recursively solve for both
        // sides
        int j = i + 1;
        // Move j forward to skip all consecutive occurrences of this invalid
        // character
        while (j < r && s[j] == s[i])
          ++j;
        // Recursively solve for the left and right segments, and return the
        // maximum
        int left = longestSubstringHelper(s, l, i, k);
        int right = longestSubstringHelper(s, j, r, k);
        return max(left, right);
      }
    }

    // If every character appears at least k times, the whole substring is valid
    return r - l;
  }
};
// @lc code=end
