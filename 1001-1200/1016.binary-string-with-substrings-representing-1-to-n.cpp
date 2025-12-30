/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to verify if the binary representations of all integers from 1 to n are substrings of s.
 *
 * High-Level Summary:
 * -------------------
 * 1. Constraint Check: The length of s is at most 1000.
 *    - Consider the range [1024, 2047]. There are 1024 integers in this range.
 *    - Each integer in this range has a binary representation of exactly 11 bits (since 2^10 = 1024).
 *    - A string s of length L can contain at most (L - k + 1) distinct substrings of length k.
 *    - With L=1000 and k=11, s can contain at most 1000 - 11 + 1 = 990 distinct substrings of length 11.
 *    - Since we need 1024 distinct 11-bit strings but can only have at most 990, it is impossible for s to contain all of them.
 *    - Therefore, if n >= 2047 (we use 2048 for simplicity), we can immediately return false.
 * 2. Iteration:
 *    - We iterate from n down to n/2 + 1.
 *    - We check if the binary string of the current number exists in s.
 *    - We don't need to check numbers <= n/2 because if a number x is present, its binary prefix (which corresponds to x >> 1) is also present.
 *
 * Time Complexity: O(min(n, 2000) * L), where L is string length. Effectively O(1) due to the bound.
 * Space Complexity: O(L) for binary string storage.
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        // Optimization: If n is large, s (len <= 1000) cannot contain all binary strings.
        // Specifically, s cannot contain all 1024 binary strings of length 11.
        // So if n >= 2048, we can immediately return false.
        if (n >= 2048) {
            return false;
        }

        // Check numbers from n down to n/2 + 1.
        // If binary(i) is in s, then binary(i >> 1) (which is a prefix) is also in s.
        for (int i = n; i > n / 2; --i) {
            string binary = toBinary(i);
            if (s.find(binary) == string::npos) {
                return false;
            }
        }

        return true;
    }

private:
    string toBinary(int n) {
        if (n == 0) return "0";
        string binary = "";
        while (n > 0) {
            binary += (n % 2 == 0 ? '0' : '1');
            n /= 2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
};
// @lc code=end
