/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to compute a^b mod 1337, where a is a normal integer but
 * b is so large that it is given as an array of its digits. We cannot convert b
 * to an integer directly due to its size. Instead, we must use properties of
 * modular exponentiation to compute the result efficiently, handling the digits
 * of b one by one.
 *
 * High-Level Summary:
 * ----
 * We use the property that (a^b) mod m = ((a^(b1*10^k + b2*10^(k-1) + ... +
 * bk)) mod m). This can be broken down recursively using: a^[b1,b2,...,bn] =
 * (a^[b1,b2,...,bn-1])^10 * a^bn We process the digits of b from left to right,
 * recursively, and use fast modular exponentiation to compute powers
 * efficiently. The modulus 1337 is small, so all calculations are done modulo
 * 1337. Time complexity is O(N * log a), where N is the number of digits in b.
 * Space complexity is O(N) due to recursion stack.
 */

#include <vector> // Include vector for the input array 'b'
using std::vector;

// @lc code=start
class Solution {
public:
  // Helper function to perform fast modular exponentiation.
  // Computes (a^k) % mod efficiently using recursion.
  int modPow(int a, int k, int mod) {
    // Base case: any number to the power of 0 is 1
    if (k == 0)
      return 1;
    // Compute a^(k/2) recursively
    int half = modPow(a, k / 2, mod);
    // If k is even: (a^k) = (a^(k/2))^2
    // If k is odd:  (a^k) = (a^(k/2))^2 * a
    if (k % 2 == 0) {
      return (half * half) % mod;
    } else {
      return ((half * half) % mod * (a % mod)) % mod;
    }
  }

  // Main function to compute a^b mod 1337, where b is given as a vector of
  // digits.
  int superPow(int a, vector<int> &b) {
    // The modulus as specified in the problem
    const int MOD = 1337;
    // Base case: if b is empty, a^0 = 1
    if (b.empty())
      return 1;

    // Extract the last digit of b
    int lastDigit = b.back();
    b.pop_back(); // Remove the last digit for the recursive call

    // Compute part1: a^(rest of b) mod MOD, then raise it to the 10th power
    int part1 = modPow(superPow(a, b), 10, MOD);
    // Compute part2: a^(lastDigit) mod MOD
    int part2 = modPow(a, lastDigit, MOD);

    // Combine the two parts and return the result modulo MOD
    return (part1 * part2) % MOD;
  }
};
// @lc code=end
