/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 */

#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  string reformat(string s) {
    int letterCount = 0, digitCount = 0;
    // Count the number of letters and digits in the string
    for (char c : s) {
      if (isalpha(c))
        ++letterCount;
      else
        ++digitCount;
    }
    // If the difference between letters and digits is more than 1, it's
    // impossible to reformat
    if (abs(letterCount - digitCount) > 1)
      return "";

    // Decide which type should go first: letter or digit
    bool letterFirst = letterCount >= digitCount;
    int i = 0, j = 0;
    // Prepare a result string of the same size, filled with spaces
    string res(s.size(), ' ');
    // Place each character in the correct position to alternate types
    for (char c : s) {
      if (isalpha(c)) {
        if (letterFirst) {
          // Place letter at even index if letters go first
          res[i] = c;
          i += 2;
        } else {
          // Place letter at odd index if digits go first
          res[j + 1] = c;
          j += 2;
        }
      } else {
        if (!letterFirst) {
          // Place digit at even index if digits go first
          res[i] = c;
          i += 2;
        } else {
          // Place digit at odd index if letters go first
          res[j + 1] = c;
          j += 2;
        }
      }
    }
    return res;
  }
};
// @lc code=end
