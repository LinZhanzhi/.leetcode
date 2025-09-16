/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /*
    This algorithm uses binary search to find a peak element in the array.
    A peak element is defined as an element that is strictly greater than its
    neighbors.

    A key enabler of this algorithm is the rule that you may imagine nums[-1] =
    nums[n] = -∞, where n is the length of the array. In other words, an element
    is always considered to be strictly greater than a neighbor that is outside
    the array. This ensures that the first and last elements can also be peaks
    if they are greater than their only neighbor.

    The correctness of this algorithm is based on the following observations:

    - At each step, we compare nums[mid] and nums[mid + 1].
    - If nums[mid] > nums[mid + 1], then there must be a peak on the left side
    (including mid), because either nums[mid] is a peak, or there is a higher
    value to the left. So, we move the right pointer to mid.
    - If nums[mid] < nums[mid + 1], then there must be a peak on the right side
    (excluding mid), because the slope is increasing, so a peak must exist
    further right. So, we move the left pointer to mid + 1.
    - The loop continues until left == right, at which point left (or right) is
    a peak index.

    This works because the array ends are considered to have -infinity values,
    so there is always at least one peak, and the binary search always moves
    towards a peak. The time complexity is O(log n).
  */
  int findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[mid + 1]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
// @lc code=end
