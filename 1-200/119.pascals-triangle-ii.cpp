/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Use only O(1) extra space (besides the output vector)
        vector<int> row(rowIndex + 1, 1);
        // Use 64-bit integer for calculation to avoid overflow, but store as int
        for (int i = 1; i <= rowIndex; ++i) {
            // Compute C(rowIndex, i) using previous value
            // row[i] = row[i-1] * (rowIndex - i + 1) / i
            // Work backwards to avoid extra space
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};
// @lc code=end
