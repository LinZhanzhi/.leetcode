/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    int n = arr.size();
    int threshold = n / 4;
    for (int i = 0; i <= n - threshold - 1; ++i) {
      if (arr[i] == arr[i + threshold]) {
        return arr[i];
      }
    }
    // Should never reach here as per problem constraints
    return -1;
  }
};
// @lc code=end
