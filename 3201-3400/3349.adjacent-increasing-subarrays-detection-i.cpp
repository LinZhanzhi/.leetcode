/*
 * @lc app=leetcode id=3349 lang=cpp
 *
 * [3349] Adjacent Increasing Subarrays Detection I
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  // Main function to check for two adjacent strictly increasing subarrays of
  // length k
  bool hasIncreasingSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    if (!isValidInput(n, k)) {
      return false;
    }
    // For k == 1, every single element is a strictly increasing subarray of
    // length 1, so we just need to check if there are at least two adjacent
    // subarrays of length 1, which is always true if n >= 2.
    if (k == 1) {
      return n >= 2;
    }
    for (int i = 0; i <= n - 2 * k; ++i) {
      if (isStrictlyIncreasing(nums, i, k) &&
          isStrictlyIncreasing(nums, i + k, k)) {
        return true;
      }
    }
    return false;
  }

private:
  // Checks if the input size and k are valid for the problem constraints
  bool isValidInput(int n, int k) { return k >= 1 && n >= 2 * k; }

  // Checks if the subarray nums[start, start + k) is strictly increasing
  bool isStrictlyIncreasing(const vector<int> &nums, int start, int k) {
    if (k == 1)
      return true;
    for (int i = start + 1; i < start + k; ++i) {
      if (nums[i] <= nums[i - 1]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
