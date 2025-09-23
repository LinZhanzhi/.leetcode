/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

/*
 * High-Level Summary:
 * -------------------
 * This solution uses the Sieve of Eratosthenes algorithm to efficiently count
 * the number of prime numbers less than a given integer n. The Sieve of
 * Eratosthenes is a classic algorithm for finding all primes up to a certain
 * limit by iteratively marking the multiples of each prime number as non-prime.
 *
 * Assumptions:
 * - The input n is a non-negative integer.
 * - We are to count the number of prime numbers strictly less than n (i.e.,
 * primes < n).
 *
 * Approach:
 * - We create a boolean array isPrime of size n, where isPrime[i] indicates
 * whether i is a prime number.
 * - We initialize all entries as true (assuming all numbers are prime), then
 * explicitly set 0 and 1 to false (since 0 and 1 are not prime).
 * - For each number i starting from 2 up to sqrt(n), if i is still marked as
 * prime, we mark all multiples of i (starting from i*i) as non-prime.
 * - Finally, we count how many numbers remain marked as prime in the range [2,
 * n).
 *
 * Time Complexity: O(n log log n), which is very efficient for large n.
 * Space Complexity: O(n), due to the boolean array storing primality
 * information for each number less than n.
 *
 * Edge Cases:
 * - If n <= 2, there are no primes less than n, so we return 0 immediately.
 *
 * Why this approach?
 * - The Sieve of Eratosthenes is much faster than checking each number
 * individually for primality, especially for large n.
 * - By starting to mark multiples from i*i, we avoid redundant work, since
 * smaller multiples would have already been marked by smaller primes.
 */

// @lc code=start
class Solution {
public:
  // This function returns the number of prime numbers less than n.
  int countPrimes(int n) {
    // Edge case: If n is less than or equal to 2, there are no primes less than
    // n. 0 and 1 are not prime, and 2 is the first prime, but we want strictly
    // less than n.
    if (n <= 2)
      return 0;

    // Create a boolean vector of size n, initialized to true.
    // isPrime[i] will be true if i is a prime number, false otherwise.
    // We use n instead of n+1 because we only care about numbers less than n.
    std::vector<bool> isPrime(n, true);

    // 0 and 1 are not prime numbers by definition, so we mark them as false.
    isPrime[0] = isPrime[1] = false;

    // Start the sieve process.
    // We only need to check numbers up to sqrt(n), because any composite number
    // less than n must have a factor less than or equal to sqrt(n).
    for (int i = 2; i * i < n; ++i) {
      // If i is still marked as prime, it means it has not been marked as a
      // multiple of any smaller prime.
      if (isPrime[i]) {
        // Mark all multiples of i as non-prime.
        // We start from i*i because any smaller multiple of i would have
        // already been marked by a smaller prime factor.
        for (int j = i * i; j < n; j += i) {
          isPrime[j] = false; // Mark j as not prime.
        }
      }
      // If isPrime[i] is false, it means i is composite and its multiples have
      // already been marked.
    }

    // Now, count how many numbers are still marked as prime in the range [2,
    // n).
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (isPrime[i])
        ++count; // Increment count for each prime found.
    }

    // Return the total count of primes less than n.
    return count;
  }
};
// @lc code=end
