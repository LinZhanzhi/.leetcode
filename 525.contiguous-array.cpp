/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the length of the longest contiguous subarray in
 * a binary array (containing only 0s and 1s) where the number of 0s and 1s are
 * equal. In other words, we want the largest window in the array where the
 * count of 0s matches the count of 1s.
 *
 * High-Level Summary:
 * ----
 * The key insight is to treat 0s as -1s and 1s as +1s, and compute a running
 * sum (prefix sum) as we traverse the array. If the same running sum occurs at
 * two different indices, it means the subarray between those indices has an
 * equal number of 0s and 1s (because the net change is zero). We use a hash map
 * to record the first occurrence of each running sum, and for each new
 * occurrence, we check the distance to maximize the subarray length.
 *
 * Time Complexity: O(n), where n is the length of nums, since we traverse the
 * array once. Space Complexity: O(n), for storing the running sum indices in
 * the hash map.
 */

#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to find the maximum length of a contiguous subarray with
  // equal number of 0s and 1s
  int findMaxLength(vector<int> &nums) {
    // Helper function to compute the maximum length using prefix sum and hash
    // map
    return maxLengthWithEqualZeroOne(nums);
  }

private:
  // Helper function that encapsulates the main algorithm
  int maxLengthWithEqualZeroOne(const vector<int> &nums) {
    // Hash map to store the first occurrence index of each running sum
    // Key: running sum, Value: first index where this sum occurs
    unordered_map<int, int> sumIndexMap;
    // Initialize with sum 0 at index -1 to handle subarrays starting at index 0
    sumIndexMap[0] = -1;

    int maxLength = 0;  // To keep track of the maximum length found
    int runningSum = 0; // Running sum, treating 0 as -1 and 1 as +1

    // Iterate through the array
    for (int i = 0; i < nums.size(); ++i) {
      // Update running sum: treat 0 as -1, 1 as +1
      runningSum += (nums[i] == 0) ? -1 : 1;

      // If this running sum has been seen before, a subarray with equal 0s and
      // 1s exists
      if (sumIndexMap.find(runningSum) != sumIndexMap.end()) {
        // Calculate the length of the subarray between previous index and
        // current index
        int prevIndex = sumIndexMap[runningSum];
        int currLength = i - prevIndex;
        // Update maxLength if this subarray is longer
        if (currLength > maxLength) {
          maxLength = currLength;
        }
      } else {
        // If this running sum is seen for the first time, record its index
        sumIndexMap[runningSum] = i;
      }
    }
    // Return the maximum length found
    return maxLength;
  }
};
// @lc code=end
