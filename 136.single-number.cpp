/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        // No extra memory used except for result
        int result = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            result ^= *it;
        }
        return result;
    }
};
// @lc code=end
