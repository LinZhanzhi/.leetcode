/*
 * @lc app=leetcode id=522 lang=cpp
 *
 * [522] Longest Uncommon Subsequence II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the length of the longest string in the input
 * array that is a subsequence of itself but is NOT a subsequence of any other
 * string in the array. If no such string exists, we return -1. A subsequence is
 * any string that can be formed by deleting zero or more characters from
 * another string without changing the order of the remaining characters. The
 * challenge is to efficiently check, for each string, whether it is a
 * subsequence of any other string in the array.
 *
 * High-Level Summary:
 * ----
 * The solution iterates through each string in the input array and checks if it
 * is an "uncommon subsequence": that is, it is not a subsequence of any other
 * string in the array (excluding itself). To do this efficiently, we:
 *   - Sort the strings in descending order of length (so we can return early
 * with the longest possible answer).
 *   - For each string, check if it is a subsequence of any other string in the
 * array.
 *   - If not, return its length as the answer.
 *   - If no such string is found, return -1.
 /*
  * Educational Explanation:
  * ----
  * Why do we only check if the current string is a subsequence of other
 strings,
  * and not check for all possible subsequences of the current string?
  *
  * The problem asks for the "longest uncommon subsequence" among the input
 strings.
  * An "uncommon subsequence" is defined as a string that is a subsequence of
 itself
  * (which is always true), but is NOT a subsequence of any other string in the
 array.
  *
  * The key insight is that we are only allowed to select strings that are
 present
  * in the input array as candidates for the answer. We are NOT required to
 generate
  * or check all possible subsequences of each string (which would be
 exponentially
  * many and infeasible for even moderate string lengths).
  *
  * Instead, for each string in the input, we simply check if it is a
 subsequence
  * of any other string in the array. If it is not, then it is "uncommon" and we
  * consider its length for the answer. This is both correct and efficient.
  *
  * High-Level Summary:
  * ----
  * - The problem only asks about the strings in the input array, not about all
  *   possible subsequences that could be formed from them.
  * - If we were to check all possible subsequences of each string, we would be
  *   considering strings that are not present in the input, which is not
 required
  *   by the problem statement.
  * - Therefore, we only need to check, for each string in the input, whether it
  *   is a subsequence of any other string in the array.
  * - This approach is both correct and efficient, and avoids unnecessary work.
  */
*The subsequence check is done using a helper function.*
    Time complexity is O(N ^ 2 * L),
    where N is the number of strings and L is the *maximum string length(<= 10)
                .Space complexity is O(1) extra(not counting * input).*
        /

#include <algorithm> // For std::sort
#include <string>    // For std::string
#include <vector>    // For std::vector

        using std::max;
using std::string;
using std::vector;

class Solution {
public:
  // Main function to find the length of the longest uncommon subsequence
  int findLUSlength(vector<string> &strs) {
    // Sort the strings in descending order of length.
    // This ensures we check longer strings first, so we can return early.
    std::sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
      return a.size() > b.size();
    });

    // Iterate through each string in the sorted array
    for (int i = 0; i < strs.size(); ++i) {
      // For each string, check if it is a subsequence of any other string
      bool isUncommon = true; // Assume it is uncommon until proven otherwise

      for (int j = 0; j < strs.size(); ++j) {
        // Skip comparing the string with itself
        if (i == j)
          continue;
        // If strs[i] is a subsequence of strs[j], it is not uncommon
        if (isSubsequence(strs[i], strs[j])) {
          isUncommon = false;
          break; // No need to check further
        }
      }

      // If the string is not a subsequence of any other, return its length
      if (isUncommon) {
        return strs[i].size();
      }
    }

    // If no uncommon subsequence is found, return -1
    return -1;
  }

private:
  // Helper function to check if 'sub' is a subsequence of 'full'
  bool isSubsequence(const string &sub, const string &full) {
    // If sub is longer than full, it cannot be a subsequence
    if (sub.size() > full.size())
      return false;

    // Use two pointers to check for subsequence
    int i = 0; // Pointer for sub
    int j = 0; // Pointer for full

    // Iterate through both strings
    while (i < sub.size() && j < full.size()) {
      if (sub[i] == full[j]) {
        // If characters match, move both pointers
        ++i;
      }
      // Always move the pointer for full
      ++j;
    }

    // If we've matched all characters in sub, it's a subsequence
    return i == sub.size();
  }
};
// @lc code=end
