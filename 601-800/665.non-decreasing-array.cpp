/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

/*
 * Brief Digested Understanding:
 * ----
 * The problem asks whether you can make a given array non-decreasing by
 * changing at most one element. A non-decreasing array means that every
 * element is less than or equal to the next one. You are allowed to change
 * only one value in the array, and you need to determine if this is enough
 * to fix any "drops" (where nums[i] > nums[i+1]) in the sequence.
 *
 * High-Level Summary:
 * ----
 * The main idea is to scan the array and count how many times a "drop"
 * (nums[i] > nums[i+1]) occurs. If more than one drop is found, it's
 * impossible to fix the array with a single modification, so we return
 * false. If at most one drop is found, we check if it's possible to fix
 * the drop by modifying either nums[i] or nums[i+1] without creating a new
 * drop elsewhere. We do this by checking the values before and after the
 * drop. The algorithm runs in O(n) time and O(1) space, as we only need to
 * scan the array once and use a few variables.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  // Main function to check if the array can be made non-decreasing
  bool checkPossibility(vector<int> &nums) {
    // Helper function to check if the array is non-decreasing
    auto isNonDecreasing = [](const vector<int> &arr) -> bool {
      for (size_t i = 0; i + 1 < arr.size(); ++i) {
        if (arr[i] > arr[i + 1]) {
          // Found a drop, so array is not non-decreasing
          return false;
        }
      }
      return true;
    };

    int n = nums.size();
    int count = 0; // To count the number of drops

    // Scan the array to find drops
    for (int i = 0; i + 1 < n; ++i) {
      if (nums[i] > nums[i + 1]) {
        count++;
        // If more than one drop, cannot fix with one modification
        if (count > 1)
          return false;

        // Try to fix the drop by modifying nums[i] or nums[i+1]
        // We need to check which modification is safe
        // Make a copy of the array to test modifications
        vector<int> temp(nums);

        // Option 1: Lower nums[i] to nums[i+1] (if possible)
        temp[i] = (i == 0) ? temp[i + 1] : std::max(temp[i - 1], temp[i + 1]);
        if (isNonDecreasing(temp))
          return true;

        // Option 2: Raise nums[i+1] to nums[i] (if possible)
        temp = nums; // Reset to original
        temp[i + 1] = (i + 2 == n) ? temp[i] : std::min(temp[i], temp[i + 2]);
        if (isNonDecreasing(temp))
          return true;

        // If neither modification works, return false
        return false;
      }
    }
    // If no more than one drop, array is already non-decreasing or can be fixed
    return true;
  }
};
// @lc code=end
