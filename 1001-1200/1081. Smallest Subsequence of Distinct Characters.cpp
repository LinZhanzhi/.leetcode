/*
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.



Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/
class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> lastIndex(26, -1);
        vector<bool> inStack(26, false);
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            lastIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (inStack[s[i] - 'a'])
                continue;

            // s[i] can make the result smaller, so pop the top of the stack if it's greater than s[i]
            // but make sure the characters in the stack can be found later in the string
            while (!st.empty() && st.top() > s[i] && lastIndex[st.top() - 'a'] > i)
            {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            // add the current character as we can .
            st.push(s[i]);
            inStack[s[i] - 'a'] = true;
        }

        string result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};