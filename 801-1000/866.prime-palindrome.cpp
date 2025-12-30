/*
 * @lc app=leetcode id=866 lang=cpp
 *
 * [866] Prime Palindrome
 */

/*
 * Brief Digested Understanding:
 * ---
 * In this problem, you are asked to find the smallest number that is both a
 * palindrome (it reads the same forward and backward) and a prime (only
 * divisible by 1 and itself), which is at least as large as the given integer
 * n. Essentially, from n upwards, we want the first number satisfying both
 * properties.
 *
 * High-Level Summary:
 * ---
 * The solution systematically generates palindromic numbers in increasing
 * order, starting at n, and checks each for primality. For efficiency, we only
 * generate palindromes (since most numbers aren't palindromic), and then for
 * each such candidate ≥ n, we perform a primality check.
 * - For palindromes with an even number of digits (except 11), most are
 * divisible by 11, so we focus on odd-length palindromes and handle 11
 * specially.
 * - We implement helper functions for checking if a number is palindrome,
 * checking for primality, and for generating palindromes.
 * - This modular approach makes the code clear and efficient enough for the
 * constraints (n ≤ 10^8).
 * - Time Complexity: O(sqrt(k)) for checking primality of each candidate k, but
 * as we skip non-palindromic numbers, it's efficient within problem
 * constraints.
 * - Space Complexity: O(1) for palindrome and prime checks; no large data
 * structure is maintained.
 */

// @lc code=start
#include <cmath>
#include <string>
#include <vector>

using std::min;
using std::string;

// Helper function to check if a given number is prime
bool isPrime(int x) {
  // Handle special cases
  if (x < 2)
    return false;
  // Even numbers greater than 2 are not prime
  if (x > 2 && x % 2 == 0)
    return false;
  // Test divisibility up to sqrt(x)
  for (int d = 3; d <= static_cast<int>(sqrt(x)); d += 2) {
    if (x % d == 0)
      return false;
  }
  return true;
}

// Helper function to generate palindromic numbers with a given odd length
int buildPalindrome(int root, bool oddLength) {
  string s = std::to_string(root);
  int len = s.size();
  // For odd length, skip the last digit when mirroring
  for (int i = len - (oddLength ? 2 : 1); i >= 0; --i) {
    s.push_back(s[i]);
  }
  return std::stoi(s);
}

class Solution {
public:
  int primePalindrome(int n) {
    // If n is between 8 and 11 (inclusive), return 11 directly
    // This is an important exception; all even-length palindromes > 11 are
    // divisible by 11
    if (n <= 11) {
      for (int x = n; x <= 11; ++x) {
        if (isPrime(x) && isPalindrome(x))
          return x;
      }
      // If not found, proceed further
    }

    // For numbers with up to 8 digits
    // Since even length palindromes > 11 are not prime, only generate
    // odd-length palindromes
    // proof that even length palindromes > 11 are not prime
    // if a number is a palindrome and even length, it is divisible by 11
    // because 11 is a prime number and the number is a palindrome, it is
    // divisible by 11 therefore, the number is not prime therefore, we can skip
    // even length palindromes > 11 proof that odd length palindromes > 11 are
    // prime if a number is a palindrome and odd length, it is not divisible by
    // 11 because 11 is a prime number and the number is a palindrome, it is not
    // divisible by 11 therefore, the number is prime therefore, we can check
    // odd length palindromes > 11
    for (int len = 1; len <= 5; ++len) {
      // The root gives us the left-half of the palindrome
      int start = pow(10, len - 1);
      int end = pow(10, len);

      for (int root = start; root < end; ++root) {
        int candidate =
            buildPalindrome(root, true); // Only odd-length palindromes

        // Skip candidate if it's out of the valid range
        if (candidate > 200000000)
          break; // Constraint: n <= 1e8, answer < 2*1e8

        // Only check candidates >= n
        if (candidate >= n && isPrime(candidate))
          return candidate;
      }
    }
    // According to problem statement, answer always exists in range [2, 2*10^8]
    // But we should handle overflows gracefully.
    return -1; // Should never reach here
  }

private:
  // Helper function to check if a number is a palindrome using string
  // conversion
  bool isPalindrome(int x) {
    string s = std::to_string(x);
    int left = 0, right = static_cast<int>(s.size()) - 1;
    while (left < right) {
      if (s[left++] != s[right--])
        return false;
    }
    return true;
  }
};
// @lc code=end
