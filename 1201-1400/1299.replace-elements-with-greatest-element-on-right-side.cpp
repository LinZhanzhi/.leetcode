/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    int n = arr.size();
    int maxRight = -1;
    for (int i = n - 1; i >= 0; --i) {
      int temp = arr[i];
      arr[i] = maxRight;
      if (temp > maxRight) {
        maxRight = temp;
      }
    }
    return arr;
  }
};
// @lc code=end
