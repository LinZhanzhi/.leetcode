/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        
        // Convert to base-26 (A-Z) from right to left
        while (columnNumber > 0) {
            // Subtract 1 because Excel columns are 1-indexed
            columnNumber--;
            
            // Get the current digit (0-25) and convert to letter (A-Z)
            char currentChar = 'A' + (columnNumber % 26);
            result = currentChar + result;
            
            // Move to the next position
            columnNumber /= 26;
        }
        
        return result;
    }
};
// @lc code=end

