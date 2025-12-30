/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
  void sortColors(vector<int> &nums) {
    // Dutch National Flag algorithm (one-pass, constant space)
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
      if (nums[mid] == 0) {
        std::swap(nums[low], nums[mid]);
        low++;
        mid++;
      } else if (nums[mid] == 1) {
        mid++;
      } else { // nums[mid] == 2
        std::swap(nums[mid], nums[high]);
        high--;
      }
    }
  }
};
// @lc code=end
