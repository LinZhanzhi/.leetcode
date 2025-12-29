/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to construct a string with exactly  'a's and  'b's such that "aaa" and "bbb" do not appear.
 * This means we cannot have 3 consecutive identical characters.
 *
 * High-Level Summary:
 * -------------------
 * This is a greedy construction problem.
 * At each step, we decide whether to append 'a' or 'b'.
 * The general rule is to append the character that we have more of remaining, to balance the counts.
 * However, if appending that character would create "aaa" or "bbb" (i.e., the last two characters are already that character),
 * we MUST append the other character, regardless of counts.
 *
 * Algorithm:
 * 1. Initialize an empty string s.
 * 2. Loop while  > 0 or  > 0.
 * 3. Check if we should write 'a':
 *    - Case 1: We have more 'a's than 'b's ( > b), AND writing 'a' won't violate the rule (last two aren't "aa").
 *    - Case 2: We have fewer or equal 'a's ( <= b), BUT writing 'b' would violate the rule (last two are "bb"), so we are forced to write 'a'.
 *    - Note: We also need to ensure  > 0.
 * 4. If we should write 'a', append 'a' and decrement .
 * 5. Otherwise (if we should write 'b'), append 'b' and decrement .
 *    - This happens if  > a and no violation, or if writing 'a' would cause a violation.
 *
 * Time Complexity: O(a + b) - We construct the string character by character.
 * Space Complexity: O(a + b) - To store the result.
 */

#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";
        int n = a + b;

        while (a > 0 || b > 0) {
            bool writeA = false;
            int len = s.length();

            // Check if the last two characters are 'a'
            bool lastTwoA = (len >= 2 && s[len-1] == 'a' && s[len-2] == 'a');
            // Check if the last two characters are 'b'
            bool lastTwoB = (len >= 2 && s[len-1] == 'b' && s[len-2] == 'b');

            if (lastTwoA) {
                // Must write 'b' to avoid "aaa"
                writeA = false;
            } else if (lastTwoB) {
                // Must write 'a' to avoid "bbb"
                writeA = true;
            } else {
                // No immediate violation threat.
                // Greedily choose the one with higher remaining count.
                if (a >= b) {
                    writeA = true;
                } else {
                    writeA = false;
                }
            }

            if (writeA) {
                s += 'a';
                a--;
            } else {
                s += 'b';
                b--;
            }
        }

        return s;
    }
};
// @lc code=end
