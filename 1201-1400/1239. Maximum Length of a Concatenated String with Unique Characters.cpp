/*
You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.


Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
*/
class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        vector<int> masks;
        for (const auto &s : arr)
        {
            int mask = 0;
            for (const auto &c : s)
            {
                int bit = 1 << (c - 'a');
                // If the character has already been seen in the current string, we can skip this string.
                if ((mask & bit) != 0)
                {
                    mask = 0;
                    break;
                }
                mask |= bit;
            }
            if (mask != 0)
                masks.push_back(mask);
        }
        int ans = 0;
        function<void(int, int)> dfs = [&](int i, int mask)
        {
            ans = max(ans, __builtin_popcount(mask));
            for (int j = i; j < masks.size(); j++)
            {
                if ((mask & masks[j]) == 0)
                    dfs(j + 1, mask | masks[j]);
            }
        };
        dfs(0, 0);
        return ans;
    }
};