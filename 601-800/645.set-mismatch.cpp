/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    vector<int> res(2, -1);
    int n = nums.size();
    vector<int> count(n + 1, 0);
    for (int num : nums) {
      count[num]++;
    }
    for (int i = 1; i <= n; ++i) {
      if (count[i] == 2)
        res[0] = i;
      else if (count[i] == 0)
        res[1] = i;
    }
    return res;
  }
};
// @lc code=end
