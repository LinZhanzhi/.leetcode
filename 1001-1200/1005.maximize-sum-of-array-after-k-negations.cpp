/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    // INSERT_YOUR_CODE
    sort(nums.begin(), nums.end());
    int i = 0;
    int n = nums.size();
    // Flip as many negative numbers as possible
    while (i < n && k > 0 && nums[i] < 0) {
      nums[i] = -nums[i];
      i++;
      k--;
    }
    // If k is still positive and odd, flip the smallest absolute value
    int minVal = *min_element(nums.begin(), nums.end());
    if (k % 2 == 1) {
      for (int j = 0; j < n; ++j) {
        if (nums[j] == minVal) {
          nums[j] = -nums[j];
          break;
        }
      }
    }
    int sum = 0;
    for (int num : nums)
      sum += num;
    return sum;
  }
};
// @lc code=end
