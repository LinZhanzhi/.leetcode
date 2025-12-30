/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to find pairs of songs whose total duration is a multiple of 60.
 * Mathematically, for two songs with durations \	1\ and \	2\, we want:
 * (t1 + t2) % 60 == 0.
 * This implies that (t1 % 60 + t2 % 60) % 60 == 0.
 * So, if a song has a remainder \
\ when divided by 60, we need to find another song
 * with a remainder \	arget\ such that (r + target) % 60 == 0.
 * - If r == 0, then target must be 0.
 * - If r != 0, then target must be 60 - r.
 *
 * High-Level Summary:
 * -------------------
 * We can use a frequency array (or hash map) of size 60 to store the counts of remainders encountered so far.
 * We iterate through the \	ime\ array:
 * 1. Calculate the remainder \
 = t % 60\.
 * 2. Determine the required complement remainder: \	arget = (60 - r) % 60\.
 * 3. Add the count of songs with the \	arget\ remainder seen so far to our total count of pairs.
 * 4. Increment the count for the current remainder \
\.
 *
 * Time Complexity: O(N), where N is the number of songs. We iterate through the list once.
 * Space Complexity: O(1), since the frequency array has a fixed size of 60.
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        long long count = 0;
        vector<int> remainderCounts(60, 0);

        for (int t : time) {
            int r = t % 60;

            // Calculate the complement remainder needed to sum to a multiple of 60.
            // If r is 0, we need another 0.
            // If r is non-zero (e.g., 20), we need 60 - r (e.g., 40).
            // The expression (60 - r) % 60 handles both cases correctly:
            // (60 - 0) % 60 = 0
            // (60 - 20) % 60 = 40
            int target = (60 - r) % 60;

            // Add the number of previously seen songs that have the target remainder
            count += remainderCounts[target];

            // Record the current song's remainder
            remainderCounts[r]++;
        }

        return (int)count;
    }
};
// @lc code=end
