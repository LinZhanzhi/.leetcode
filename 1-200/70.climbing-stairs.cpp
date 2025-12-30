/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // Handle edge cases
        if (n <= 2) {
            return n;
        }
        
        // Use dynamic programming with space optimization
        // This is essentially the Fibonacci sequence
        int prev2 = 1;  // ways to climb 1 step
        int prev1 = 2;  // ways to climb 2 steps
        
        // Calculate ways for each step from 3 to n
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};
// @lc code=end

