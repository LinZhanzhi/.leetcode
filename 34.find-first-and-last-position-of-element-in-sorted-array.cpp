/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    auto findBound = [&](bool isFirst) -> int {
      int left = 0, right = nums.size() - 1, bound = -1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
          bound = mid;
          if (isFirst) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      return bound;
    };
    int first = findBound(true);
    int last = findBound(false);
    return {first, last};
  }
};
// @lc code=end
