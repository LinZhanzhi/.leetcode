/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */

// Brief Digested Understanding:
// ----
// In this problem, we are given a strictly increasing sorted array of unique
// primes (which always starts with 1). The challenge is to select distinct i
// and j indices (i < j) from arr, such that we form all unique proper
// fractions arr[i]/arr[j], sort these in ascending order of their decimal
// values, and find the numerator and denominator for the k-th smallest
// fraction in this list. The constraints and input size mean that brute force
// approaches are too slow, so we must avoid explicitly generating and sorting
// all O(n^2) possible fractions. Instead, we need an efficient way to zoom in
// on the correct fraction using math and properties of sorted arrays.
//
// Key constraints to remember: all numbers are unique, strictly increasing,
// and always primes (though primality is not otherwise relevant). Indices i
// and j cannot be equal, and i must be less than j (so strictly proper
// fractions, no repeats, and all less than 1).

// High-Level Summary:
// ----
// The essence of our solution is to use binary search over possible fraction
// values (between 0 and 1) to efficiently "count" how many fractions are less
// than or equal to a test value. At every binary search iteration, we sweep
// through denominators using the two-pointer pattern, leveraging the sorted
// array to find--for each possible denominator--how many valid numerators
// produce a fraction <= our guess (mid). Simultaneously, we track the
// largest fraction encountered that still does not exceed this mid value.
// When we count at least k fractions <= mid, we know our target lies at or
// below mid, so we adjust our search range accordingly, updating our best
// candidate as we go. When the range converges sufficiently, we output the
// last best numerator and denominator found. All logic is modularized: the
// counting and fraction-tracking is kept in its own helper. The algorithm
// leverages properties of sorted arrays and careful cross-multiplication to
// avoid floating-point inaccuracies when comparing fractions. Its time
// complexity is O(n log W), where n is the array length and W is the precision
// (about 40 iterations for 1e-9 accuracy), and space complexity is O(1).

#include <algorithm> // For std::max
#include <vector>    // For std::vector

using std::max;
using std::pair;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the k-th smallest prime fraction.
  // Receives a sorted unique list of primes `arr` and a target k.
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n = arr.size(); // Number of elements in the input array.

    // Helper variables to keep track of the "best" valid fraction found during
    // search.
    int best_num = 0; // Numerator of the current best (<= mid) fraction.
    int best_den = 1; // Denominator of the current best (<= mid) fraction.

    // The search interval for fraction values: all fractions are in (0, 1).
    double left = 0.0, right = 1.0;

    // Helper function:
    // For a given double value `x`, counts how many fractions arr[i]/arr[j] <=
    // x (i < j), and updates best_num and best_den to the largest such fraction
    // not exceeding x.
    auto count_leq = [&](double x) -> int {
      int count = 0; // Number of fractions <= x found so far.
      best_num = 0;  // Reset best numerator for this call.
      best_den = 1;  // Reset best denominator.

      int i = -1; // Pointer for numerators. Start at -1 so i+1 == 0 at entry.

      // For each possible denominator (arr[j]), loop.
      for (int j = 1; j < n; ++j) {
        // Move numerator pointer i as far as arr[i+1]/arr[j] <= x (while
        // ensuring i+1 < j). We check arr[i+1] <= arr[j] * x to avoid float
        // division.
        while (i + 1 < j && static_cast<double>(arr[i + 1]) <= arr[j] * x) {
          ++i;
        }
        // After this, for denominator arr[j], all numerators arr[0..i] create a
        // valid fraction.
        if (i >= 0) {
          // Among these, arr[i]/arr[j] is the largest <= x for this j.
          // If this is the largest so far, update.
          // Cross-multiply for comparison to avoid float precision errors:
          // Compare: best_num/best_den < arr[i]/arr[j]  <=> best_num * arr[j] <
          // best_den * arr[i]
          if (best_num * arr[j] < best_den * arr[i]) {
            best_num = arr[i];
            best_den = arr[j];
          }
        }
        // Add to count: all (i+1) valid numerators for this denominator.
        count += (i + 1);
      }
      return count; // How many fractions arr[i]/arr[j] <= x
    };

    double eps = 1e-9; // Binary search stops when the search interval is
                       // smaller than eps.
    while (right - left > eps) {
      double mid = (left + right) / 2.0; // Midpoint fraction to check.
      int cnt = count_leq(mid); // Count fractions <= mid, and track the best.

      if (cnt < k) {
        // Not enough fractions ≤ mid: need to look for larger ones, so move
        // left up.
        left = mid;
      } else if (cnt == k) {
        return {best_num, best_den};
      } else {
        // At least k fractions ≤ mid: k-th smallest is ≤ mid, so move right
        // down and keep current "best" fraction found so far (for possible
        // answer).
        right = mid;
      }
    }
    // After binary search, best_num/best_den is the fraction that was k-th in
    // sorted order.
    return {best_num, best_den};
  }
};

/*
 * For illustration, we'll walk through the code with:
 *   Input:  arr = [1, 2, 3, 5],  k = 3
 *   Output: [2, 5]
 * We will show major intermediate states (fraction counts, best candidate,
 * and left/right bounds) for a few binary search steps via in-code "sample run"
 * comments.
 *
 * Time: O(n log(denom)), where n = arr.size(). Space: O(1) auxiliary.
 */

// Sample illustration for Input: arr = [1,2,3,5], k = 3

// Example for a few binary search steps to illustrate (rounded, conceptual):
// left = 0.0, right = 1.0
// mid = 0.5
//   count_leq(0.5) counts: 1/5, 1/3, 2/5, 1/2  (so count=4)
//   best fraction <= 0.5 is 2/5
// count=4 >= k=3 -> right = 0.5
// mid = 0.25
//   count_leq(0.25): only 1/5 (0.2) <= 0.25, so count=1
//   best is 1/5
// count=1 < k, so left = 0.25
// mid = 0.375
//   count_leq(0.375): 1/5, 1/3 (so count=2)
// left = 0.375
// mid = 0.4375
//   count: 1/5, 1/3, 2/5 (2/5=0.4 <= 0.4375), so count=3
// now k=3 found; so the answer is the last best fraction recorded <= mid, which
// is 2/5.
//
// Therefore, result is [2,5].

// @lc code=end
