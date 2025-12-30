/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to compress a list of characters in-place by replacing
 * consecutive repeating characters with the character followed by the count of
 * its repetitions (if more than one). For example, "aaabb" becomes "a3b2". The
 * compressed result must overwrite the original array, and we must return the
 * new length. We are not allowed to use extra space proportional to the input
 * size—only a constant amount.
 *
 * High-Level Summary:
 * ----
 * The solution uses two pointers: one to read through the input (`read`), and
 * one to write the compressed result (`write`). For each group of consecutive
 * repeating characters, we write the character, and if the group is longer than
 * one, we write the count as individual digits. This is done in-place, and we
 * return the position of the write pointer as the new length. The algorithm
 * runs in O(n) time and uses O(1) extra space.
 */

#include <string> // Include string for std::to_string
#include <vector> // Include vector for std::vector

using std::vector; // Bring std::vector into scope

// @lc code=start
class Solution {
public:
  int compress(vector<char> &chars) {
    // 'write' is the index where we write the next compressed character or
    // digit
    int write = 0;
    // 'read' is the index for reading through the input array
    int read = 0;
    int n = chars.size(); // Store the size for efficiency

    // Loop through the array until we've processed all characters
    while (read < n) {
      char current_char =
          chars[read];        // The character we're currently compressing
      int group_start = read; // Start index of the current group

      // Move 'read' forward as long as the next character is the same
      while (read < n && chars[read] == current_char) {
        read++;
      }
      int group_length =
          read - group_start; // Number of times current_char repeats

      // Write the character to the 'write' position
      chars[write++] = current_char;

      // If the group is longer than 1, write its length as individual digits
      if (group_length > 1) {
        // Convert the count to a string (e.g., 12 -> "12")
        std::string count_str = std::to_string(group_length);
        // Write each digit of the count to the array
        for (char digit : count_str) {
          chars[write++] = digit;
        }
      }
      // If group_length == 1, nothing extra is written (just the character)
    }
    // After processing, 'write' is the new length of the compressed array
    return write;
  }
};
// @lc code=end
