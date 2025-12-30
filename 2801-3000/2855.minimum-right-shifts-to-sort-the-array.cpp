/*
 * @lc app=leetcode id=2855 lang=cpp
 *
 * [2855] Minimum Right Shifts to Sort the Array
 */

// @lc code=start
class Solution {
public:
  int minimumRightShifts(vector<int> &nums) {
    // by sorting the problem mean strictly increasing
    // if the array can be sorted using right shifts,
    // then there is at most one drop in the array
    int drop = -1; // the index of the drop
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        if (drop == -1)
          drop = i;
        else
          return -1;
      }
    }
    if (drop == -1)
      return 0;
    // check the rightmost element is smaller than the leftmost element
    if (nums[nums.size() - 1] > nums[0])
      return -1;
    return nums.size() - drop;
  }
};
// @lc code=end
