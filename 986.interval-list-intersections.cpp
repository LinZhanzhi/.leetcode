/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given two sorted lists of disjoint intervals. We need to find the intersection of these two lists.
 * The intersection of two lists of intervals is the set of intervals common to both.
 *
 * High-Level Summary:
 * -------------------
 * Since both lists are sorted and disjoint, we can use a two-pointer approach.
 * Let i be the pointer for irstList and j be the pointer for secondList.
 * We compare the interval A = firstList[i] and B = secondList[j].
 *
 * 1. Check if A and B intersect.
 *    - An intersection exists if max(A.start, B.start) <= min(A.end, B.end).
 *    - The intersection interval is [max(A.start, B.start), min(A.end, B.end)].
 * 2. If they intersect, add the intersection to the result.
 * 3. Move the pointer of the interval that ends earlier.
 *    - If A.end < B.end, increment i. This is because A cannot possibly intersect with any subsequent interval in secondList (since secondList is sorted and disjoint, the next interval in secondList starts after B.end, which is greater than A.end).
 *    - Otherwise, increment j.
 *
 * Time Complexity: O(N + M), where N and M are the lengths of the two lists. We process each interval at most once.
 * Space Complexity: O(N + M) to store the result. O(1) auxiliary space.
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0; // Pointer for firstList
        int j = 0; // Pointer for secondList

        while (i < firstList.size() && j < secondList.size()) {
            // Let's define the start and end points for clarity
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            // Find the overlap range
            // The start of the intersection is the max of the start times
            int intersectStart = max(start1, start2);
            // The end of the intersection is the min of the end times
            int intersectEnd = min(end1, end2);

            // If the range is valid (start <= end), we have an intersection
            if (intersectStart <= intersectEnd) {
                result.push_back({intersectStart, intersectEnd});
            }

            // Move the pointer of the interval that finishes first
            // The logic is that the interval ending earlier cannot overlap with any future interval
            // from the other list.
            if (end1 < end2) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};
// @lc code=end
