/*
 * @lc app=leetcode id=2553 lang=cpp
 *
 * [2553] Separate the Digits in an Array
 */

// @lc code=start
class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> answer;
    for (int num : nums) {
      vector<int> digits;
      if (num == 0) {
        digits.push_back(0);
      } else {
        while (num > 0) {
          digits.push_back(num % 10);
          num /= 10;
        }
        reverse(digits.begin(), digits.end());
      }
      answer.insert(answer.end(), digits.begin(), digits.end());
    }
    return answer;
  }
};
// @lc code=end
