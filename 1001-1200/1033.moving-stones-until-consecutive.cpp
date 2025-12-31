/*
 * Brief Digested Understanding:
 * -----------------------------
 * We have three stones at distinct positions a, b, c on a number line.
 * A move consists of taking an endpoint stone (min or max position) and moving it to an empty spot strictly between the current min and max.
 * The goal is to make the stones consecutive (e.g., positions 3, 4, 5).
 * We need to find the minimum and maximum number of moves to achieve this state.
 *
 * High-Level Summary:
 * -------------------
 * 1. **Sorting**: First, sort the three positions to get x < y < z.
 * 2. **Maximum Moves**: To maximize moves, we want to move stones one step at a time into the empty spaces.
 *    The total number of empty spaces between x and z is (z - x - 1) - 1 = z - x - 2.
 *    Every move consumes one empty space (by placing a stone there). So max moves = z - x - 2.
 * 3. **Minimum Moves**:
 *    - If stones are already consecutive (z - x == 2), 0 moves.
 *    - If there is a gap of 1 or 0 between any adjacent pair (i.e., y - x <= 2 or z - y <= 2), we can finish in 1 move.
 *      For example, if we have 1, 3, 10, we can move 10 to 2, resulting in 1, 2, 3.
 *    - Otherwise, we need 2 moves (move x to y-1, then z to y+1, or similar).
 *
 * Time Complexity: O(1) since input size is fixed at 3.
 * Space Complexity: O(1).
 */

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s = {a, b, c};
        sort(s.begin(), s.end());
        int x = s[0];
        int y = s[1];
        int z = s[2];

        // Maximum moves: sum of gaps.
        // Gap between x and y is (y - x - 1).
        // Gap between y and z is (z - y - 1).
        // Total = (y - x - 1) + (z - y - 1) = z - x - 2.
        int max_moves = z - x - 2;

        int min_moves;
        if (z - x == 2) {
            // Already consecutive (e.g., 1, 2, 3)
            min_moves = 0;
        } else if ((y - x <= 2) || (z - y <= 2)) {
            // Gap of 1 or 0 exists between a pair.
            // Example: 1, 3, 10 -> move 10 to 2 -> 1, 2, 3 (1 move)
            // Example: 1, 2, 10 -> move 10 to 3 -> 1, 2, 3 (1 move)
            min_moves = 1;
        } else {
            // Gaps are larger than 1 on both sides.
            // Example: 1, 5, 10.
            // Move 1 to 4 -> 4, 5, 10. Then 10 to 6 -> 4, 5, 6. (2 moves)
            min_moves = 2;
        }

        return {min_moves, max_moves};
    }
};