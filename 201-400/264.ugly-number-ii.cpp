/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to find the nth "ugly number," where an ugly number is a positive
 * integer whose only prime factors are 2, 3, or 5. The sequence starts with 1
 * (by convention), and each subsequent ugly number is the smallest number not
 * yet in the sequence that can be formed by multiplying a previous ugly number
 * by 2, 3, or 5.
 *
 * High-Level Summary:
 * ----
 * We use dynamic programming to generate ugly numbers in order. We maintain an
 * array of ugly numbers and three pointers (indices) for the next multiple of
 * 2, 3, and 5. At each step, we select the smallest candidate (from 2×, 3×, or
 * 5× the previous ugly numbers), add it to the list, and advance the
 * corresponding pointer(s). This ensures all ugly numbers are generated in
 * increasing order without duplicates.
 *
 * Time Complexity: O(n) — Each ugly number is generated once.
 * Space Complexity: O(n) — We store the first n ugly numbers.
 */

// @lc code=start
#include <algorithm> // Include algorithm for std::min
#include <vector>    // Include vector for dynamic array storage

class Solution {
public:
  int nthUglyNumber(int n) {
    // Edge case: If n is 1, return 1 directly (by definition)
    if (n == 1)
      return 1;

    // Create a vector to store the first n ugly numbers
    std::vector<int> ugly(n);
    ugly[0] = 1; // The first ugly number is always 1

    // Initialize three pointers for multiples of 2, 3, and 5
    int i2 = 0, i3 = 0, i5 = 0;

    // Next multiples for 2, 3, and 5
    int next2 = 2;
    int next3 = 3;
    int next5 = 5;

    // Generate ugly numbers from 2 to n
    for (int i = 1; i < n; ++i) {
      // Choose the smallest among next2, next3, next5
      int next_ugly = std::min({next2, next3, next5});
      ugly[i] = next_ugly;

      // Increment the pointer(s) whose multiple was used
      // This avoids duplicates (e.g., 6 can be 2×3 or 3×2)
      if (next_ugly == next2) {
        ++i2;
        next2 = ugly[i2] * 2; // Update next multiple of 2
      }
      if (next_ugly == next3) {
        ++i3;
        next3 = ugly[i3] * 3; // Update next multiple of 3
      }
      if (next_ugly == next5) {
        ++i5;
        next5 = ugly[i5] * 5; // Update next multiple of 5
      }
    }

    // The nth ugly number is at index n-1
    return ugly[n - 1];
  }
};
// @lc code=end
