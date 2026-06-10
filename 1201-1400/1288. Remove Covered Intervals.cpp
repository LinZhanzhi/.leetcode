/*
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.



Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1


Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li < ri <= 105
All the given intervals are unique.
*/
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        // sort by start, if start is same, sort by end in descending order
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

        int count = 0;
        int prevEnd = 0;
        for (const auto &interval : intervals)
        {
            if (interval[1] > prevEnd)
            {
                count++;
                prevEnd = interval[1];
            }
        }
        return count;
    }
};