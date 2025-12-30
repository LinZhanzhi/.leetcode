/*
 * @lc app=leetcode id=2206 lang=cpp
 *
 * [2206] Divide Array Into Equal Pairs
 */

// @lc code=start
class Solution {
public:
  bool divideArray(vector<int> &nums) {
    // INSERT_YOUR_CODE
    int freq[501] = {0};
    for (int num : nums) {
      freq[num]++;
    }
    for (int i = 1; i <= 500; ++i) {
      if (freq[i] % 2 != 0)
        return false;
    }
    return true;
  }
};
// @lc code=end
