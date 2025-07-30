/*
 * @lc app=leetcode id=3314 lang=cpp
 *
 * [3314] Construct the Minimum Bitwise Array I
 */

// @lc code=start
class Solution {
public:
  vector<int> minBitwiseArray(vector<int> &nums) {
    vector<int> ans;
    for (int num : nums) {
      int found = -1;
      // Try all possible ans in [0, num]
      for (int x = 0; x <= num; ++x) {
        if ((x | (x + 1)) == num) {
          found = x;
          break;
        }
      }
      ans.push_back(found);
    }
    return ans;
  }
};
// @lc code=end
