/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given an array of integers where each integer is between 1 and n (the
 * array's length), and each number appears either once or twice. Our goal is to
 * find all numbers that appear exactly twice in the array, and return them in a
 * result array.
 *
 * The challenge is to do this in linear time (O(n)) and with constant extra
 * space (not counting the output array).
 */

/*
 * High-Level Summary:
 * ----
 * The solution leverages the fact that the numbers are in the range [1, n] and
 * can use the input array itself for marking. For each number, we use its value
 * to index into the array (subtracting 1 for zero-based indexing). We mark the
 * number at that index as negative to indicate we've seen the value before. If
 * we encounter a number whose corresponding index is already negative, it means
 * we've seen it before, so it's a duplicate. This approach ensures O(n) time
 * and O(1) extra space.
 *
 * Time Complexity: O(n), since we traverse the array once.
 * Space Complexity: O(1) auxiliary space (excluding the output vector).
 */

#include <cstdlib> // Include cstdlib for std::abs
#include <vector>  // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    // Result vector to store the duplicates found
    vector<int> result;

    // Iterate through each number in the input array
    for (int i = 0; i < nums.size(); ++i) {
      // Get the absolute value of the current number
      // (since we may have already negated it earlier)
      int val = std::abs(nums[i]);
      // The index to check/mark is val - 1 (since array is 0-indexed)
      int idx = val - 1;

      // If the number at index 'idx' is already negative,
      // it means we've seen 'val' before, so it's a duplicate
      if (nums[idx] < 0) {
        result.push_back(val);
      } else {
        // Otherwise, mark the number at index 'idx' as negative
        // to indicate we've seen 'val' once
        nums[idx] = -nums[idx];
      }
    }

    // The result vector contains all numbers that appeared twice
    return result;
  }
};
// @lc code=end
