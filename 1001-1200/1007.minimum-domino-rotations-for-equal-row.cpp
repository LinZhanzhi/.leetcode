/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We want to make all values in the top row the same, or all values in the bottom row the same.
 * We can swap the top and bottom values of any domino.
 * Key Observation: If a solution exists, the target value MUST be one of the values in the
 * first domino (either tops[0] or bottoms[0]). If a value is not present in the first domino,
 * it cannot be present in all dominoes (since the first one is part of "all").
 *
 * High-Level Summary:
 * -------------------
 * 1. Define a helper function \check(x)\ that calculates the minimum rotations to make all tops \x\
 *    or all bottoms \x\.
 *    - Iterate through the array. If a domino doesn't contain \x\, return -1 (impossible).
 *    - Count how many swaps are needed for tops (if tops[i] != x) and bottoms (if bottoms[i] != x).
 *    - Return min(swaps_for_top, swaps_for_bottom).
 * 2. Try \check(tops[0])\. If valid (not -1), return it.
 * 3. If not, try \check(bottoms[0])\. Return the result (valid or -1).
 *
 * Time Complexity: O(N), where N is the number of dominoes. We do at most two passes.
 * Space Complexity: O(1).
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        // Helper lambda to check if we can make all elements equal to x
        auto check = [&](int x) -> int {
            int rotationsA = 0; // Rotations to make tops all x
            int rotationsB = 0; // Rotations to make bottoms all x

            for (int i = 0; i < n; ++i) {
                // If x is not present in the current domino, impossible
                if (tops[i] != x && bottoms[i] != x) {
                    return -1;
                }

                // If top is not x, we need to swap (bottom must be x)
                if (tops[i] != x) {
                    rotationsA++;
                }

                // If bottom is not x, we need to swap (top must be x)
                if (bottoms[i] != x) {
                    rotationsB++;
                }
            }
            // Return the minimum of rotations needed for top or bottom
            return min(rotationsA, rotationsB);
        };

        // Try to make everything equal to tops[0]
        int rotations = check(tops[0]);
        if (rotations != -1) {
            return rotations;
        }

        // If that failed, try to make everything equal to bottoms[0]
        return check(bottoms[0]);
    }
};
// @lc code=end
