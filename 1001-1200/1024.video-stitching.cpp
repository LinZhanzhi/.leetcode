/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * The problem asks for the minimum number of video clips needed to cover a continuous
 * time interval [0, time]. We are given a list of clips, each defined by a start
 * and end time. We need to select a subset of these clips such that they overlap
 * or touch to form a continuous coverage from 0 to the target time. If the entire
 * range cannot be covered, we should return -1.
 *
 * High-Level Summary:
 * -------------------
 * I will use a greedy approach to solve this problem.
 * 1. Sort the clips based on their start times. This allows us to process them in order.
 * 2. Maintain a `current_end` variable, which tracks the end of the continuous range
 *    [0, current_end] covered so far. Initially, this is 0.
 * 3. Iterate through the sorted clips. In each step, consider all clips that start
 *    before or at `current_end`. Among these candidates, pick the one that extends
 *    the coverage the furthest (i.e., has the maximum end time).
 * 4. Update `current_end` to this new maximum reach and increment the clip count.
 * 5. Repeat this process until `current_end` reaches or exceeds the target `time`.
 * 6. If at any point we cannot find a clip to extend our range (i.e., the max reach
 *    doesn't go beyond `current_end`), it means there is a gap, and we return -1.
 *
 * Time Complexity:
 *   - O(N log N) due to sorting the clips, where N is the number of clips.
 *   - The subsequent iteration is O(N) as we pass through the clips at most once.
 *
 * Space Complexity:
 *   - O(1) or O(log N) depending on the sorting implementation, as we only use a
 *     few variables for state.
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // Sort the clips by their start time.
        // If start times are equal, the secondary sort order doesn't strictly matter
        // for this greedy logic, but default vector comparison works fine.
        sort(clips.begin(), clips.end());

        int ans = 0;            // Count of clips used
        int current_end = 0;    // The end of the continuous range covered [0, current_end]
        int farthest_reach = 0; // The furthest point we can reach from the current range
        int i = 0;
        int n = clips.size();

        // We need to cover up to 'time'.
        while (current_end < time) {
            // Check all clips that start within the current covered range [0, current_end].
            // We want to pick the one that extends our reach the most.
            while (i < n && clips[i][0] <= current_end) {
                farthest_reach = max(farthest_reach, clips[i][1]);
                i++;
            }

            // If the farthest we can reach is not better than where we currently are,
            // it means we are stuck and cannot cover the next segment.
            if (current_end == farthest_reach) {
                return -1;
            }

            // We select the clip that gave us 'farthest_reach'.
            // Update our current covered range to this new point.
            current_end = farthest_reach;
            ans++;
        }

        return ans;
    }
};
// @lc code=end