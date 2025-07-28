/*
 * @lc app=leetcode id=2190 lang=cpp
 *
 * [2190] Most Frequent Number Following Key In an Array
 */

// @lc code=start
class Solution {
public:
  int mostFrequent(vector<int> &nums, int key) {
    unordered_map<int, int> count;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] == key) {
        count[nums[i + 1]]++;
      }
    }
    int maxCount = 0, res = 0;
    for (auto &[target, cnt] : count) {
      if (cnt > maxCount) {
        maxCount = cnt;
        res = target;
      }
    }
    return res;
  }
};
// @lc code=end
