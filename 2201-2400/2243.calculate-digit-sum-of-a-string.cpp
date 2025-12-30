/*
 * @lc app=leetcode id=2243 lang=cpp
 *
 * [2243] Calculate Digit Sum of a String
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  // Helper function to calculate the sum of digits in a substring [start, end)
  int sumOfDigits(const string &s, int start, int end) {
    int sum = 0;
    for (int i = start; i < end && i < s.length(); ++i) {
      sum += s[i] - '0';
    }
    return sum;
  }

  // Helper function to process the string in groups of size k and return the
  // new string
  string processGroups(const string &s, int k) {
    string new_s = "";
    for (int i = 0; i < s.length(); i += k) {
      int sum = sumOfDigits(s, i, i + k);
      new_s += to_string(sum);
    }
    return new_s;
  }

  string digitSum(string s, int k) {
    while (s.length() > k) {
      s = processGroups(s, k);
    }
    return s;
  }
};
// @lc code=end
