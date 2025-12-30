/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks: Given a string of uppercase letters, and up to k allowed
 * character changes, what is the length of the longest substring you can make
 * where all the letters are the same? You can change any character to any other
 * uppercase letter, but you can only do this at most k times. The goal is to
 * find the maximum possible length of such a uniform substring after at most k
 * changes.
 */

/*
 * High-Level Summary:
 * ----
 * The optimal approach uses a sliding window technique. We maintain a window
 * [left, right] over the string, and for each window, we track the count of the
 * most frequent character in that window. The minimum number of changes needed
 * to make all characters in the window the same is: (window size) - (count of
 * most frequent character) If this number is less than or equal to k, the
 * window is valid. We expand the window to the right as long as it's valid, and
 * shrink from the left when it isn't. We keep track of the maximum window size
 * found.
 *
 * Time Complexity: O(N), where N is the length of the string, since each
 * character is visited at most twice. Space Complexity: O(1), since the
 * frequency array is always of size 26 (for uppercase letters).
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
  int characterReplacement(string s, int k) {
    // Array to keep count of each uppercase letter in the current window.
    // There are 26 uppercase English letters.
    vector<int> count(26, 0);

    int maxCount =
        0; // The count of the most frequent character in the current window.
    int maxLength =
        0;        // The result: the maximum length of a valid window found.
    int left = 0; // Left pointer of the sliding window.

    // Iterate with the right pointer over the string.
    for (int right = 0; right < s.size(); ++right) {
      // Update the count for the current character at position 'right'.
      count[s[right] - 'A']++;
      maxCount = getMaxCount(count);

      // The number of characters to change in the current window is:
      // (window size) - (maxCount)
      // If this exceeds k, the window is invalid, so we shrink it from the
      // left.
      while ((right - left + 1) - maxCount > k) {
        // Decrement the count of the character going out of the window.
        count[s[left] - 'A']--;
        // Move the left pointer to shrink the window.
        left++;
        // Update maxCount to the new maximum count in the window.
        maxCount = getMaxCount(count);
      }

      // Update the maximum length found so far.
      maxLength = max(maxLength, right - left + 1);
    }

    // Return the length of the longest valid window found.
    return maxLength;
  }

private:
  /*
   * Brief, Digested Understanding:
   * ----
   * We want a helper function that, given a vector of 26 integers (representing
   * the counts of each uppercase English letter), returns the maximum value in
   * that vector. This is useful for quickly finding the most frequent character
   * in a window or substring.
   *
   * High-Level Summary:
   * ----
   * The function iterates through the vector and keeps track of the largest
   * value seen so far. It returns this maximum at the end. The time complexity
   * is O(26) = O(1), since the vector always has 26 elements, and the space
   * complexity is O(1).
   */

  // Helper function to get the maximum value in a vector<int> of size 26.
  // This function is private to the Solution class.
  int getMaxCount(const vector<int> &count) {
    int maxVal = 0; // Initialize the maximum value to 0.
    // Iterate through all 26 elements (for 'A' to 'Z').
    for (int i = 0; i < 26; ++i) {
      // Update maxVal if a larger value is found.
      if (count[i] > maxVal) {
        maxVal = count[i];
      }
    }
    // Return the largest count found.
    return maxVal;
  }
};
// @lc code=end
