/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    if (arr.empty())
      return {};
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> rank;
    int curr_rank = 1;
    for (int num : sorted) {
      if (rank.find(num) == rank.end()) {
        rank[num] = curr_rank++;
      }
    }
    vector<int> res;
    for (int num : arr) {
      res.push_back(rank[num]);
    }
    return res;
  }
};
// @lc code=end
