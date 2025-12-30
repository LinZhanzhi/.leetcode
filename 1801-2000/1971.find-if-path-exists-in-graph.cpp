/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    // Use Union-Find (Disjoint Set Union) to efficiently determine if source
    // and destination are connected
    vector<int> parent(n);
    for (int i = 0; i < n; ++i)
      parent[i] = i;

    function<int(int)> find = [&](int x) {
      if (parent[x] != x)
        parent[x] = find(parent[x]);
      return parent[x];
    };

    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1];
      parent[find(u)] = find(v);
    }

    return find(source) == find(destination);
  }
};
// @lc code=end
