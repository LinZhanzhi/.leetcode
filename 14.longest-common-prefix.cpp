/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        int minLen = strs[0].size();
        for (const auto &s : strs)
            minLen = min(minLen, (int)s.size());
        int prefixLen = 0;
        for (; prefixLen < minLen; ++prefixLen)
        {
            char c = strs[0][prefixLen];
            for (int i = 1; i < strs.size(); ++i)
            {
            if (strs[i][prefixLen] != c)
                return strs[0].substr(0, prefixLen);
            }
        }
        return strs[0].substr(0, prefixLen);
    }
};
// @lc code=end
