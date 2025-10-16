/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// Brief Digested Understanding:
// ----
// The core idea of this problem is: you are given a string `s` of lowercase
// letters, and another string `order` that specifies a custom sorting order
// of (possibly some or all) lowercase letters. All characters in `order` are
// unique. Your task is to rearrange (permute) `s` so that characters that occur
// in `order` are sorted in the order that `order` specifies, and letters not
// in `order` can be placed anywhere in the result (their relative position
// doesn't matter). For example, if "cba" is the order, then in the output all
// 'c's should appear before all 'b's, which should appear before all 'a's,
// and the rest of the letters can go anywhere.
//
// At heart, this problem asks you to "apply a custom prioritization" to the
// characters of `s`, using the rulebook given in `order`.
//
// Key constraints: `order` is up to 26 letters (no repeats, all lowercase),
// and `s` is up to 200 letters.

// High-Level Summary:
// ----
// The solution works by first counting the frequency of every letter in `s`.
// We then output all the characters of `s` that appear in `order`, in the
// sequence given by `order`, using their frequency. After placing all the
// letters that are specified by `order`, we append all the remaining letters
// from `s` (those not in `order`), in any order.
//
// The main technique is frequency counting (hash map or array), and iterating
// through `order` for prioritized characters. For speed, we use a fixed array
// of size 26 to count letter frequencies since all letters are lowercase.
//
// - Time Complexity: O(N + M), where N = length of s, M = length of order.
// - Space Complexity: O(1), because the frequency array is constant-sized.
//
// The logic is modularized into helper functions for counting frequencies
// and for building the result based on the custom order.
//
// Includes detailed beginner-friendly comments throughout.

// @lc code=start
#include <string>  // Needed for std::string
#include <vector>  // Needed for std::vector
using std::string; // Bring string into scope for convenience

class Solution {
public:
  // Public interface for the custom sort
  string customSortString(string order, string s) {
    // Count the frequency of each lowercase letter in `s`.
    std::vector<int> freq = countFrequencies(s);

    // Build the sorted string according to the custom order.
    string result;
    appendOrderedCharacters(result, order,
                            freq); // Adds letters in the correct order
    appendRemainingCharacters(result, freq); // Adds leftover letters

    return result;
  }

private:
  // Helper function to count the frequency of each letter in s.
  // Returns a vector of size 26, where freq[i] is number of char('a'+i) in `s`.
  std::vector<int> countFrequencies(const string &s) {
    std::vector<int> freq(26, 0); // 26 lowercase English letters
    for (char c : s) {
      freq[c - 'a']++; // Increment count for this character
    }
    return freq;
  }

  // Helper function to add characters present in `order` to result in correct
  // order.
  void appendOrderedCharacters(string &result, const string &order,
                               std::vector<int> &freq) {
    for (char c : order) {
      int idx = c - 'a';
      // Append this character freq[idx] times to result (if it exists in `s`)
      result.append(freq[idx], c);
      // After appending, set frequency to 0 to avoid double-adding later
      freq[idx] = 0;
    }
  }

  // Helper function to add remaining characters (not present in order) to
  // result.
  void appendRemainingCharacters(string &result, const std::vector<int> &freq) {
    for (int i = 0; i < 26; ++i) {
      // If any counts left, add those letters to the result
      result.append(freq[i], 'a' + i);
    }
  }
};
// @lc code=end
