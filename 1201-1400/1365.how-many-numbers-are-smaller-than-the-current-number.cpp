/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    vector<int> res(nums.size(), 0);
    // Since 0 <= nums[i] <= 100, we can use counting sort idea
    vector<int> count(101, 0);
    // Count the frequency of each number
    for (int n : nums) {
      count[n]++;
    }
    // Compute prefix sums: count[i] will be the number of elements < i
    for (int i = 1; i < 101; ++i) {
      count[i] += count[i - 1];
    }
    // For each number, the answer is count[nums[i]-1] (if nums[i] > 0)
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        res[i] = 0;
      } else {
        res[i] = count[nums[i] - 1];
      }
    }
    return res;
  }
};
// @lc code=end
