/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We want to maximize the score: values[i] + values[j] + i - j, where i < j.
 * This can be rewritten as: (values[i] + i) + (values[j] - j).
 * As we iterate through the array with index j, we want to pick the best previous index i
 * that maximizes (values[i] + i).
 *
 * High-Level Summary:
 * -------------------
 * We can solve this in a single pass.
 * We maintain a variable \maxPrev\ which tracks the maximum value of (values[i] + i) seen so far.
 * For each element at index j (starting from 1), the score using this j is \maxPrev + values[j] - j\.
 * We update the global maximum score.
 * Then, we update \maxPrev\ to include the current element: \max(maxPrev, values[j] + j)\.
 *
 * Time Complexity: O(N), where N is the size of the array.
 * Space Complexity: O(1).
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxPrev = values[0] + 0; // Represents max(values[i] + i) seen so far

        for (int j = 1; j < values.size(); ++j) {
            // Calculate score for current pair (best i so far, current j)
            // Score = (values[i] + i) + (values[j] - j)
            maxScore = max(maxScore, maxPrev + values[j] - j);

            // Update maxPrev to include current j as a potential i for future pairs
            maxPrev = max(maxPrev, values[j] + j);
        }

        return maxScore;
    }
};
// @lc code=end
