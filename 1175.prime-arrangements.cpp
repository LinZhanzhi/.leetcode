/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 */

// @lc code=start
class Solution {
public:
  int numPrimeArrangements(int n) {
    const int MOD = 1e9 + 7;
    // Helper function to count primes up to n
    auto countPrimes = [](int n) {
      int count = 0;
      std::vector<bool> isPrime(n + 1, true);
      isPrime[0] = isPrime[1] = false;
      for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
          ++count;
          for (int j = i * 2; j <= n; j += i) {
            isPrime[j] = false;
          }
        }
      }
      return count;
    };
    // Helper function to compute factorial modulo MOD
    auto factorial = [&](int x) {
      long long res = 1;
      for (int i = 2; i <= x; ++i) {
        res = (res * i) % MOD;
      }
      return res;
    };
    int primes = countPrimes(n);
    int nonPrimes = n - primes;
    long long ans = (factorial(primes) * factorial(nonPrimes)) % MOD;
    return (int)ans;
  }
};
// @lc code=end
