/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to find the minimum cost to cover a set of travel days given three types of passes:
 * 1-day, 7-day, and 30-day.
 *
 * High-Level Summary:
 * -------------------
 * We can use Dynamic Programming. Let dp[i] be the minimum cost to cover all travel days up to day i.
 * We iterate from day 1 to the last travel day.
 * If day i is not a travel day, the cost is the same as day i-1 (dp[i] = dp[i-1]).
 * If day i is a travel day, we consider three options ending at day i:
 * 1. Buy a 1-day pass on day i: cost = dp[i-1] + costs[0]
 * 2. Buy a 7-day pass covering [i-6, i]: cost = dp[max(0, i-7)] + costs[1]
 * 3. Buy a 30-day pass covering [i-29, i]: cost = dp[max(0, i-30)] + costs[2]
 * We take the minimum of these three.
 *
 * Time Complexity: O(D), where D is the last travel day (max 365). Effectively O(1).
 * Space Complexity: O(D) for the DP array. Effectively O(1).
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        // dp[i] stores the min cost to cover travel up to day i
        vector<int> dp(lastDay + 1, 0);

        // Use a boolean array for fast lookup of travel days
        vector<bool> isTravelDay(lastDay + 1, false);
        for (int day : days) {
            isTravelDay[day] = true;
        }

        for (int i = 1; i <= lastDay; ++i) {
            if (!isTravelDay[i]) {
                // If not traveling today, cost is same as yesterday
                dp[i] = dp[i-1];
            } else {
                // If traveling today, choose the cheapest pass option
                int oneDay = dp[i-1] + costs[0];
                int sevenDay = dp[max(0, i-7)] + costs[1];
                int thirtyDay = dp[max(0, i-30)] + costs[2];

                dp[i] = min({oneDay, sevenDay, thirtyDay});
            }
        }

        return dp[lastDay];
    }
};
// @lc code=end
