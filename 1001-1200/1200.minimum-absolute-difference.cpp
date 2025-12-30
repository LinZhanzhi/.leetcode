/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    vector<vector<int>> res;
    // First, find the minimum absolute difference
    for (int i = 1; i < arr.size(); ++i) {
      minDiff = min(minDiff, arr[i] - arr[i - 1]);
    }
    // Then, collect all pairs with that difference
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] - arr[i - 1] == minDiff) {
        res.push_back({arr[i - 1], arr[i]});
      }
    }
    return res;
  }
};
// @lc code=end
