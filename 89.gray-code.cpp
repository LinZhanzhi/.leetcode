/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> res;
    int size = 1 << n; // 2^n
    for (int i = 0; i < size; ++i) {
      res.push_back(i ^ (i >> 1));
    }
    return res;
  }
};
// @lc code=end
