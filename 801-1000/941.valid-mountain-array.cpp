/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
  bool validMountainArray(vector<int> &arr) {
    if (arr.size() < 3)
      return false;
    int i = 0;
    int n = arr.size();
    // walk up
    while (i + 1 < n && arr[i] < arr[i + 1]) {
      i++;
    }
    // peak can't be first or last
    if (i == 0 || i == n - 1)
      return false;
    // walk down
    while (i + 1 < n && arr[i] > arr[i + 1]) {
      i++;
    }
    return i == n - 1;
  }
};
// @lc code=end
