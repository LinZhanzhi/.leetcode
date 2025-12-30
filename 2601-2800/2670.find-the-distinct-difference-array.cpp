/*
 * @lc app=leetcode id=2670 lang=cpp
 *
 * [2670] Find the Distinct Difference Array
 */

// @lc code=start
class Solution {
public:
  vector<int> distinctDifferenceArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> diff(n, 0);
    vector<int> prefixDistinct(n, 0), suffixDistinct(n, 0);

    unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
      seen.insert(nums[i]);
      prefixDistinct[i] = seen.size();
    }

    seen.clear();
    for (int i = n - 1; i >= 0; --i) {
      if (i == n - 1) {
        suffixDistinct[i] = 0;
      } else {
        seen.insert(nums[i + 1]);
        suffixDistinct[i] = seen.size();
      }
    }

    for (int i = 0; i < n; ++i) {
      diff[i] = prefixDistinct[i] - suffixDistinct[i];
    }
    return diff;
  }
};
// @lc code=end
