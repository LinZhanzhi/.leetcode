/*
We are given hours, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.



Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
Example 2:

Input: hours = [6,6,6]
Output: 0


Constraints:

1 <= hours.length <= 104
0 <= hours[i] <= 16
*/
class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        /*
        we can convert the hours array to a score array where score[i] = 1 if hours[i] > 8 and score[i] = -1 if hours[i] <= 8
        and then we calculate the prefix sum of the score array, which is prefix[i] = score[0] + score[1] + ... + score[i]
        for all prefix sum value v, we store its first occurrence index and last occurrrence index in a hash map
        and then we just do for all pair of prefix sum values v1 and v2, if v1 > v2, we can calculate the length of the interval [first occurrence index of v2 + 1, last occurrence index of v1] as last occurrence index of v1 - first occurrence index of v2, and we want to maximize this length
        time complexity is O(n^2) as prefix sum value is in the range of [-n, n] and we need to check all pair of prefix sum values
        */
        unordered_map<int, pair<int, int>> m; // prefix sum value -> (first occurrence index, last occurrence index)
        int prefix = 0;
        // insert prefix sum value 0 with first occurrence index -1 and last occurrence index -1 to handle the case when the well-performing interval starts from index 0
        m[0] = {-1, -1};
        for (int i = 0; i < hours.size(); i++)
        {
            prefix += hours[i] > 8 ? 1 : -1;
            if (m.find(prefix) == m.end())
            {
                m[prefix] = {i, i};
            }
            else
            {
                m[prefix].second = i;
            }
        }

        // int res = 0;
        // for (auto &p1 : m)
        // {
        //     for (auto &p2 : m)
        //     {
        //         if (p1.first > p2.first)
        //         {
        //             res = max(res, p1.second.second - p2.second.first);
        //         }
        //     }
        // }
        // sort the prefix sum values in ascending order, so we can drop the condition p1.first > p2.first
        // also maintain a minimum first occurrence index for all prefix sum values smaller than the current prefix sum value, so we can calculate the length of the interval in O(1) time
        vector<pair<int, pair<int, int>>> prefixSumValues; // (prefix sum value, (first occurrence index, last occurrence index))
        for (auto &p : m)
        {
            prefixSumValues.push_back(p);
        }
        sort(prefixSumValues.begin(), prefixSumValues.end());
        int res = 0;
        int minFirstOccurrenceIndex = prefixSumValues[0].second.first; // minimum first occurrence index for all prefix sum values smaller than the current prefix sum value
        for (int i = 1; i < prefixSumValues.size(); i++)
        {
            res = max(res, prefixSumValues[i].second.second - minFirstOccurrenceIndex);
            minFirstOccurrenceIndex = min(minFirstOccurrenceIndex, prefixSumValues[i].second.first);
        }
        return res;

    }
};