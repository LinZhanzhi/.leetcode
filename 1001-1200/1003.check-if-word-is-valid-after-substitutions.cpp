/*
 * @lc app=leetcode id=1003 lang=cpp
 *
 * [1003] Check If Word Is Valid After Substitutions
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * The problem asks if a string \s\ can be constructed by starting with an empty string
 * and repeatedly inserting "abc" at any position.
 * Conversely, this means if \s\ is valid, we should be able to repeatedly remove "abc"
 * substrings until the string becomes empty.
 * This structure suggests a stack-based approach, similar to valid parentheses checking.
 * Instead of matching '(' with ')', we are matching the sequence 'a', 'b', 'c'.
 *
 * High-Level Summary:
 * -------------------
 * We iterate through the string \s\ and maintain a stack (or a string acting as a stack).
 * For each character, we push it onto the stack.
 * After pushing, we check if the top 3 elements of the stack form the sequence "abc".
 * If they do, we pop these 3 elements immediately.
 * If the string is valid, the stack should be empty after processing all characters.
 *
 * Time Complexity: O(N), where N is the length of \s\. Each character is added and removed at most once.
 * Space Complexity: O(N) for the stack in the worst case.
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // We can use a string as a stack for convenience.
        string st;

        for (char c : s) {
            st.push_back(c);

            // Check if the last 3 characters form "abc"
            int n = st.size();
            if (n >= 3 && st[n-1] == 'c' && st[n-2] == 'b' && st[n-3] == 'a') {
                st.pop_back(); // remove 'c'
                st.pop_back(); // remove 'b'
                st.pop_back(); // remove 'a'
            }
        }

        // If the string is valid, the stack must be empty.
        return st.empty();
    }
};
// @lc code=end
