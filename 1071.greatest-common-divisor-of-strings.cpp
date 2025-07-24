/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * Detailed Proof of Solution:
 *
 * Problem Restatement:
 * Given two strings str1 and str2, return the largest string X such that X
 * divides both str1 and str2.
 * A string X divides S if S is made by concatenating X with itself one or more
 * times.
 *
 * Solution Overview:
 * 1. If there exists a string X that divides both str1 and str2, then
 * concatenating str1 + str2 must be equal to str2 + str1.
 *    - Proof: Suppose str1 = X repeated m times, str2 = X repeated n times.
 *      Then, str1 + str2 = X...X (m times) + X...X (n times) = X...X (m+n
 * times) Similarly, str2 + str1 = X...X (n times) + X...X (m times) = X...X
 * (n+m times) So, str1 + str2 == str2 + str1.
 *    - Conversely, if str1 + str2 != str2 + str1, then there is no such X.
 *
 * 2. The length of the greatest common divisor string must be the greatest
 * common divisor (gcd) of the lengths of str1 and str2.
 *    - Proof: Let len1 = |str1|, len2 = |str2|. If X divides both, then |X|
 * divides both len1 and len2. The largest such |X| is gcd(len1, len2).
 *    - So, the answer is str1.substr(0, gcd(len1, len2)), provided the check in
 * (1) passes.
 *
 * 3. The code implements these two steps:
 *    - If str1 + str2 != str2 + str1, return "".
 *    - Otherwise, return str1.substr(0, gcd(len1, len2)).
 *
 * This is both correct and optimal.
 */

// @lc code=start
#include <numeric>
#include <string>

using std::string;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    // Step 1: Check if a common divisor string is possible
    if (str1 + str2 != str2 + str1) {
      // If not, return empty string
      return "";
    }
    // Step 2: Compute the length of the greatest common divisor string
    int gcd = std::gcd(str1.size(), str2.size());
    // Step 3: Return the substring of length gcd
    return str1.substr(0, gcd);
  }
};
// @lc code=end
