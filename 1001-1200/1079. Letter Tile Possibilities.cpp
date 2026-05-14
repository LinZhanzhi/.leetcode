/*
You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.



Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1


Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.
*/
class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        int count[26] = {0};
        for (char c : tiles)
            count[c - 'A']++;

        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] == 0)
                continue;

            res++;
            count[i]--;
            res += numTilePossibilities(count);
            count[i]++;
        }
        return res;
    }

private:
    int numTilePossibilities(int count[26])
    {
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] == 0)
                continue;

            res++;
            count[i]--;
            res += numTilePossibilities(count);
            count[i]++;
        }
        return res;
    }
};
