/*
 * @lc app=leetcode id=1880 lang=cpp
 *
 * [1880] Check if Word Equals Summation of Two Words
 */

// @lc code=start
class Solution {
public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    auto getNum = [](const string &s) -> int {
      string numStr;
      for (char c : s) {
        numStr += to_string(c - 'a');
      }
      return stoi(numStr);
    };
    return getNum(firstWord) + getNum(secondWord) == getNum(targetWord);
  }
};
// @lc code=end