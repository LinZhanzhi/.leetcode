/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        // Skip trailing spaces
        while (end >= 0 && s[end] == ' ') --end;
        int start = end;
        // Find the start of the last word
        while (start >= 0 && s[start] != ' ') --start;
        return end - start;
    }
};
// @lc code=end

