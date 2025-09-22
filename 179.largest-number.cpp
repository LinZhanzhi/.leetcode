/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    // Convert all numbers to strings
    vector<string> numStrs;
    for (int num : nums) {
      numStrs.push_back(std::to_string(num));
    }
    // Custom sort: if a+b > b+a, a should come before b
    std::sort(numStrs.begin(), numStrs.end(),
              [](const string &a, const string &b) { return a + b > b + a; });
    // If the largest number is "0", the result is "0"
    if (numStrs[0] == "0")
      return "0";
    // Concatenate all strings
    string result;
    for (const string &s : numStrs) {
      result += s;
    }
    return result;
  }
};
