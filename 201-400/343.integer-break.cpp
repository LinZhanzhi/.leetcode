/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to split a given integer n (where n >= 2) into at least
 * two positive integers such that their sum is n, and the product of these
 * integers is as large as possible. We need to find and return this maximum
 * product. For example, for n = 10, splitting as 3 + 3 + 4 gives the product
 * 3*3*4 = 36, which is the maximum.
 */

/*
 * High-Level Summary:
 * ----
 * The optimal way to maximize the product is to break n into as many 3's as
 * possible, because 3*3 > 2*2*2 and 3*2 > 4*1, etc. If after dividing by 3, the
 * remainder is 1, it's better to use two 2's instead of a 3 and a 1 (since 2*2
 * > 3*1). For small n (n = 2 or 3), the answer is n-1, since we must split into
 * at least two numbers. The algorithm is greedy and runs in O(1) time for each
 * n, with O(1) space.
 */

// @lc code=start
class Solution {
public:
  int integerBreak(int n) {
    // For n = 2 or 3, the only way to split is into 1+1 or 2+1, and the product
    // is n-1, since we must split into at least two positive integers.
    if (n == 2)
      return 1; // 1+1 = 2, 1*1 = 1
    if (n == 3)
      return 2; // 2+1 = 3, 2*1 = 2

    // Calculate how many times we can use 3 in the decomposition.
    // This is because breaking n into as many 3's as possible maximizes the
    // product.
    int num_3 = n / 3;     // Number of 3's we can use
    int remainder = n % 3; // What's left after using as many 3's as possible

    // If the remainder is 1, it's better to use two 2's instead of a 3 and a 1,
    // because 2*2 = 4 > 3*1 = 3. So, we reduce one 3 and make the remainder 4.
    if (remainder == 1) {
      num_3 -= 1;    // Use one less 3
      remainder = 4; // Use two 2's instead of 3 and 1
    } else if (remainder == 0) {
      // If there's no remainder, set it to 1 so it doesn't affect the product.
      remainder = 1;
    }
    // If remainder is 2, we just multiply by 2 at the end.

    // Compute the final product: 3^num_3 * remainder
    // Use pow from <cmath> to compute 3^num_3.
    // Note: pow returns double, so cast to int for integer result.
    return static_cast<int>(pow(3, num_3)) * remainder;
  }
};

/*
/*
 * Detailed Mathematical Proof: Why Breaking into 3's Maximizes the Product
 * ----
 * The core claim is: For any integer n >= 5, breaking off a 3 (i.e., using 3
and n-3)
 * gives a product at least as large as not breaking, i.e., 3*(n-3) >= n.
 *
 * Let's prove this:
 *
 * 1. Consider splitting n into two positive integers: 3 and (n-3).
 *    The product is: P = 3 * (n - 3)
 *
 * 2. We want to show: 3 * (n - 3) >= n, for n >= 5.
 *
 *    Expand:
 *      3 * (n - 3) >= n
 *      3n - 9 >= n
 *      3n - n >= 9
 *      2n >= 9
 *      n >= 4.5
 *
 *    Since n is an integer and n >= 5, this inequality always holds for n >= 5.
 *
 * 3. Why is breaking into 3's optimal?
 *    - Suppose we break n into k equal parts: n = x + x + ... + x (k times), so
x = n/k.
 *    - The product is maximized when all parts are as close as possible to the
mathematical constant e (~2.718).
 *    - Since we must use integers, the best choices are 2 and 3.
 *    - For n >= 5, using as many 3's as possible gives a higher product than
using 2's or larger numbers.
 *      - For example, 2*2*2 = 8 < 3*3 = 9 for n=6.
 *      - For n=7: 3*2*2 = 12, 3*4 = 12, 2*2*3 = 12, all equal, but for larger
n, more 3's win.
 *    - Using 4 or higher as a part is suboptimal:
 *      - 2*2 = 4, but 3*1 = 3 < 4, so for n=4, 2*2 is best.
 *      - For n=5: 3*2 = 6 > 2*2*1 = 4, so 3's are better.
 *      - For n=6: 3*3 = 9 > 2*2*2 = 8.
 *    - In general, for n >= 5, repeatedly breaking off 3's maximizes the
product.
 *
 * 4. Special handling for remainders:
 *    - If after breaking off 3's, the remainder is 1, it's better to use two
2's instead of 3 and 1:
 *      - 3*1 = 3, but 2*2 = 4.
 *    - So, if n % 3 == 1, we use one less 3 and two 2's.
 *
 * Summary:
 *   - For n >= 5, breaking off as many 3's as possible (with the above
adjustment for remainder 1)
 *     always yields the maximum product.
 */

/*
/*
 * Brief, Digested Understanding:
 * ----
 * To maximize the product of numbers that sum to N (where N > 1), we want to
break N into a set of positive integers whose product is as large as possible.
The key is to decide whether breaking N into two or more parts gives a higher
product than keeping it whole, and if so, what those parts should be. We use
mathematical reasoning to determine the best way to split N, focusing on
maximizing the product at each step.
 *
 * High-Level Summary:
 * ----
 * First, we consider breaking N into two integer factors, x and N-x, and
analyze the product f = x * (N-x). The product is maximized when x is as close
as possible to N/2. For integer values, the maximum is (N/2)*(N/2) if N is even,
or (N-1)/2 * (N+1)/2 if N is odd. We compare this product to N itself: if the
product is greater than or equal to N, it's beneficial to break N. This leads to
the conclusion that for N >= 4 (even) or N >= 5 (odd), breaking is better.
Therefore, the optimal factors in the final product should be 2 or 3, since
larger factors can be broken down for a better product. Furthermore, using as
many 3's as possible yields the highest product, with at most three 2's in the
optimal decomposition. This is because, for example, 3*3 > 2*2*2 for N=6. Thus,
the best strategy is to use as many 3's as possible, and use 2's only when
necessary.
 */
/*
 * Step-by-step Mathematical Reasoning:
 * ----
 * 1. Consider breaking N into two factors: x and N-x.
 *    - The product is f = x * (N - x).
 *    - This function is maximized when x = N/2.
 *    - For integer N:
 *        - If N is even: max product = (N/2) * (N/2)
 *        - If N is odd:  max product = (N-1)/2 * (N+1)/2
 * 2. Compare the product to N itself:
 *    - For even N: (N/2)*(N/2) >= N  =>  N >= 4
 *    - For odd N:  (N-1)/2 * (N+1)/2 >= N  =>  N >= 5
 *    - So, for N >= 4 (even) or N >= 5 (odd), breaking N increases the product.
 * 3. This means that in the final decomposition, all factors should be less
 * than 4.
 *    - The only candidates are 1, 2, and 3.
 *    - Using 1 is suboptimal (since multiplying by 1 doesn't increase the
 * product), so we avoid 1.
 *    - Therefore, the best factors are 2 and 3.
 * 4. Why use as many 3's as possible?
 *    - For N=6: 3*3 = 9, but 2*2*2 = 8, so using more 3's gives a higher
 * product.
 *    - In general, the more 3's we use, the larger the product, except for a
 * few small cases where 2's are needed to avoid a leftover 1.
 *    - The optimal product contains as many 3's as possible, with at most three
 * 2's.
 */
// @lc code=end
