/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        
        // Convert from base-26 (A-Z) to decimal
        for (char c : columnTitle) {
            // Convert character to digit (A=1, B=2, ..., Z=26)
            int digit = c - 'A' + 1;
            
            // Multiply current result by 26 and add new digit
            result = result * 26 + digit;
        }
        
        return result;
    }
};
// @lc code=end

