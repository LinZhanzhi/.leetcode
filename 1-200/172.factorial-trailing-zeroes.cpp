/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

/*
  Proof of correctness (mathematical explanation):

  The number of trailing zeroes in n! (n factorial) is determined by the number
  of times 10 divides n!. Since 10 = 2 * 5, and there are always more factors of
  2 than 5 in n!, the number of trailing zeroes is equal to the number of times
  5 divides n!.

  For each integer k from 1 to n:
    - Every multiple of 5 contributes at least one factor of 5.
    - Every multiple of 25 (= 5^2) contributes an extra factor of 5.
    - Every multiple of 125 (= 5^3) contributes yet another factor of 5, and so
  on.

  Therefore, the total number of factors of 5 in n! is:
    floor(n/5) + floor(n/25) + floor(n/125) + ... (until n/5^k == 0)

  This is exactly what the algorithm computes:
    - n /= 5; count += n;
    - Each iteration adds the number of multiples of 5, 25, 125, etc., in n.

  Thus, the algorithm correctly counts the number of trailing zeroes in n!.
  /*
    Example: n = 100

    - Multiples of 5 up to 100: 5, 10, 15, ..., 100 (there are floor(100/5) = 20
  such numbers) Each contributes at least one factor of 5.

    - Multiples of 25 up to 100: 25, 50, 75, 100 (there are floor(100/25) = 4
  such numbers) Each contributes an extra factor of 5 (since 25 = 5^2).

    - Multiples of 125 up to 100: none (floor(100/125) = 0).

    So, total trailing zeroes in 100! = 20 (from 5s) + 4 (from 25s) = 24.

    This matches the algorithm:
      n = 100
      n /= 5 -> n = 20, count = 20
      n /= 5 -> n = 4,  count = 24
      n /= 5 -> n = 0,  stop

    Therefore, 100! has 24 trailing zeroes.
  */
*/

    // @lc code=start
    class Solution {
public:
  int trailingZeroes(int n) {
    int count = 0;
    while (n > 0) {
      n /= 5;
      count += n;
    }
    return count;
  }
};
// @lc code=end
