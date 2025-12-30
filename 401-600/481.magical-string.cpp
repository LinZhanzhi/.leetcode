/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The "magical string" is a self-generating sequence of '1's and '2's, where
 * the counts of consecutive identical digits, when read in order, reproduce the
 * string itself. For example, the string starts as "1 22 11 2 1 22 ...", and
 * the sequence of group lengths ("1 2 2 1 1 2 ...") is the same as the string
 * itself. The problem asks: given n, how many '1's are in the first n
 * characters of this magical string?
 *
 * High-Level Summary:
 * ----
 * To solve this, we simulate the construction of the magical string up to
 * length n. We use a vector to store the sequence, and a pointer to track which
 * group size to use next (taken from the string itself). We alternate between
 * appending '1's and '2's, using the group sizes as dictated by the string. We
 * count the number of '1's as we build the string. The algorithm is O(n) time
 * and O(n) space, as we only generate up to n characters.
 */

// @lc code=start
#include <vector> // Include vector for dynamic array storage

class Solution {
public:
  // Main function to count the number of '1's in the first n characters of the
  // magical string
  int magicalString(int n) {
    // Edge case: if n is 0, there are no characters, so return 0
    if (n == 0)
      return 0;
    // Edge case: if n is 1, the string is just "1"
    if (n == 1)
      return 1;

    // Initialize the magical string with the starting sequence "1, 2, 2"
    std::vector<int> s = {1, 2, 2};
    // The index in s that tells us how many times to append the next number
    int groupIdx = 2;
    // The next number to append (alternates between 1 and 2)
    int nextNum = 1;
    // Count of '1's in the magical string so far
    int onesCount = 1; // The first element is '1'

    // Continue building the magical string until it reaches at least n
    // characters
    while ((int)s.size() < n) {
      // The current group size (how many times to append nextNum)
      int groupSize = s[groupIdx];
      // Append nextNum groupSize times
      for (int i = 0; i < groupSize && (int)s.size() < n; ++i) {
        s.push_back(nextNum);
        // If the number appended is '1', increment the count
        if (nextNum == 1) {
          ++onesCount;
        }
      }
      // Alternate the next number: if it was 1, make it 2; if 2, make it 1
      nextNum = 3 - nextNum;
      // Move to the next group in the magical string
      ++groupIdx;
    }
    // Return the total count of '1's in the first n characters
    return onesCount;
  }
};
// @lc code=end
