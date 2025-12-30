/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &colors) {
    int n = colors.size();
    int maxDist = 0;
    // We only need to consider pairs where one house is at the leftmost or
    // rightmost position, because the maximum possible distance is achieved
    // when the two houses are as far apart as possible. So, we check all houses
    // against the leftmost and rightmost house to find the furthest with a
    // different color. Check from leftmost house to the rightmost house with
    // different color
    for (int i = 0; i < n; ++i) {
      if (colors[i] != colors[0]) {
        maxDist = max(maxDist, i);
      }
    }
    // Check from rightmost house to the leftmost house with different color
    for (int i = 0; i < n; ++i) {
      if (colors[i] != colors[n - 1]) {
        maxDist = max(maxDist, n - 1 - i);
      }
    }
    return maxDist;
  }
};
// @lc code=end
