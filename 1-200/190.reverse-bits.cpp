/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
        int result = 0;
        
        // Process all 32 bits
        for (int i = 0; i < 32; i++) {
            // Get the i-th bit from the right
            int bit = (n >> i) & 1;
            
            // Place the bit in the reversed position
            result |= (bit << (31 - i));
        }
        
        return result;
    }
};
// @lc code=end

