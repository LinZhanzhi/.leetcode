/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given two arrays of numbers, `nums1` and `nums2`.
 * We want to draw lines connecting matching numbers (`nums1[i] == nums2[j]`).
 * The constraint is that lines cannot cross. This means if we connect index `i` in `nums1` to index `j` in `nums2`, and index `k` in `nums1` to index `l` in `nums2` (where `i < k`), then it must be true that `j < l`.
 * This problem is structurally identical to finding the **Longest Common Subsequence (LCS)**.
 * We want to find the maximum number of pairs (elements that appear in both arrays in the same relative order).
 *
 * High-Level Summary:
 * -------------------
 * 1. **Dynamic Programming**: We can use a 2D DP table `dp[i][j]`.
 *    - `dp[i][j]` represents the maximum number of uncrossed lines we can draw using the first `i` elements of `nums1` and the first `j` elements of `nums2`.
 * 2. **Transitions**:
 *    - If `nums1[i-1] == nums2[j-1]`: We can draw a line between these two. The result is `1 + dp[i-1][j-1]`.
 *    - If `nums1[i-1] != nums2[j-1]`: We cannot draw a line between these specific two. The best we can do is the maximum of ignoring the current element of `nums1` (`dp[i-1][j]`) or ignoring the current element of `nums2` (`dp[i][j-1]`).
 * 3. **Base Case**: `dp[0][0] = 0` (0 lines with empty arrays).
 * 4. **Optimization**: Since `dp[i][j]` only depends on the previous row `dp[i-1]`, we can optimize space to O(min(M, N)) or just O(N) using a 1D array, but the 2D array is clearer for explanation and fits within the constraints (500x500).
 *
 * Time Complexity: O(M * N), where M and N are the lengths of `nums1` and `nums2`.
 * Space Complexity: O(M * N) for the 2D DP table.
 */

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // dp[i][j] stores the max uncrossed lines using nums1[0...i-1] and nums2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If the current numbers match, we can draw a line.
                // We add 1 to the result of the subproblem without these two numbers.
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If they don't match, we take the best result from either:
                    // 1. Excluding the current number from nums1 (dp[i-1][j])
                    // 2. Excluding the current number from nums2 (dp[i][j-1])
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};