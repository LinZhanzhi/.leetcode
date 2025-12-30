/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
  // int maxSubArray(vector<int> &nums) {
  //   // prevsum[i] = sum(nums[0, i]), inclusive
  //   int n = nums.size();
  //   vector<int> prevsum(n + 1);
  //   prevsum[0] = nums[0];
  //   for (int i = 1; i < n; i++) {
  //     prevsum[i] = prevsum[i - 1] + nums[i];
  //   }
  //   // for all 0 <= i <= j < n, sum(nums[i, j]) = prevsum[j] - prevsum[i-1]
  //   // given j, the minimum prevsum[i-1] shall yield the maximum sum for a
  //   // subarray ending at num[j] let's denote that as res[j] res[j] =
  //   // max(sum(nums[i, j])) for all i in [0, j] res[j] = max(prevsum[j] -
  //   // prevsum[i-1]) for all i in [0, j] res[j] = prevsum[j] -
  //   min(prevsum[i-1])
  //   // for all i in [0, j] we can use a min_prevsum array to store the
  //   minimum
  //   // value of prevsum[i-1] for all i in [0, j] for all i in [0, j]
  //   vector<int> min_prevsum(n + 1);
  //   min_prevsum[0] = min(prevsum[0], 0);
  //   for (int j = 1; j < n; j++) {
  //     min_prevsum[j] = min(min_prevsum[j - 1], prevsum[j]);
  //   }
  //   // calculate res
  //   vector<int> res(n);
  //   res[0] = prevsum[0];
  //   for (int j = 1; j < n; j++) {
  //     res[j] = prevsum[j] - min_prevsum[j - 1];
  //   }
  //   return *max_element(res.begin(), res.end());
  // }
  int maxSubArray(vector<int> &nums) {
    // Divide and conquer approach
    function<int(int, int)> helper = [&](int left, int right) -> int {
      if (left == right) {
        return nums[left];
      }
      int mid = left + (right - left) / 2;
      int leftMax = helper(left, mid);
      int rightMax = helper(mid + 1, right);

      // Find max crossing sum
      int leftSum = INT_MIN, sum = 0;
      for (int i = mid; i >= left; --i) {
        sum += nums[i];
        leftSum = max(leftSum, sum);
      }
      int rightSum = INT_MIN;
      sum = 0;
      for (int i = mid + 1; i <= right; ++i) {
        sum += nums[i];
        rightSum = max(rightSum, sum);
      }
      int crossMax = leftSum + rightSum;
      return max({leftMax, rightMax, crossMax});
    };
    return helper(0, nums.size() - 1);
  }
};
// @lc code=end
