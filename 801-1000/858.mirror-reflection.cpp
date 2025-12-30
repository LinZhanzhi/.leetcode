/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */

/*
 * Brief Digested Understanding:
 * ----
 * The problem asks which "receptor" (numbered 0, 1, 2) in a square room a
 * laser beam will strike first if it starts in the southwest corner and
 * reflects around the room at a 45-degree angle, given the room's side length
 * (p) and an offset (q). In other words, as the beam bounces, we want to know
 * which corner with a receptor it hits first. The ray "wraps around" vertically
 * and horizontally, so over time, the up-and-right movement leads to a
 * repeating pattern. The challenge is to compute the first intersection without
 * simulation.
 *
 * Key constraints: 1 <= q <= p <= 1000; it’s always guaranteed the ray will
 * eventually hit a receptor.
 *
 * High-Level Summary:
 * ----
 * The core approach is to find when the ray exactly lands at a room's corner
 * with a receptor. To do this, observe that at each "pass" across the room
 * horizontally, the ray climbs vertically by "q". We find the Least Common
 * Multiple (LCM) of p and q: it tells us after how many "round trips" both the
 * top wall (vertical bounces) and right wall (horizontal bounces, i.e., step in
 * p's direction) are simultaneously reached. Specifically, the number of 'room
 * heights' traversed ("m" = LCM/p) tells us which wall the beam hits: even or
 * odd number of trips means it ends at a particular side/receptor. Based on m
 * and n (LCM/p, LCM/q respectively), we deduce which receptor is first met
 * through parity:
 * - If m is even & n is odd: Receptor 0 (top-left)
 * - If m is odd & n is odd: Receptor 1 (top-right)
 * - If m is odd & n is even: Receptor 2 (bottom-right)
 * (m,n both even can't happen here since the SW corner is not a receptor.)
 *
 * Time Complexity: O(log p + log q) due to GCD/LCM computation.
 * Space Complexity: O(1), only integer arithmetic.
 */

// @lc code=start

#include <numeric> // For std::gcd in C++17+. For C++11/14, use custom gcd.

class Solution {
public:
  // Helper function to compute Least Common Multiple
  int lcm(int a, int b) {
    // The LCM of two numbers is their product divided by GCD
    return a * b / std::gcd(a, b);
  }

  // Main function to find the first receptor met by the laser beam
  int mirrorReflection(int p, int q) {
    // Find the first time both vertical (p) and offset (q) align at a wall
    int l = lcm(p, q); // l is the smallest distance at which both align

    int m = l / p; // Number of room heights traversed (also number of wall hits
                   // vertically)
    int n =
        l /
        q; // Number of room widths traversed (number of steps in "q" direction)

    // Detailed explanation by parity:
    // - If m is even, the beam hits the left (west) wall; thus, receptor 0 if n
    // is odd,
    //   but 0 is only on the left wall at the top (see receptor assignment).
    // - If m is odd, the beam hits the right (east) wall; check if it is at the
    // top or bottom.
    //   If n is odd: it's at the top-right (receptor 1).
    //   If n is even: it's at the bottom-right (receptor 2).

    if (m % 2 == 0 && n % 2 == 1)
      return 0; // Top-left receptor
    else if (m % 2 == 1 && n % 2 == 1)
      return 1; // Top-right receptor
    else if (m % 2 == 1 && n % 2 == 0)
      return 2; // Bottom-right receptor
    // It should never reach here due to problem guarantees
    return -1;
  }
};

// @lc code=end
