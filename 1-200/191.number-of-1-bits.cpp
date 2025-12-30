/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        
        // Brian Kernighan's algorithm
        // n & (n-1) removes the least significant set bit
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        
        return count;
    }
};
// @lc code=end

