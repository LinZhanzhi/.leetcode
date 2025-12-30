/*
 * @lc app=leetcode id=2815 lang=cpp
 *
 * [2815] Max Pair Sum in an Array
 */

// @lc code=start
class Solution {
public:
  int maxSum(vector<int> &nums) {
    auto getMaxDigit = [](int n) {
      int maxD = 0;
      while (n) {
        maxD = max(maxD, n % 10);
        n /= 10;
      }
      return maxD;
    };
    unordered_map<int, vector<int>> groups;
    for (int num : nums) {
      int d = getMaxDigit(num);
      groups[d].push_back(num);
    }
    int res = -1;
    for (auto &[d, v] : groups) {
      if (v.size() >= 2) {
        sort(v.begin(), v.end(), greater<int>());
        res = max(res, v[0] + v[1]);
      }
    }
    return res;
  }
};
// @lc code=end
