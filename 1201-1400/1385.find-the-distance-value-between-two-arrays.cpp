/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start
class Solution {
public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    int count = 0;
    for (int i = 0; i < arr1.size(); ++i) {
      bool valid = true;
      for (int j = 0; j < arr2.size(); ++j) {
        if (abs(arr1[i] - arr2[j]) <= d) {
          valid = false;
          break;
        }
      }
      if (valid)
        ++count;
    }
    return count;
  }
};
// @lc code=end
