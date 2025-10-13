/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// Brief Digested Understanding:
// This problem challenges us to find out how many times we must repeat the
// first string 'a' so that the second string 'b' appears as a substring in that
// repeated sequence. If 'b' cannot possibly appear as a substring regardless of
// how many times we repeat 'a', we must return -1. The core concept is about
// string repetition and window substring searching.

// High-Level Summary:
// To solve the problem, we repeat string 'a' enough times so that its total
// length is at least as long as 'b', since otherwise 'b' cannot fit inside. In
// fact, it might need to be repeated *just over* the length of 'b' to catch
// cases where 'b' "wraps around" between two concatenated 'a's. We'll try up to
// (b.length / a.length) + 2 repetitions, checking after each addition whether
// 'b' is now a substring. If so, return the number of repetitions needed;
// otherwise return -1 if no such substring is found. This uses basic string
// operations; no advanced algorithms are required. Time complexity is O(N * M)
// for the substring checking (with possible optimizations depending on the STL
// implementation), where N is the number of repetitions and M is max size of a
// or b. Space complexity is O(N*M) due to string concatenation.

// @lc code=start
#include <string> // Needed for std::string
using std::string;

class Solution {
public:
  // Main function: returns the minimum number of times to repeat 'a' so that
  // 'b' is a substring
  int repeatedStringMatch(string a, string b) {
    // Helper function: Checks if 'b' is a substring of 'repeated' string
    auto isSubstring = [](const string &repeated, const string &b) -> bool {
      // Uses find(), which returns npos if not found
      return repeated.find(b) != string::npos;
    };

    int minRepeats = (b.size() + a.size() - 1) / a.size();
    // Above: minimal repeats to cover b's length.

    string repeated = ""; // Will hold 'a' repeated several times

    // Repeat up to minRepeats + 2 to handle overlaps
    for (int repeat = 1; repeat <= minRepeats + 2; ++repeat) {
      repeated += a; // Add another 'a'
      // After each addition, check if 'b' is now a substring
      if (isSubstring(repeated, b)) {
        return repeat; // Found the minimal repetition
      }
    }
    // If we exit loop, 'b' cannot be a substring regardless of repeats
    return -1;
  }
};
// @lc code=end
