/*
 * @lc app=leetcode id=3507 lang=cpp
 *
 * [3507] Minimum Pair Removal to Sort Array I
 */

// @lc code=start
class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    int n = nums.size();
    int ops = 0;
    // Helper to check if array is non-decreasing
    auto is_sorted = [](const vector<int> &arr) {
      for (int i = 1; i < arr.size(); ++i)
        if (arr[i] < arr[i - 1])
          return false;
      return true;
    };
    while (!is_sorted(nums)) {
      int min_sum = INT_MAX, idx = -1;
      for (int i = 0; i < nums.size() - 1; ++i) {
        int s = nums[i] + nums[i + 1];
        if (s < min_sum) {
          min_sum = s;
          idx = i;
        }
      }
      // Replace nums[idx] and nums[idx+1] with their sum
      nums[idx] = nums[idx] + nums[idx + 1];
      nums.erase(nums.begin() + idx + 1);
      ++ops;
    }
    return ops;
  }
};
// @lc code=end
