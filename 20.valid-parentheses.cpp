/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> stk;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }
            else
            {
                if (stk.empty())
                    return false;
                char t = stk.top();
                stk.pop();
                if ((c == ')' && t != '(') ||
                    (c == '}' && t != '{') ||
                    (c == ']' && t != '['))
                {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end
