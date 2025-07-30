/*
 * @lc app=leetcode id=3502 lang=cpp
 *
 * [3502] Minimum Cost to Reach Every Position
 */

// @lc code=start
class Solution {
public:
  vector<int> minCosts(vector<int> &cost) {
    int n = cost.size();
    vector<int> answer(n, INT_MAX);

    // The idea: For each position i, the minimum cost to reach i is the minimum
    // cost among all cost[j] where j <= i. Because after swapping with j, you
    // can reach any position <= j for free.
    int min_cost = INT_MAX;
    for (int i = 0; i < n; ++i) {
      min_cost = min(min_cost, cost[i]);
      answer[i] = min_cost;
    }
    return answer;
  }
};
// @lc code=end
