/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        // Handle edge cases
        if (needle.empty()) {
            return 0;  // Empty string is always found at index 0
        }
        
        if (haystack.empty() || haystack.length() < needle.length()) {
            return -1;  // Needle is longer than haystack
        }
        
        // Try each possible starting position in haystack
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            // Check if needle matches starting at position i
            bool found = true;
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            
            if (found) {
                return i;  // Found the first occurrence
            }
        }
        
        return -1;  // Needle not found
    }
};
// @lc code=end

