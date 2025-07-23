/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
class Solution {
public:
  vector<int> constructRectangle(int area) {
    int W = (int)sqrt(area);
    while (area % W != 0) {
      W--;
    }
    int L = area / W;
    return {L, W};
  }
};
// @lc code=end
