/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// Brief Digested Understanding:
// ----
// The problem asks if we can split an array of positive integers into exactly k
// groups (subsets), so that the sum of each group is the same. We have to use
// every number exactly once, and each group must have at least one number. The
// real crux is to assign numbers into k groups fairly, so that each subset has
// identical sum - not just splitting the array, but ensuring all pieces add up
// equally. With at most 16 items, this is a feasibility check that naturally
// hints at recursion or backtracking.

// High-Level Summary:
// ----
// The solution uses recursive backtracking to attempt to assign each number to
// one of k buckets, making sure no bucket's sum exceeds the required per-bucket
// target. First, we check if a fair split is mathematically possible
// (total must divide evenly by k). Sorting the array descending lets us try
// larger values first, pruning failures sooner. We use an in-place bool array
// to mark used numbers, and recursively try to fill one group at a time. Once a
// full bucket is matched, we recur to fill the next. If all k-1 buckets can be
// filled, the remaining numbers must fill the last. Complexity is O(k*2^n) in
// the worst case, since for each pick, we try bucket assignments, but with
// pruning and early-exit, it performs efficiently for upto 16 numbers.

// @lc code=start
#include <algorithm> // For std::sort
#include <vector>

using std::vector;

class Solution {
public:
  /**
   * Main function to determine if the nums array can be partitioned into k
   * equal sum subsets.
   * Arguments:
   *  - nums: input vector of positive integers
   *  - k: number of subsets to form
   * Returns:
   *  - true if partition possible, false otherwise
   */
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int n = nums.size();
    int total = 0;
    for (int num : nums)
      total += num;

    // If total isn't divisible by k, it's impossible.
    if (total % k != 0)
      return false;
    int target = total / k;

    // Sorting in descending order helps failure/pruning early:
    // If the largest item is bigger than target, it's impossible.
    std::sort(nums.rbegin(), nums.rend());
    if (nums[0] > target)
      return false;

    // Used[] helps us track which numbers have been assigned to a bucket.
    vector<bool> used(n, false);

    // Try to recursively fill k buckets, each of which must sum to target.
    return backtrack(nums, used, k, 0, 0, target);
  }

private:
  /**
   * Helper function to recursively assign numbers to buckets.
   * Arguments:
   *  - nums: sorted input numbers
   *  - used: bool vector, used[i] is true if nums[i] is already assigned
   *  - k: number of buckets left to fill
   *  - start: index in nums vector to try next (to dedupe and avoid repeats)
   *  - currSum: current bucket's sum so far
   *  - target: required sum per bucket
   * Returns:
   *  - true if it's possible to fill buckets as described, false otherwise
   */
  bool backtrack(const vector<int> &nums, vector<bool> &used, int k, int start,
                 int currSum, int target) {
    // If only one bucket left, remaining numbers together will form last
    // subset. (Because we've already checked divisibility and used all.)
    if (k == 1)
      return true;

    // When current bucket is full, start filling the next bucket.
    if (currSum == target)
      return backtrack(nums, used, k - 1, 0, 0, target);

    int n = nums.size();

    // Try every unused number, starting from 'start' index (to remove
    // symmetry).
    for (int i = start; i < n; ++i) {
      // Skip if already used.
      if (used[i])
        continue;

      // If adding nums[i] would exceed target, skip it.
      if (currSum + nums[i] > target)
        continue;

      // Mark as used and attempt to fill further.
      used[i] = true;
      // Recursively try to fill the rest.
      if (backtrack(nums, used, k, i + 1, currSum + nums[i], target))
        return true; // If we ever find a valid path, return true.

      // Backtrack: unmark the number, and try next possibility.
      used[i] = false;

      // If previous choice made currSum+nums[i]==target but failed,
      // and nums[i] == nums[i-1], we can skip same value for same role.
      while (i + 1 < n && nums[i] == nums[i + 1])
        ++i;
    }

    // If no valid selection, return false.
    return false;
  }
};
// @lc code=end
