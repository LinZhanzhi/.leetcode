/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to find the nth "super ugly number," which is a positive integer
 * whose only prime factors are from a given list of primes. The sequence always
 * starts with 1, and each subsequent number is the smallest number not yet in
 * the sequence that can be formed by multiplying a previous super ugly number
 * by one of the primes. We need to efficiently generate this sequence up to the
 * nth element.
 *
 * High-Level Summary:
 * ----
 * We use a dynamic programming approach similar to the classic "Ugly Number II"
 * problem. We maintain an array of the first n super ugly numbers, starting
 * with 1. For each prime, we keep a pointer (index) to track which super ugly
 * number to multiply next. At each step, we select the minimum among all
 * possible next candidates (current super ugly number at each pointer times its
 * corresponding prime), add it to the sequence, and advance the pointers for
 * any primes that produced this minimum. This ensures the sequence is strictly
 * increasing and contains no duplicates.
 *
 * Time Complexity: O(n * k), where n is the target index and k is the number of
 * primes. Space Complexity: O(n + k), for the super ugly numbers array and the
 * pointers.
 */

#include <algorithm> // Include algorithm for std::min
#include <vector>    // Include vector for dynamic arrays

using std::vector;

// @lc code=start
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    // The array to store the first n super ugly numbers.
    // ugly[0] is always 1 by definition.
    vector<int> ugly(n, 1);

    int k = primes.size(); // Number of primes

    // idx[i] points to the current position in ugly[] for primes[i]
    // It tells us which ugly number to multiply by primes[i] next.
    vector<int> idx(k, 0);

    // next_multiple[i] stores the next candidate for each prime:
    // next_multiple[i] = ugly[idx[i]] * primes[i]
    vector<long> next_multiple(k);
    for (int i = 0; i < k; ++i) {
      next_multiple[i] =
          primes[i]; // Initially, all primes * ugly[0] (which is 1)
    }

    // Generate ugly numbers from 1 to n-1 (since ugly[0] is already 1)
    for (int i = 1; i < n; ++i) {
      // Find the minimum among all next multiples
      long next_ugly = next_multiple[0];
      for (int j = 1; j < k; ++j) {
        if (next_multiple[j] < next_ugly) {
          next_ugly = next_multiple[j];
        }
      }
      ugly[i] = static_cast<int>(next_ugly); // Store the next super ugly number

      // Advance all pointers whose next_multiple equals next_ugly
      // This handles duplicates (e.g., 6 = 2*3 = 3*2)
      for (int j = 0; j < k; ++j) {
        if (next_multiple[j] == next_ugly) {
          idx[j]++; // Move pointer forward for this prime
          // Update the next candidate for this prime
          // Use long to avoid integer overflow
          next_multiple[j] = static_cast<long>(ugly[idx[j]]) * primes[j];
        }
      }
    }

    // The nth super ugly number is at index n-1 (since we started from 0)
    return ugly[n - 1];
  }
};
// @lc code=end
