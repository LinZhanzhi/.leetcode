/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// ====================
// Brief Digested Understanding:
// ====================
// The core idea in this problem is to determine the *smallest integer eating
// speed (k)* such that Koko can finish every pile of bananas within a given
// number of hours (h). Each hour, she selects a pile and eats up to k bananas—
// possibly finishing the pile if it contains fewer than k bananas. We want to
// find this minimum k efficiently, especially because the pile values and hour
// constraints can be very large. The problem boils down to efficiently finding
// the lowest k so that the sum over all piles of ceil(pile / k) is <= h.

// ====================
// High-Level Summary:
// ====================
// We solve this by using binary search on possible eating speeds (k)—from 1 to
// the largest pile size. For any candidate k, we can check feasibility by
// summing over all piles the number of hours required to finish that pile
// (which is ceil(pile / k) per pile), and comparing the total to h. To avoid
// overflow and guarantee correctness for very large pile sizes and h, we use
// 'long long' (instead of 'int') for all accumulation and midpoint arithmetic.
// The binary search narrows down to the smallest feasible k by testing each
// midpoint and tightening the bounds. We modularize with a helper function to
// encapsulate the feasibility check.
// Time Complexity: O(N log M), where N is the number of piles and M is the
// maximum pile size. Space Complexity: O(1) beyond input.

#include <algorithm> // For std::max to find maximum pile size
#include <vector>    // For std::vector to store piles of bananas

using std::vector;

class Solution {
public:
  // Main function: computes the minimum eating speed k
  int minEatingSpeed(vector<int> &piles, int h) {
    // Helper function: Returns true if Koko can eat all bananas at speed 'k'
    auto canFinish = [&](long long k) -> bool {
      // Use long long to prevent integer overflow when summing large values
      long long totalHours = 0;
      for (const int pile : piles) {
        // Calculate hours needed for each pile at speed k (with ceiling)
        // We do (pile + k - 1) / k to achieve integer ceiling division
        totalHours += (pile + k - 1) / k;
        // No casting to double, keeps precision and avoids floating point error
        // Avoids integer overflow since both pile and k are promoted to long
        // long
        if (totalHours > h) {
          // Early break: If we've already exceeded h, don't keep accumulating
          return false;
        }
      }
      // Feasible if total hours spent is less than or equal to allowed hours
      return totalHours <= h;
    };

    // Find upper bound for k: the largest pile size
    int maxPile = 0;
    for (const int pile : piles) {
      if (pile > maxPile)
        maxPile = pile;
    }

    // We use long long here to prevent potential overflow in 'mid' calculation
    long long left = 1;        // Minimum possible speed
    long long right = maxPile; // Maximum necessary speed
    int answer = maxPile;      // Store the minimal feasible k found

    while (left <= right) {
      // Prevent mid-point overflow by using long long
      long long mid = left + (right - left) / 2;

      if (canFinish(mid)) {
        // If we can finish with speed 'mid', try to minimize k further
        answer = static_cast<int>(mid); // Safe since mid <= maxPile (int)
        right = mid - 1;
      } else {
        // Otherwise, we need to increase the eating speed
        left = mid + 1;
      }
    }
    return answer; // The smallest k that allows Koko to finish within h hours
  }
};

// @lc code=end
