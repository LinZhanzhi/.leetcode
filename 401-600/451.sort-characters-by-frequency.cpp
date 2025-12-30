/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to rearrange the characters in a string so that
 * characters that appear more frequently come first. If two characters have the
 * same frequency, their order doesn't matter, but all occurrences of the same
 * character must be grouped together. The input string can contain uppercase,
 * lowercase letters, and digits, and we must treat each character as distinct
 * (e.g., 'A' ≠ 'a').
 */

/*
 * High-Level Summary:
 * ----
 * The solution involves three main steps:
 *   1. Count the frequency of each character in the string using a hash map.
 *   2. Sort the characters by their frequency in descending order.
 *   3. Build the result string by repeating each character according to its
 * frequency.
 *
 * We use an unordered_map to count frequencies, a vector of pairs to sort
 * characters by frequency, and then construct the output.
 *
 * Time Complexity: O(N log K), where N is the length of the string and K is the
 * number of unique characters (at most 62 for [A-Za-z0-9]). Space Complexity:
 * O(N + K), for the frequency map, the vector, and the result string.
 */

#include <algorithm>     // For std::sort
#include <string>        // For std::string
#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to sort characters by frequency
  string frequencySort(string s) {
    // Step 1: Count the frequency of each character in the string
    unordered_map<char, int> freqMap; // Maps each character to its frequency
    for (char c : s) {
      freqMap[c]++; // Increment the count for character c
    }

    // Step 2: Store characters and their frequencies in a vector for sorting
    // Each element is a pair: (character, frequency)
    vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

    // Step 3: Sort the vector by frequency in descending order
    // If two characters have the same frequency, their order doesn't matter
    std::sort(freqVec.begin(), freqVec.end(),
              [](const pair<char, int> &a, const pair<char, int> &b) {
                return a.second > b.second; // Sort by frequency descending
              });

    // Step 4: Build the result string by repeating each character by its
    // frequency
    string result;
    result.reserve(s.size()); // Reserve space for efficiency

    for (const auto &entry : freqVec) {
      // Append 'entry.second' copies of 'entry.first' to the result
      result.append(entry.second, entry.first);
    }

    // Return the final sorted string
    return result;
  }
};
// @lc code=end
