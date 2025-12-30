/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<pair<int, int>> power;
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; ++i) {
      // Count soldiers using binary search
      int left = 0, right = n;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (mat[i][mid] == 1)
          left = mid + 1;
        else
          right = mid;
      }
      power.push_back({left, i});
    }
    sort(power.begin(), power.end());
    vector<int> res;
    for (int i = 0; i < k; ++i) {
      res.push_back(power[i].second);
    }
    return res;
  }
};
// @lc code=end
