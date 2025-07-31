/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};

    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> result;
    string current;

    function<void(int)> backtrack = [&](int idx) {
      if (idx == digits.size()) {
        result.push_back(current);
        return;
      }
      string letters = mapping[digits[idx] - '0'];
      for (char c : letters) {
        current.push_back(c);
        backtrack(idx + 1);
        current.pop_back();
      }
    };

    backtrack(0);
    return result;
  }
};
// @lc code=end
