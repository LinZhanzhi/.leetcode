/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the length of the longest subsequence in a given
 * array where the differences between consecutive numbers strictly alternate
 * between positive and negative. This means, after a positive difference, the
 * next must be negative, and vice versa. The subsequence does not need to be
 * contiguous, but the order must be preserved. The goal is to maximize the
 * length of such a "wiggle" subsequence.
 */

/*
 * High-Level Summary:
 * ----
 * The optimal solution uses a greedy approach with two variables:
 *   - 'up': the length of the longest wiggle subsequence ending with an upward
 * difference.
 *   - 'down': the length of the longest wiggle subsequence ending with a
 * downward difference. As we iterate through the array, we update 'up' and
 * 'down' based on whether the current difference is positive or negative. This
 * approach ensures O(n) time and O(1) space complexity, as we only need to
 * track the last state, not the entire sequence.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring std::vector into the current namespace

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to find the length of the longest subsequence in an array where
 * the differences between consecutive numbers strictly alternate between
 * positive and negative. In other words, we want to count how many times the
 * sequence "wiggles" (switches from increasing to decreasing or vice versa),
 * and the subsequence does not need to be contiguous, but must preserve order.
 */

/*
 * High-Level Summary:
 * ----
 * This solution explicitly counts the number of times the sequence changes
 * direction (from increasing to decreasing or vice versa), which is the essence
 * of a "wiggle" effect. We first skip any initial repeated values, then
 * determine the initial direction (increasing or decreasing). As we iterate, we
 * increment our answer each time the direction flips, ensuring we only count
 * true wiggle points. This approach is greedy, O(n) time, and O(1) space.
 */

// @lc code=start
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    int n = nums.size();
    // Edge case: If the array has only one element, the longest wiggle
    // subsequence is 1.
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;

    int i = 0;
    // Skip initial repeated values, as they do not contribute to a wiggle.
    while ((i + 1 < n) && nums[i] == nums[i + 1])
      ++i;

    // If all elements are the same, the longest wiggle subsequence is 1.
    if (i == n - 1)
      return 1;

    // Determine the initial direction: true for increasing, false for
    // decreasing.
    bool increasing = nums[i + 1] > nums[i];
    int ans = 2; // At least two different numbers form the first wiggle.

    // Iterate through the array, starting from the first non-equal pair.
    for (; i + 1 < n; ++i) {
      // If the current direction is increasing and we find a decrease, it's a
      // wiggle.
      if (increasing && nums[i + 1] < nums[i]) {
        increasing = false; // Flip the direction to decreasing.
        ++ans;              // Count this wiggle.
      }
      // If the current direction is decreasing and we find an increase, it's a
      // wiggle.
      else if (!increasing && nums[i + 1] > nums[i]) {
        increasing = true; // Flip the direction to increasing.
        ++ans;             // Count this wiggle.
      }
      // If nums[i+1] == nums[i], do nothing, as equal values do not contribute
      // to a wiggle.
    }
    // The answer is the total number of wiggle points plus the initial element.
    return ans;
  }
};
// @lc code=end
