/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string_view s) {
        int left = 0, right = static_cast<int>(s.length()) - 1;
        while (left < right) {
            unsigned char cl = s[left], cr = s[right];
            // Move left pointer to next alphanumeric
            if (!((cl >= 'a' && cl <= 'z') || (cl >= 'A' && cl <= 'Z') || (cl >= '0' && cl <= '9'))) {
                ++left;
                continue;
            }
            // Move right pointer to previous alphanumeric
            if (!((cr >= 'a' && cr <= 'z') || (cr >= 'A' && cr <= 'Z') || (cr >= '0' && cr <= '9'))) {
                --right;
                continue;
            }
            // Compare lowercased characters
            if ((cl | 32) != (cr | 32) && !(cl >= '0' && cl <= '9' && cl == cr)) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end
