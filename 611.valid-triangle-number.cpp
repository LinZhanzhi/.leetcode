/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// Brief, Digested Understanding:
//
// The problem asks us to count how many unique triplets (i, j, k) in the array
// can form the sides of a triangle. For three numbers to form a triangle, the
// sum of any two sides must be greater than the third side. We need to find all
// such triplets in the array.
//
// High-Level Summary:
//
// The solution sorts the array first, which allows us to efficiently check the
// triangle condition using a two-pointer approach. For each possible largest
// side (nums[k]), we look for pairs (nums[i], nums[j]) with i < j < k such that
// nums[i] + nums[j] > nums[k]. By sorting, we can use two pointers to count all
// valid pairs for each k in O(n^2) time. The overall time complexity is O(n^2),
// and space complexity is O(1) (ignoring the sort).
//
// The code is modularized with helper functions for clarity and educational
// purposes.

#include <algorithm> // Include algorithm for std::sort
#include <vector>    // Include vector for using std::vector

using std::vector;

class Solution {
public:
  // Main function to count the number of valid triangle triplets
  int triangleNumber(vector<int> &nums) {
    // Sort the array to make it easier to apply the triangle inequality
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    int count = 0;

    // Iterate over each possible largest side (nums[k])
    for (int k = n - 1; k >= 2; --k) {
      // For each k, count valid pairs (i, j) with i < j < k
      count += countValidPairs(nums, k);
    }
    return count;
  }

private:
  // Helper function to count valid (i, j) pairs for a given k
  int countValidPairs(const vector<int> &nums, int k) {
    int count = 0;
    int i = 0;     // Start pointer
    int j = k - 1; // End pointer (just before k)

    // Use two pointers to find all pairs (i, j) such that nums[i] + nums[j] >
    // nums[k]
    while (i < j) {
      // If the sum is greater than nums[k], all pairs between i and j are valid
      if (nums[i] + nums[j] > nums[k]) {
        // All pairs (i, i+1, ..., j-1, j) with this j are valid
        count += (j - i);
        // Move the end pointer left to check for more pairs
        --j;
      } else {
        // If not valid, move the start pointer right to increase the sum
        ++i;
      }
    }
    return count;
  }
};
// @lc code=end
