/*
 * @lc app=leetcode id=3038 lang=cpp
 *
 * [3038] Maximum Number of Operations With the Same Score I
 */

// @lc code=start
class Solution {
public:
  int maxOperations(vector<int> &nums) {
    int n = nums.size();
    if (n < 2)
      return 0;
    int score = nums[0] + nums[1];
    int cnt = 0;
    int i = 0;
    while (i + 1 < n) {
      if (nums[i] + nums[i + 1] == score) {
        cnt++;
        i += 2;
      } else {
        break;
      }
    }
    return cnt;
  }
};
// @lc code=end
