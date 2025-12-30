/*
 * @lc app=leetcode id=3602 lang=cpp
 *
 * [3602] Hexadecimal and Hexatrigesimal Conversion
 */

#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  string toBase(int num, int base, int maxDigit) {
    string res;
    while (num > 0) {
      int rem = num % base;
      if (rem < 10)
        res += char('0' + rem);
      else
        res += char('A' + (rem - 10));
      num /= base;
    }
    if (res.empty())
      res = "0";
    reverse(res.begin(), res.end());
    return res;
  }

  string concatHex36(int n) {
    int n2 = n * n;
    int n3 = n * n * n;
    string hex = toBase(n2, 16, 15);   // 0-9, A-F
    string hex36 = toBase(n3, 36, 35); // 0-9, A-Z
    return hex + hex36;
  }
};
// @lc code=end
