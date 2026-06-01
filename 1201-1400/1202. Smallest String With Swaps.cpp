/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.



Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination:
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"


Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/
class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        // if there are no pairs, return the original string
        // if there are pairs, we can use a union find data structure to group the indices that can be swapped
        // then we can sort the characters in each group and place them back to those indices in the original string
        // so we just do grouping first and then sorting and placing back
        int n = s.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // initialize the parent of each index to itself
        }
        // union find functions
        function<int(int)> find = [&](int x)
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]); // path compression
            }
            return parent[x];
        };
        function<void(int, int)> unite = [&](int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY)
            {
                parent[rootX] = rootY;
            }
        };
        // group the indices based on the pairs
        for (const auto &pair : pairs)
        {
            unite(pair[0], pair[1]);
        }
        // create a map to store the characters in each group
        unordered_map<int, vector<char>> groups;
        for (int i = 0; i < n; i++)
        {
            groups[find(i)].push_back(s[i]);
        }
        // sort the characters in each group in descending order so we can pop the last character when placing back to the original string
        for (auto &group : groups)
        {
            sort(group.second.begin(), group.second.end() , greater<char>());
        }
        // place the sorted characters back to their original indices . small to large
        string result = s;
        for (int i = 0; i < n; i++)
        {
            int root = find(i);
            result[i] = groups[root].back(); // get the last character from the sorted group
            groups[root].pop_back();         // remove the last character from the group
        }
        return result;
    }
};