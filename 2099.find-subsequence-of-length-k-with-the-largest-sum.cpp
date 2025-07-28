/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 */

// @lc code=start
class Solution {
public:
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    vector<pair<int, int>> num_with_idx;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      num_with_idx.push_back({nums[i], i});
    }
    // Sort by value descending
    sort(num_with_idx.begin(), num_with_idx.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           if (a.first != b.first)
             return a.first > b.first;
           return a.second < b.second;
         });
    // Take the first k elements (largest values)
    vector<int> indices;
    for (int i = 0; i < k; ++i) {
      indices.push_back(num_with_idx[i].second);
    }
    // Sort indices to preserve original order
    sort(indices.begin(), indices.end());
    vector<int> res;
    for (int idx : indices) {
      res.push_back(nums[idx]);
    }
    return res;
  }
};
// @lc code=end
