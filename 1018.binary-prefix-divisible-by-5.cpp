/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int> &nums) {
    vector<bool> answer;
    int num = 0;
    for (int i = 0; i < nums.size(); ++i) {
      num = ((num << 1) + nums[i]) % 5;
      answer.push_back(num == 0);
    }
    return answer;
  }
};
// @lc code=end
