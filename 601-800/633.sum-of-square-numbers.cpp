/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

/*
 * Brief Digested Understanding:
 * ----
 * The problem asks: Given a non-negative integer c, can you find two integers a
 * and b such that a^2 + b^2 = c? In other words, is c the sum of two perfect
 * squares? The task is to return true if such a pair exists, and false
 * otherwise. The key is to efficiently check all possible pairs (a, b) without
 * unnecessary work, especially since c can be as large as 2^31 - 1.
 *
 * High-Level Summary:
 * ----
 * The main idea is to use a two-pointer approach: one pointer (a) starts at 0
 * and the other (b) starts at the largest integer whose square is less than or
 * equal to c (i.e., sqrt(c)). We check if a^2 + b^2 equals c. If the sum is too
 * small, we increment a; if it's too large, we decrement b. This way, we
 * efficiently search all possible pairs without redundant checks. The algorithm
 * runs in O(sqrt(c)) time and uses O(1) extra space.
 */

// @lc code=start
#include <cmath> // For std::sqrt

class Solution {
public:
  // Main function to determine if c can be written as the sum of two squares
  bool judgeSquareSum(int c) {
    // Helper function to check if a number is a perfect square
    auto isPerfectSquare = [](long long n) -> bool {
      long long root = static_cast<long long>(std::sqrt(n));
      // Check if the square of the root equals n
      return root * root == n;
    };

    // Use two pointers: a starts at 0, b starts at sqrt(c)
    long long a = 0;
    long long b = static_cast<long long>(std::sqrt(c));

    // Loop while a does not exceed b
    while (a <= b) {
      long long sum = a * a + b * b; // Compute the sum of squares

      if (sum == c) {
        // Found a valid pair (a, b) such that a^2 + b^2 == c
        return true;
      } else if (sum < c) {
        // If the sum is too small, increment a to increase the sum
        ++a;
      } else {
        // If the sum is too large, decrement b to decrease the sum
        --b;
      }
    }
    // If no such pair is found, return false
    return false;
  }
};
// @lc code=end
