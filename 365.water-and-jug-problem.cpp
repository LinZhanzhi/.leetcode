/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given two jugs with capacities x and y liters, and we want to know if
 * we can measure exactly 'target' liters using only the allowed operations:
 * fill, empty, or pour between the jugs. The key is to determine if it's
 * possible to reach the target amount in either jug or in total, using any
 * sequence of these operations.
 *
 * The problem is fundamentally about whether the target amount can be formed by
 * combining multiples of x and y (with positive or negative coefficients),
 * given the constraints of the operations.
 */

/*
 * High-Level Summary:
 * ----
 * The solution is based on a classic result from number theory (Bézout's
 * identity): we can measure exactly 'target' liters if and only if target is a
 * multiple of the greatest common divisor (gcd) of x and y, and target does not
 * exceed the combined capacity (x + y).
 *
 * - If target > x + y, it's impossible (we can't hold that much water).
 * - If target == 0, it's always possible (do nothing).
 * - Otherwise, check if target % gcd(x, y) == 0.
 *
 * This approach is efficient: time complexity is O(log(min(x, y))) due to the
 * gcd calculation, and space complexity is O(1).
 */

// @lc code=start
class Solution {
public:
  // Helper function to compute the greatest common divisor (gcd) of two numbers
  int gcd(int a, int b) {
    // Use the Euclidean algorithm: gcd(a, b) = gcd(b, a % b)
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

  bool canMeasureWater(int x, int y, int target) {
    // If the target is greater than the total capacity, it's impossible
    if (target > x + y) {
      return false;
    }
    // If the target is zero, we can always measure it (by doing nothing)
    if (target == 0) {
      return true;
    }
    // If either jug has capacity equal to target, or their sum equals target,
    // it's possible
    if (x == target || y == target || x + y == target) {
      return true;
    }
    // Otherwise, check if target is a multiple of the gcd of x and y
    // This is based on Bézout's identity: ax + by = target has integer
    // solutions iff gcd(x, y) divides target
    int d = gcd(x, y);
    return (target % d == 0);
  }
};
/*
/*
 * Brief, Digested Understanding:
 * ----
 * The "Water and Jug Problem" asks whether it is possible to measure exactly
 * 'target' liters using two jugs with capacities 'x' and 'y', given that you
 * can fill, empty, or pour water between the jugs as many times as you like.
 * The core of the problem is to determine if, through a sequence of these
 * operations, you can reach a state where one or both jugs contain exactly
 * 'target' liters.
 */

/*
 * High-Level Summary: Bézout's Identity and Problem Formulation
 * ----
 * This problem can be formulated using Bézout's identity from number theory.
 * Bézout's identity states that for any integers a and b, there exist integers
 * m and n such that: m*a + n*b = d, where d is the greatest common divisor
 * (gcd) of a and b. In the context of the jug problem, a and b are the jug
 * capacities (x and y), and m and n represent the number of times you fill or
 * empty each jug (possibly negative, corresponding to emptying).
 *
 * The set of all measurable amounts using the two jugs is exactly the set of
 * all integer linear combinations of x and y (i.e., all numbers of the form
 * m*x + n*y). Therefore, you can measure 'target' if and only if:
 *   1. target is a multiple of gcd(x, y) (i.e., target % gcd(x, y) == 0)
 *   2. target does not exceed the total capacity (x + y)
 *
 * This is why the solution checks these two conditions. The time complexity is
 * O(log(min(x, y))) for the gcd calculation, and space complexity is O(1).
 */

/*
 * Example: Interpreting Bézout's Identity in the Jug Problem
 * ----
 * If either coefficient in Bézout's identity is negative, it means we are
 * emptying that jug; if positive, we are filling it. For example:
 *
 * Let x = 4, y = 6, target (z) = 8.
 * - GCD(4, 6) = 2
 * - 8 is a multiple of 2, so a solution is possible.
 * - Bézout's identity gives: (-1) * 4 + 2 * 6 = 8
 *   - Here, -1 means we empty the 4-gallon jug once,
 *     and 2 means we fill the 6-gallon jug twice.
 *
 * In practical terms, this corresponds to the following sequence:
 *   1. Fill the 6-gallon jug and pour into the 4-gallon jug (leaving 2 gallons
 * in the 6-gallon jug).
 *   2. Empty the 4-gallon jug.
 *   3. Pour the remaining 2 gallons from the 6-gallon jug into the 4-gallon
 * jug.
 *   4. Refill the 6-gallon jug and pour into the 4-gallon jug until it is full.
 *      (At this point, you have measured exactly 8 gallons in total.)
 *
 * This example illustrates how positive coefficients correspond to filling
 * jugs, and negative coefficients to emptying them, and how Bézout's identity
 * provides a constructive way to reach the target amount.
 */
// @lc code=end
