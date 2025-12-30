/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to generate all integers of length
 such that the absolute difference between every pair of consecutive digits is exactly k.
 * The numbers cannot have leading zeros.
 *
 * High-Level Summary:
 * -------------------
 * Since
 is small (up to 9), we can generate these numbers digit by digit using Depth First Search (DFS).
 * We start with the first digit (1-9). For each subsequent position, the next digit depends on the previous digit d:
 * it can be d + k or d - k. We check if these are valid digits (0-9) and continue the recursion.
 *
 * Time Complexity: O(2^N) - In the worst case, each digit has 2 possibilities. Since N <= 9, this is very fast.
 * Space Complexity: O(N) - For the recursion stack depth.
 */

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;

        // Start DFS for each possible leading digit (1-9)
        for (int i = 1; i <= 9; ++i) {
            dfs(n - 1, k, i, result);
        }

        return result;
    }

private:
    // DFS helper function
    // remaining_digits: number of digits left to append
    // k: the required difference
    // current_num: the number formed so far
    // result: vector to store valid numbers
    void dfs(int remaining_digits, int k, int current_num, vector<int>& result) {
        if (remaining_digits == 0) {
            result.push_back(current_num);
            return;
        }

        int last_digit = current_num % 10;

        // Option 1: Next digit is last_digit + k
        int next_digit1 = last_digit + k;
        if (next_digit1 >= 0 && next_digit1 <= 9) {
            dfs(remaining_digits - 1, k, current_num * 10 + next_digit1, result);
        }

        // Option 2: Next digit is last_digit - k
        // We only do this if k > 0 to avoid duplicates when k = 0 (since +0 and -0 are the same)
        if (k > 0) {
            int next_digit2 = last_digit - k;
            if (next_digit2 >= 0 && next_digit2 <= 9) {
                dfs(remaining_digits - 1, k, current_num * 10 + next_digit2, result);
            }
        }
    }
};
// @lc code=end
