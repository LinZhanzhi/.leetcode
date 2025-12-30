/*
 * @lc app=leetcode id=2395 lang=cpp
 *
 * [2395] Find Subarrays With Equal Sum
 */

// @lc code=start
class Solution {
public:
  /*
   * 1. Use a set to store the sums of all subarrays of length 2.
   * 2. If the sum is already in the set, return true.
   * 3. Otherwise, add the sum to the set.
   * 4. If no subarray with equal sum is found, return false.
   *
   * Time Complexity: O(n)
   * Space Complexity: O(n)
   */
  bool findSubarrays(vector<int> &nums) {
    unordered_set<int> seen;
    for (int i = 0; i < nums.size() - 1; ++i) {
      int sum = nums[i] + nums[i + 1];
      if (seen.count(sum)) {
        return true;
      }
      seen.insert(sum);
    }
    return false;
  }
};
// @lc code=end
