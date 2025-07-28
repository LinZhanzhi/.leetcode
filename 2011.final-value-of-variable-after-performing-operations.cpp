/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
 */

// @lc code=start
class Solution {
public:
  int finalValueAfterOperations(vector<string> &operations) {
    int X = 0;
    for (const string &op : operations) {
      if (op[1] == '+') {
        X++;
      } else {
        X--;
      }
    }
    return X;
  }
};
// @lc code=end
