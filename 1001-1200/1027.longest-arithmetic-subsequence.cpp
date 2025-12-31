/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to find the length of the longest subsequence in a given array `nums` such
 * that the difference between any two consecutive elements in the subsequence is constant.
 * This is an arithmetic progression. The order of elements in the subsequence must match
 * their order in the original array.
 *
 * High-Level Summary:
 * -------------------
 * I will use a Dynamic Programming (DP) approach with Memoization (Top-Down).
 * The previous solution relied on the small range of values ([0, 500]). This updated
 * solution works for any range of integer values by using a map to find indices.
 *
 * State Definition:
 *   `dp[i][j]` = Length of the longest arithmetic subsequence whose first two elements
 *                are `nums[i]` and `nums[j]` (where `i < j`).
 *
 * Algorithm:
 * 1. Precompute a mapping `valueIndices` where `valueIndices[v]` is a sorted list of
 *    indices where value `v` appears in `nums`. This effectively implements the
 *    requested `firstIndex[value][index]` lookup.
 * 2. Define a recursive function `solve(i, j)` with memoization:
 *    - Calculate the common difference `diff = nums[j] - nums[i]`.
 *    - Calculate the expected next value `target = nums[j] + diff`.
 *    - Search for the smallest index `k > j` such that `nums[k] == target`.
 *      We use `upper_bound` on `valueIndices[target]` to find this efficiently.
 *    - If such a `k` exists, `dp[i][j] = 1 + solve(j, k)`.
 *      (The `1` accounts for `nums[i]`, and `solve(j, k)` covers the rest).
 *    - If no such `k` exists, the sequence is just `nums[i], nums[j]`, so return 2.
 * 3. Iterate through all pairs `(i, j)` with `i < j` to find the maximum length.
 *
 * Time Complexity:
 *   - O(N^2 * log N). There are O(N^2) states. Each state takes O(log N) to find the
 *     next index. This fits within the constraints for N=1000.
 *
 * Space Complexity:
 *   - O(N^2) for the memoization table.
 *   - O(N) for the `valueIndices` map.
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        // Map value -> sorted list of indices
        // This allows us to find the first index of a value >= specific index
        unordered_map<int, vector<int>> valueIndices;
        for (int i = 0; i < n; ++i) {
            valueIndices[nums[i]].push_back(i);
        }

        // Memoization table initialized to 0
        // dp[i][j] stores the result for solve(i, j)
        vector<vector<int>> memo(n, vector<int>(n, 0));

        int maxLength = 2;

        // Iterate all pairs (i, j) to start the sequence
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                maxLength = max(maxLength, solve(i, j, nums, valueIndices, memo));
            }
        }

        return maxLength;
    }

private:
    // Returns the length of the LAS starting with nums[i], nums[j]
    int solve(int i, int j, const vector<int>& nums,
              const unordered_map<int, vector<int>>& valueIndices,
              vector<vector<int>>& memo) {

        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        long long diff = (long long)nums[j] - nums[i];
        long long target = (long long)nums[j] + diff;

        // Find the first index k > j such that nums[k] == target
        int k = -1;

        // Check if target is within integer range and exists in the map
        if (target >= INT_MIN && target <= INT_MAX && valueIndices.count((int)target)) {
            const vector<int>& indices = valueIndices.at((int)target);
            // We need an index > j. Since indices are sorted, we can use upper_bound.
            auto it = upper_bound(indices.begin(), indices.end(), j);
            if (it != indices.end()) {
                k = *it;
            }
        }

        if (k != -1) {
            // Found next element, recurse
            // The length is 1 (for nums[i]) + length of sequence starting at j, k
            memo[i][j] = 1 + solve(j, k, nums, valueIndices, memo);
        } else {
            // End of sequence, just nums[i] and nums[j]
            memo[i][j] = 2;
        }

        return memo[i][j];
    }
};
// @lc code=end