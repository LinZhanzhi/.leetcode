/*
Given a string s, return the maximum number of occurrences of any substring under the following rules:

The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.


Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 occurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.


Constraints:

1 <= s.length <= 105
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s consists of only lowercase English letters.
*/
class Solution
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        // We only need to consider substrings of size minSize, because larger substrings will have fewer occurrences.
        unordered_map<string, int> count;
        int maxCount = 0;

        for (int i = 0; i <= (int)s.size() - minSize; i++)
        {
            string substring = s.substr(i, minSize);

            // Check if substring has at most maxLetters unique characters
            unordered_set<char> uniqueChars(substring.begin(), substring.end());
            if (uniqueChars.size() <= maxLetters)
            {
                count[substring]++;
                maxCount = max(maxCount, count[substring]);
            }
        }

        return maxCount;
    }
};