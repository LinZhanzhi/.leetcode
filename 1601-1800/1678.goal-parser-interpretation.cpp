/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
class Solution {
public:
  string interpret(string command) {
    string res;
    for (int i = 0; i < command.size();) {
      if (command[i] == 'G') {
        res += 'G';
        i++;
      } else if (command[i] == '(' && command[i + 1] == ')') {
        res += 'o';
        i += 2;
      } else if (command[i] == '(' && command[i + 1] == 'a') {
        res += "al";
        i += 4;
      }
    }
    return res;
  }
};
// @lc code=end
