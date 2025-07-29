/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    int min_ops = k; // maximum possible is k (all W's)
    int white_count = 0;
    // Count whites in the first window
    for (int i = 0; i < k; ++i) {
      if (blocks[i] == 'W')
        white_count++;
    }
    min_ops = white_count;
    // Slide the window
    for (int i = k; i < n; ++i) {
      if (blocks[i - k] == 'W')
        white_count--;
      if (blocks[i] == 'W')
        white_count++;
      if (white_count < min_ops)
        min_ops = white_count;
    }
    return min_ops;
  }
};
// @lc code=end
