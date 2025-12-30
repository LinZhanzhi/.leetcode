/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start

#include <unordered_map> // Required for hash map
#include <unordered_set> // Required for hash set
#include <vector>        // Required for std::vector

using std::vector;

//
// Brief Digested Understanding:
// ----
// The main challenge here is to maximize the number of stones removed from the
// board, where the rule is: a stone can be removed if another stone is in the
// same row or column. In effect, stones are "connected" if they share a row or
// column, and as long as there's at least one other stone in their group, we
// can always keep removing stones until one remains. So, the problem is to find
// the number of distinct connected groups (islands) formed by sharing rows or
// columns. The answer will be the total stones minus the number of such groups.
//
// High-Level Summary:
// ----
// We'll treat stones as nodes and connect them if they share a row or column,
// forming connected components. Using Union-Find (Disjoint Set Union, DSU), we
// can efficiently merge groups as we process each stone. The minimum stones we
// must keep is equal to the number of groups, so the answer is total stones
// minus this value. We'll use a hash map for DSU parents since coordinates can
// be large (up to 10^4). Expected time complexity is O(N*α(N)), with nearly
// linear space and time, where α() is the inverse Ackermann function
// (essentially constant).
//

// Implementation of Union-Find (Disjoint Set Union) using hash map
class DSU {
  // This DSU maps each integer node to its parent.
  // We represent x-coordinates and y-coordinates as different keys by
  // offsetting y-coordinates. This way, connecting stones that share a row or
  // column is easy.
private:
  std::unordered_map<int, int> parent;

  // Find operation with path compression for efficiency
  int find(int x) {
    // If x is not yet in the parent map, it is its own parent
    if (!parent.count(x))
      parent[x] = x;
    // If x is not its own parent, recursively find and compress the path
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

public:
  // Unite the sets containing x and y
  void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    // If roots differ, merge fy into fx
    if (fx != fy)
      parent[fx] = fy;
  }

  // Used to collect all unique roots (for counting components later)
  void add(int x) { find(x); }

  // Counts the number of unique roots (connected groups)
  int count_unique_roots() {
    std::unordered_set<int> roots;
    for (const auto &kv : parent) {
      roots.insert(find(kv.first));
    }
    return roots.size();
  }
};

// Main solution class as required by LeetCode
class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    const int Y_OFFSET =
        100001; // Guarantee x and y always map to different keys
    DSU dsu;

    // Step 1: For each stone, unite its x and y (offset y so there's no
    // collision)
    for (const auto &stone : stones) {
      int x = stone[0];
      int y = stone[1] + Y_OFFSET; // Offset y to avoid key collision with x
      dsu.unite(x, y);
      // (Optionally force-initialize both)
      dsu.add(x);
      dsu.add(y);
    }

    // Step 2: The number of unique roots is the number of connected groups
    int num_groups = dsu.count_unique_roots();

    // Step 3: The max stones we can remove is total count minus the number of
    // groups
    return static_cast<int>(stones.size()) - num_groups;
  }
};
// @lc code=end
