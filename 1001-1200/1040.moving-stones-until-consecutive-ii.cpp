/*
 * Brief Digested Understanding:
 * -----------------------------
 * We have n stones at distinct positions.
 * A move consists of taking an endpoint stone (min or max) and moving it to an unoccupied position such that it is no longer an endpoint.
 * The goal is to make all stones consecutive (range size n).
 * We need to find the minimum and maximum number of moves.
 *
 * High-Level Summary:
 * -------------------
 * 1. **Sorting**: First, sort the stones to handle positions easily.
 * 2. **Maximum Moves**:
 *    - The total "empty space" inside the current range is (stones[n-1] - stones[0] + 1) - n.
 *    - Each move consumes at least one empty space.
 *    - To maximize moves, we want to waste as little empty space as possible.
 *    - We are forced to give up the empty space at one of the ends in the very first move.
 *      - Either we move the minimum stone (stones[0]) to a position > stones[1]. We lose the gap (stones[1] - stones[0] - 1).
 *      - Or we move the maximum stone (stones[n-1]) to a position < stones[n-2]. We lose the gap (stones[n-1] - stones[n-2] - 1).
 *    - Max moves = Total Empty Space - min(gap_left, gap_right).
 * 3. **Minimum Moves**:
 *    - This is a sliding window problem. We want to find a window of size `n` that already contains the maximum number of stones.
 *    - If a window of length `n` contains `k` stones, we need `n - k` moves to fill the gaps.
 *    - **Edge Case**: If we have `n-1` consecutive stones (e.g., 1, 2, 3, 10 with n=4), we cannot simply move the endpoint to fill the gap because the moved stone must not be an endpoint. This specific configuration requires 2 moves.
 *
 * Time Complexity: O(N log N) due to sorting. The sliding window is O(N).
 * Space Complexity: O(1) if we ignore the space for sorting (or O(log N)).
 */

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();

        // Calculate Maximum Moves
        // We lose the gap at one end. We choose the smaller gap to lose.
        // Gap left: stones[1] - stones[0] - 1
        // Gap right: stones[n-1] - stones[n-2] - 1
        // Total empty slots: (stones[n-1] - stones[0] + 1) - n
        // Max moves = Total Empty - min(Gap left, Gap right)
        // Simplified:
        // Option 1 (lose left gap): stones[n-1] - stones[1] - n + 2
        // Option 2 (lose right gap): stones[n-2] - stones[0] - n + 2
        int max_moves = max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);

        // Calculate Minimum Moves
        int min_moves = n;
        int i = 0;
        for (int j = 0; j < n; ++j) {
            // Maintain a window [i, j] such that the range size (stones[j] - stones[i] + 1) <= n
            while (stones[j] - stones[i] + 1 > n) {
                i++;
            }

            int count = j - i + 1; // Number of stones in the current window

            // Check for the edge case: n-1 consecutive stones
            // If we have n-1 stones in the window and their range is exactly n-1,
            // it means they are consecutive (e.g., 1, 2, 3, 4).
            // If this is the case, we have one stone outside which is far away.
            // We need 2 moves to fix this (e.g., 1,2,3,10 -> 1,2,3,5,10 -> 1,2,3,4,5).
            if (count == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
                min_moves = min(min_moves, 2);
            } else {
                // Normal case: we need to fill the (n - count) empty spots in this window.
                min_moves = min(min_moves, n - count);
            }
        }

        return {min_moves, max_moves};
    }
};