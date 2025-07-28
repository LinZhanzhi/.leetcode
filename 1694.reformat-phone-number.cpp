/*
 * @lc app=leetcode id=1694 lang=cpp
 *
 * [1694] Reformat Phone Number
 */

// @lc code=start
class Solution {
public:
  string reformatNumber(string number) {
    number.erase(remove(number.begin(), number.end(), ' '),
                 number.end()); // remove spaces
    number.erase(remove(number.begin(), number.end(), '-'),
                 number.end()); // remove dashes
    int remainder = number.size();
    int i = 0;
    while (remainder > 4) {
      i += 3;
      number.insert(i, "-");
      remainder -= 3;
      i += 1;
    }
    if (remainder == 4) {
      // insert a dash after the second digit
      number.insert(i + 2, "-");
    }
    return number;
  }
};
// @lc code=end
