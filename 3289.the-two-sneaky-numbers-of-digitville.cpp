/*
 * @lc app=leetcode id=3289 lang=cpp
 *
 * [3289] The Two Sneaky Numbers of Digitville
 */

// @lc code=start
class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    vector<int> res;
    int n = nums.size() - 2;
    vector<int> count(n, 0);
    for (int num : nums) {
      count[num]++;
    }
    for (int i = 0; i < n; ++i) {
      if (count[i] == 2) {
        res.push_back(i);
        if (res.size() == 2)
          break;
      }
    }
    return res;
  }
};
// @lc code=end
