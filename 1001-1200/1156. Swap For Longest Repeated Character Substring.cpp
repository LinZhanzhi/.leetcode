/*
You are given a string text. You can swap two of the characters in the text.

Return the length of the longest substring with repeated characters.



Example 1:

Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
Example 2:

Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
Example 3:

Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.


Constraints:

1 <= text.length <= 2 * 104
text consist of lowercase English characters only.
*/
class Solution
{
public:
    int maxRepOpt1(string text)
    {
        // when we only focus on one character, we can treat other characters as a separator
        // for example, "aaabaaa" can be treated as "aaa#aaaa"
        // and then we do a scan to get length of each segment, and the gap between each two segments
        // for example, "aaabaaa" can be treated as "3#4"
        // if there is no gap, meaning there is only one segment. then no swapping can improve segment. just return the segment length
        // now there is gap.
        // if all gap is more than 1, then no swapping can improve segment. just return the longest segment length
        // if there is a gap with length 1, then we can swap to lengthen merge segments. but problem is where does the swapped character come from?
        // if there are only 2 segments, then we can swap any character to merge segments. so the length is sum of two segments
        // if there are more than 2 segments, then we can only swap a character from other segments. so the length is sum of two segments + 1
        // focus for each character, and get the longest length. then we get the answer.
        int n = text.size();
        vector<int> count(26, 0);
        for (char c : text)
        {
            count[c - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] == 0)
            {
                continue;
            }
            vector<int> segments;
            vector<int> gaps;
            int j = 0; // pointer to scan text
            // scan until we get to start of segment
            while (j < n && text[j] != 'a' + i)
            {
                j++;
            }
            while (j < n)
            {
                // scan and get length of segment
                int segment = 0;
                while (j < n && text[j] == 'a' + i)
                {
                    segment++;
                    j++;
                }
                segments.push_back(segment);
                // scan and get length of gap
                int gap = 0;
                while (j < n && text[j] != 'a' + i)
                {
                    gap++;
                    j++;
                }
                // gap is only meaningful between two segments, so we only record gap when we have scanned a segment
                if (j < n)
                {
                    gaps.push_back(gap);
                }
            }

            int m = segments.size();
            if (m == 1)
            {
                ans = max(ans, segments[0]);
            }
            else
            {
                for (int j = 0; j < m - 1; j++)
                {
                    if (gaps[j] == 1)
                    {
                        if (m == 2)
                        {
                            ans = max(ans, segments[j] + segments[j + 1]);
                        }
                        else
                        {
                            ans = max(ans, segments[j] + segments[j + 1] + 1);
                        }
                    }
                }
                for (int j = 0; j < m; j++)
                {
                    ans = max(ans, segments[j] + 1);
                }
            }
        }
        return ans;
    }
};