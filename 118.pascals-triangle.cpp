/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Preallocate the outer vector to avoid reallocations
        vector<vector<int>> result;
        result.reserve(numRows);

        vector<int> prev;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);
            // Only fill in the middle if i > 1
            for (int j = 1; j < i; ++j) {
                row[j] = prev[j - 1] + prev[j];
            }
            result.push_back(std::move(row));
            prev = result.back(); // Reuse prev for next iteration
        }
        return result;
    }
};
// @lc code=end
