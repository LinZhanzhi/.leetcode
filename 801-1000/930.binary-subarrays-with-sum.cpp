/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// Brief Digested Understanding:
// In this problem, we are given a binary array (only 0s and 1s) and an integer
// "goal" and we must count all possible *contiguous* subarrays whose sum equals
// the goal value. Since subarrays must be continuous sequences, the challenge
// is to efficiently count all the different intervals where their sum of
// elements equals goal, even if there are many such intervals due to zeros
// allowing "expansions" of the same sum.

// High-Level Summary:
// To solve this efficiently, we'll use a prefix sum and a hash map. As we
// iterate, we'll compute the running prefix sum. For each index, the map will
// track how many times we've seen each sum so far. For position i, we look for
// any previous prefix sums that, if subtracted from the current prefix sum,
// give "goal" (i.e., prefixSum[j] = currentSum - goal). Each such occurrence
// corresponds to a subarray [j, i] with sum == goal. We update the map as we
// advance. This algorithm runs in linear O(N) time and uses O(N) space for the
// hash map.
// We'll break the logic into helper functions for clarity and maintainability.
//
// NOTE: We'll #include <vector> and <unordered_map> since they are needed.

#include <unordered_map> // For efficient prefix sum counting with hash map.
#include <vector>        // To use std::vector for input array.

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to count subarrays with sum == goal
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    // Helper function: returns the number of subarrays with sum == goal using
    // prefix sum + hashmap
    return countSubarraysWithGivenSum(nums, goal);
  }

private:
  // Counts the number of subarrays whose sum equals the specified goal
  int countSubarraysWithGivenSum(const vector<int> &nums, int goal) {
    unordered_map<int, int> prefixSumCount; // Maps prefix sum value to the
                                            // number of times it has occurred
    prefixSumCount[0] = 1; // There is always one way to have sum 0 (empty
                           // prefix before first element)
    int currentSum = 0;    // The running prefix sum
    int answer = 0;        // Number of ways found so far

    // Iterate through array, updating prefix sum and answer at each step
    for (size_t i = 0; i < nums.size(); ++i) {
      currentSum += nums[i]; // Add the current element to prefix sum

      // Check: have we previously seen (currentSum - goal)? If so, each
      // occurrence of it marks a subarray ending here with sum == goal.
      if (prefixSumCount.count(currentSum - goal)) {
        answer += prefixSumCount[currentSum - goal];
        // The value represents the number of subarrays ending at previous
        // indices whose sums allow this subarray [j+1, i] to be sum == goal.
      }

      // Add/update the prefix sum count for the current sum
      prefixSumCount[currentSum]++;
    }

    // After full iteration, answer contains the total count
    return answer;
  }
};
// @lc code=end
