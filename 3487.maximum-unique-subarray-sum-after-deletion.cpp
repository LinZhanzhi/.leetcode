/*
 * @lc app=leetcode id=3487 lang=cpp
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
 */

// @lc code=start
class Solution {
public:
  int maxSum(vector<int> &nums) {
    // The problem allows us to delete any number of elements, so we can select
    // any subset of unique elements. The optimal is to pick all unique elements
    // and sum the positive ones.
    unordered_set<int> seen;
    int sum = 0;
    for (int x : nums) {
      if (!seen.count(x)) {
        seen.insert(x);
        if (x > 0)
          sum += x;
      }
    }
    // If all numbers are negative or zero, pick the largest one.
    if (sum == 0) {
      int max_elem = nums[0];
      for (int x : nums)
        max_elem = max(max_elem, x);
      return max_elem;
    }
    return sum;
  }
};
// @lc code=end
