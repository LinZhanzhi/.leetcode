/*
 * @lc app=leetcode id=2515 lang=cpp
 *
 * [2515] Shortest Distance to Target String in a Circular Array
 */

// @lc code=start
class Solution {
public:
  int closestTarget(vector<string> &words, string target, int startIndex) {
    int n = words.size();
    int minDist = n + 1;
    for (int i = 0; i < n; ++i) {
      if (words[i] == target) {
        int dist = abs(i - startIndex);
        dist = std::min(dist, n - dist);
        minDist = std::min(minDist, dist);
      }
    }
    return (minDist == n + 1) ? -1 : minDist;
  }
};
// @lc code=end
