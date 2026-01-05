/*
 * Brief Digested Understanding:
 * -----------------------------
 * We have a convex polygon with `n` vertices, each having a value.
 * We need to divide this polygon into triangles using non-intersecting diagonals.
 * The "score" of a triangulation is the sum of the products of the vertices of each triangle formed.
 * Our goal is to find the triangulation that minimizes this total score.
 * This is a classic dynamic programming problem (Matrix Chain Multiplication variation).
 *
 * High-Level Summary:
 * -------------------
 * 1. **Dynamic Programming State**: Let `dp[i][j]` be the minimum score to triangulate the polygon formed by vertices from index `i` to index `j` (inclusive).
 * 2. **Base Case**: If `j < i + 2`, we have fewer than 3 vertices, so no triangle can be formed. The cost is 0.
 * 3. **Recursive Step**: To triangulate the polygon defined by vertices `i` through `j`, we can pick any vertex `k` between `i` and `j` (exclusive, i.e., `i < k < j`) to form a triangle with vertices `i`, `k`, and `j`.
 *    - This triangle `(i, k, j)` divides the polygon `(i...j)` into two smaller polygons: `(i...k)` and `(k...j)`.
 *    - The cost of this choice is: `values[i] * values[k] * values[j]` (cost of triangle `ikj`) + `dp[i][k]` (cost of left part) + `dp[k][j]` (cost of right part).
 *    - We iterate through all possible `k` and take the minimum.
 * 4. **Final Answer**: `dp[0][n-1]`, which represents the min score for the entire polygon.
 *
 * Time Complexity: O(N^3), where N is the number of vertices. We have O(N^2) states, and each state takes O(N) to compute.
 * Space Complexity: O(N^2) for the DP table.
 */

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        // dp[i][j] stores the minimum score to triangulate the polygon formed by vertices i, i+1, ..., j.
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // We iterate by the length of the range (len = j - i + 1).
        // The smallest polygon we can triangulate has 3 vertices (len = 3).
        for (int len = 3; len <= n; ++len) {
            // Iterate through all possible starting vertices i.
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // The ending vertex j.

                dp[i][j] = INT_MAX; // Initialize with infinity.

                // Try every possible vertex k between i and j to form the triangle (i, k, j).
                // This triangle splits the polygon (i...j) into (i...k) and (k...j).
                for (int k = i + 1; k < j; ++k) {
                    int currentScore = values[i] * values[k] * values[j] + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], currentScore);
                }
            }
        }

        return dp[0][n - 1];
    }
};