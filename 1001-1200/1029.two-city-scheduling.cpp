/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We have 2n people who need to be flown to either City A or City B. We must send
 * exactly n people to City A and n people to City B. Each person has a specific cost
 * for flying to A and a cost for flying to B. We want to minimize the total cost of
 * flying everyone.
 *
 * High-Level Summary:
 * -------------------
 * This is a greedy problem. The decision of where to send a person depends on the
 * relative cost difference between City A and City B, not just the absolute cost.
 *
 * 1. Calculate the "opportunity cost" or difference for each person: `diff = costA - costB`.
 *    - A small (negative) `diff` means `costA` is much smaller than `costB`, so this
 *      person saves us money if they go to A.
 *    - A large (positive) `diff` means `costA` is much larger than `costB`, so this
 *      person saves us money if they go to B.
 * 2. Sort the people based on this difference in ascending order.
 * 3. The first `n` people in the sorted list have the smallest `costA - costB`, meaning
 *    they are the best candidates for City A.
 * 4. The remaining `n` people are the best candidates for City B.
 * 5. Sum the costs accordingly.
 *
 * Time Complexity:
 *   - O(N log N) due to sorting, where N is the total number of people (2n).
 *
 * Space Complexity:
 *   - O(1) or O(log N) depending on the sorting implementation (ignoring input storage).
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort the costs vector based on the difference between cost to A and cost to B.
        // If (a[0] - a[1]) is smaller, it means going to A is relatively cheaper compared to B.
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int totalCost = 0;
        int n = costs.size() / 2;

        // The first n people (with the smallest diff) go to City A.
        for (int i = 0; i < n; ++i) {
            totalCost += costs[i][0];
        }

        // The remaining n people go to City B.
        for (int i = n; i < 2 * n; ++i) {
            totalCost += costs[i][1];
        }

        return totalCost;
    }
};
// @lc code=end