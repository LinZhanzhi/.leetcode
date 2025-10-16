/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

/*
 * Brief Digested Understanding:
 * ----
 * The problem asks for the lowest-cost journey from a given source city
 * to a destination city, using at most k stops along the way (so up to k+1
 * flights including the last leg). Each flight has a cost, and the connections
 * form a directed graph. We need to find the minimal price that abides by the
 * stop-limit constraint, or return -1 if it's impossible. The challenge is
 * handling the stop-count constraint while ensuring the solution does not take
 * more than O(n^2) or O(n*k) time.
 *
 * High-Level Summary:
 * ----
 * We'll use a variant of the Bellman-Ford algorithm—a classic algorithm for
 * shortest path in a weighted, directed graph. The twist: we only allow up to
 * k+1 "edges" (flights). Bellman-Ford's key insight is that the cheapest path
 * using at most t flights can be built by taking the best path for each city
 * using at most t-1 flights, and relaxing all possible flights. We'll
 * initialize an array of size n (for each city) with "infinite" cost except the
 * source (cost 0), and repeat the process for k+1 times ('relaxing' prices for
 * one additional step each outer loop). At the end, the minimum price to the
 * destination after k+1 "flights" is our answer. The time complexity is O(k *
 * flights.size()), and space is O(n).
 */

#include <climits> // For using INT_MAX as infinite cost
#include <vector>  // Required for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    // Helper function to perform Bellman-Ford relaxation for up to k+1 flights
    auto bellmanFordLimitedStops = [&](int stops) -> int {
      // `prices` stores the cheapest cost to reach each city with at most the
      // current number of stops
      vector<int> prices(n, INT_MAX); // Initially, all cities are unreachable
      prices[src] = 0; // Price to reach the source city is always zero

      // We perform relaxation for `stops+1` times because k stops == k+1
      // flights/edges
      for (int i = 0; i <= stops; ++i) {
        // Make a copy for the current iteration, so we don't affect other
        // updates within this round
        vector<int> tmp_prices = prices;

        // Iterate through each flight (edge), attempting to improve route cost
        for (const auto &flight : flights) {
          int from = flight[0];
          int to = flight[1];
          int price = flight[2];
          // If the "from" city is currently reachable (has a known price),
          // consider the connection
          if (prices[from] != INT_MAX) {
            // If traveling to the "to" city via this flight would reduce the
            // cost, update
            if (tmp_prices[to] > prices[from] + price) {
              tmp_prices[to] = prices[from] + price;
            }
          }
        }
        // Move updated step forward for the next round of relaxations
        prices = tmp_prices;
      }
      // If destination is still "infinite", there is no valid route with k
      // stops
      return prices[dst] == INT_MAX ? -1 : prices[dst];
    };

    // Call our helper. We pass k, the max number of allowed stops
    return bellmanFordLimitedStops(k);
  }
};
// @lc code=end
