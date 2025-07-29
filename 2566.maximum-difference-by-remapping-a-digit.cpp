/*
 * @lc app=leetcode id=2566 lang=cpp
 *
 * [2566] Maximum Difference by Remapping a Digit
 */

// @lc code=start
class Solution {
public:
  int minMaxDifference(int num) {
    // Find the maximum value by remapping one digit to 9
    string s = to_string(num);
    string max_s = s;
    // For max: find the first digit not 9, replace all its occurrences with 9
    char to_max = 0;
    for (char c : s) {
      if (c != '9') {
        to_max = c;
        break;
      }
    }
    if (to_max) {
      for (char &c : max_s) {
        if (c == to_max)
          c = '9';
      }
    }
    int max_num = stoi(max_s);

    // For min: find the first digit not 0, replace all its occurrences with 0
    string min_s = s;
    char to_min = 0;
    for (char c : s) {
      if (c != '0') {
        to_min = c;
        break;
      }
    }
    if (to_min) {
      for (char &c : min_s) {
        if (c == to_min)
          c = '0';
      }
    }
    int min_num = stoi(min_s);

    return max_num - min_num;
  }
};
// @lc code=end
