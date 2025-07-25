/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */

// @lc code=start
class Solution {
public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    int n = arr.size(); // Get the size of the input array
    int res = 0;        // This will store the final result

    // Iterate through each element in the array
    for (int i = 0; i < n; ++i) {
      // The number of ways to choose a subarray that includes arr[i]:
      // - There are (i + 1) choices for the starting index (from 0 to i)
      // - There are (n - i) choices for the ending index (from i to n-1)
      int left = i + 1;
      int right = n - i;

      // Only consider subarrays of odd length.
      // For each subarray including arr[i], if its length is odd, it
      // contributes arr[i] to the sum. The number of odd-length subarrays
      // including arr[i] is calculated as follows:
      // For each subarray containing arr[i], the total number is left * right.
      // Half of these (rounded up) will be of odd length, since subarrays
      // alternate between odd and even lengths.
      int odd = ((left * right) + 1) / 2;

      // Add the contribution of arr[i] in all odd-length subarrays it is part
      // of
      res += arr[i] * odd;
    }
    // Return the total sum of all odd-length subarrays
    return res;
  }
};
// @lc code=end
