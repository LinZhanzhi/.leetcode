/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    // Function to check if an integer is a palindrome
    bool isPalindrome(int x)
    {
        // Negative numbers are not palindromes
        if (x < 0)
            return false;
        int original = x, reversed = 0;
        // Reverse the integer
        while (x > 0)
        {
            int digit = x % 10;
            // Check for overflow before multiplying and adding
            if (reversed > (INT_MAX - digit) / 10)
                return false; // handle overflow
            reversed = reversed * 10 + digit;
            x /= 10;
        }
        // Check if the original number and reversed number are the same
        return original == reversed;
    }
};
// @lc code=end
