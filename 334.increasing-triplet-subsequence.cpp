/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to determine if there exists any three indices (i, j, k)
 * in the array such that i < j < k and the values at those indices form a
 * strictly increasing sequence (nums[i] < nums[j] < nums[k]). In other words,
 * we want to know if there is any increasing subsequence of length 3 in the
 * array.
 *
 * High-Level Summary:
 * ----
 * The optimal solution uses a greedy approach with two variables to track the
 * smallest and second smallest values seen so far as we iterate through the
 * array. If we find a number greater than both, we know an increasing triplet
 * exists. This approach only requires a single pass (O(n) time) and constant
 * space (O(1)), which is efficient even for large arrays.
 *
 * Time Complexity: O(n), where n is the length of nums.
 * Space Complexity: O(1), since we only use a fixed number of variables.
 *
 */
/*
/*
 * Subtlety in the Greedy Algorithm's Index Order:
 * ----
 * A common concern is that when we update 'first' (the smallest value so far),
its index
 * becomes the current index, which could actually be *after* the index of the
current 'second'
 * (the second smallest value so far). This means that, at some point, 'first'
and 'second'
 * may not satisfy i < j (where i is the index of 'first', j is the index of
'second').
 *
 * Why does the algorithm still work?
 *
 * - The key is that we are always searching for a valid triplet in a single
left-to-right pass.
 * - When we update 'first', we are essentially "resetting" our search for a
new, better starting
 *   point for a triplet. Any previous 'second' that was found before this new
'first' is now
 *   irrelevant, because a valid triplet must have i < j < k.
 * - If 'second' was set before the current 'first', it will be overwritten the
next time we find
 *   a number greater than the new 'first' (since we only update 'second' if num
> first).
 * - The algorithm only returns true when it finds a number greater than both
'first' and 'second'
 *   *after* both have been set, which guarantees the indices are in increasing
order (since we
 *   process the array left to right).
 *
 * In summary: Even though 'first' and 'second' may not always have i < j at
every step, the
 * algorithm ensures that when a valid triplet is found, the three numbers are
encountered in
 * order (i < j < k) during the scan. Any "out-of-order" updates are harmless,
because only the
 * most recent, valid candidates for 'first' and 'second' are used to detect a
triplet.
 *
 * Example:
 *   nums = [2, 1, 5, 0, 4, 6]
 *   - first = 2 (i=0)
 *   - first = 1 (i=1)
 *   - second = 5 (i=2, since 5 > 1)
 *   - first = 0 (i=3, since 0 < 1)
 *   - second = 4 (i=4, since 4 > 0 and 4 < 5)
 *   - 6 > 0 and 6 > 4 (i=5), so we have a triplet at indices 3, 4, 5.
 *
 * At no point does 'second' get updated with a value that comes before the
current 'first'
 * in the array, because we only update 'second' when num > first. Thus, the
order of indices
 * is always preserved.
 *
 * In summary: The algorithm is correct because it only considers increasing
subsequences
 * where the elements (and thus their indices) are in strictly increasing order
as we scan
 * from left to right. The updates to 'first' and 'second' always reflect the
most promising
 * candidates for the first and second elements of a triplet, and the final
check ensures
 * the third element comes after both.
 */
/*
/*
 * Brief, Digested Understanding:
 * ----
 * The core of this problem is to determine if there exists a strictly
increasing subsequence
 * of length three (i.e., three indices i < j < k such that nums[i] < nums[j] <
nums[k]) in the
 * given array. The challenge is to do this efficiently, in a single pass and
with constant space,
 * without explicitly tracking all possible subsequences or their indices.
 *
 * The subtlety is that, as we scan the array, the variables tracking the
"smallest" and
 * "second smallest" values may not always correspond to the earliest indices.
However, the
 * algorithm is designed so that a valid triplet is only detected when the order
of indices
 * is correct, because we only update the "second smallest" after the "smallest"
has been
 * established, and we only return true when we find a value greater than both.
 *
 * The two main scenarios before finding a value larger than the current "second
smallest" are:
 *   1. If we just updated the "smallest" (first), its index is after the
"second smallest" (second),
 *      so this "smallest" cannot form a valid triplet with the current "second
smallest".
 *      The legitimate triplet would have been with the previous "smallest"
(which was less than
 *      the "second smallest" and had a smaller index), the "second smallest",
and the new value.
 *   2. If we only updated the "second smallest", then the "smallest" still has
an earlier index,
 *      and the index constraint (i < j < k) is satisfied when we find a value
greater than both.
 *
 * Thus, the algorithm always ensures that when a valid triplet is found, the
indices are in
 * increasing order, and the values are strictly increasing.
 *
 * High-Level Summary:
 * ----
 * The solution uses a greedy approach with two variables:
 *   - 'first' tracks the smallest value seen so far.
 *   - 'second' tracks the smallest value greater than 'first' seen so far.
 * As we iterate through the array:
 *   - If the current number is less than or equal to 'first', we update
'first'.
 *   - Else if it's less than or equal to 'second', we update 'second'.
 *   - Else, we've found a number greater than both, so an increasing triplet
exists.
 * This approach guarantees O(n) time and O(1) space, and the logic ensures the
index order is correct.
 */
*/

#include <vector>      // Include the vector header to use std::vector
    using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  // This function checks if there exists an increasing triplet subsequence in
  // nums.
  bool increasingTriplet(vector<int> &nums) {
    // We use two variables to keep track of the smallest and second smallest
    // values found so far.
    int first = INT_MAX; // The smallest value seen so far (potential nums[i])
    int second =
        INT_MAX; // The second smallest value seen so far (potential nums[j])

    // Iterate through each number in the array
    for (int num : nums) {
      if (num <= first) {
        // If current number is smaller than or equal to 'first', update
        // 'first'. This means we have found a new minimum candidate for the
        // first element of the triplet.
        first = num;
      } else if (num <= second) {
        // If current number is greater than 'first' but smaller than or equal
        // to 'second', update 'second'. This means we have a new candidate for
        // the second element.
        second = num;
      } else {
        // If we reach here, it means num > first and num > second,
        // so we have found a triplet: first < second < num.
        return true;
      }
      // At each step, 'first' is the smallest so far, 'second' is the next
      // smallest after 'first'.
    }
    // If we finish the loop without returning, no increasing triplet exists.
    return false;
  }
};
// @lc code=end
