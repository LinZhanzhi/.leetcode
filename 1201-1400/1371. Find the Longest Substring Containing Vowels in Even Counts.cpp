/*
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.



Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.


Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.
*/
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int n = s.size();
        vector<int> pos(1 << 5, -1);
        pos[0] = 0;
        int ans = 0, mask = 0;
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if (c == 'a')
                mask ^= 1 << 0;
            else if (c == 'e')
                mask ^= 1 << 1;
            else if (c == 'i')
                mask ^= 1 << 2;
            else if (c == 'o')
                mask ^= 1 << 3;
            else if (c == 'u')
                mask ^= 1 << 4;
            if (pos[mask] >= 0)
                ans = max(ans, i + 1 - pos[mask]);
            else
                pos[mask] = i + 1;
        }
        return ans;
    }
};