/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a list of words and need to find two words that do not share any
 * common letters. For such a pair, we calculate the product of their lengths,
 * and our goal is to return the maximum such product. If no such pair exists
 * (i.e., every pair shares at least one letter), we return 0. The main
 * challenge is efficiently checking if two words share any letters, especially
 * since the list can be large.
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses bit manipulation to efficiently check for common letters
 * between words. For each word, we create a 26-bit integer (bitmask) where each
 * bit represents a letter from 'a' to 'z'. If a word contains a letter, its
 * corresponding bit is set to 1. To check if two words share any letters, we
 * perform a bitwise AND between their bitmasks. If the result is 0, the words
 * have no letters in common. We then iterate over all pairs of words, check
 * their bitmasks, and update the maximum product accordingly.
 *
 * Time Complexity: O(N^2), where N is the number of words (since we check all
 * pairs). Space Complexity: O(N), for storing the bitmasks.
 */

#include <string> // For std::string
#include <vector> // For std::vector

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  int maxProduct(vector<string> &words) {
    int n = words.size();    // Number of words in the input list
    vector<int> masks(n, 0); // To store the bitmask for each word

    // Step 1: Build the bitmask for each word
    for (int i = 0; i < n; ++i) {
      int mask = 0; // Initialize mask for the current word
      for (char c : words[i]) {
        // Set the bit corresponding to the character 'c'
        // 'a' maps to bit 0, 'b' to bit 1, ..., 'z' to bit 25
        mask |= (1 << (c - 'a'));
      }
      masks[i] = mask; // Store the mask for the i-th word
    }

    int maxProd = 0; // To keep track of the maximum product found

    // Step 2: Compare all pairs of words
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        // If the bitwise AND is zero, the words share no common letters
        if ((masks[i] & masks[j]) == 0) {
          int prod =
              words[i].size() * words[j].size(); // Calculate product of lengths
          if (prod > maxProd) {
            maxProd = prod; // Update max product if this pair is better
          }
        }
      }
    }

    // If no such pair exists, maxProd remains 0
    return maxProd;
  }
};
// @lc code=end
