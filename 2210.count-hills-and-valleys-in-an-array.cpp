/*
 * @lc app=leetcode id=2210 lang=cpp
 *
 * [2210] Count Hills and Valleys in an Array
 */

// @lc code=start
class Solution {
public:
  // Helper to find the closest non-equal neighbor to the left of index i
  int findLeftNeighbor(const vector<int> &nums, int i) {
    int l = i - 1;
    while (l >= 0 && nums[l] == nums[i])
      l--;
    return l;
  }

  // Helper to find the closest non-equal neighbor to the right of index i
  int findRightNeighbor(const vector<int> &nums, int i) {
    int n = nums.size();
    int r = i + 1;
    while (r < n && nums[r] == nums[i])
      r++;
    return r;
  }

  // Helper to check if nums[i] is a hill or valley given its left and right
  // neighbors
  bool isHillOrValley(const vector<int> &nums, int l, int i, int r) {
    return (nums[i] > nums[l] && nums[i] > nums[r]) ||
           (nums[i] < nums[l] && nums[i] < nums[r]);
  }

  int countHillValley(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    int i = 1;
    while (i < n - 1) {
      int l = findLeftNeighbor(nums, i);
      int r = findRightNeighbor(nums, i);
      if (l >= 0 && r < n) {
        if (isHillOrValley(nums, l, i, r)) {
          res++;
        }
      }
      i = r; // skip over equal values, as they are part of the same hill/valley
    }
    return res;
  }
};
// @lc code=end
