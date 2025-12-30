/*
 * @lc app=leetcode id=2103 lang=cpp
 *
 * [2103] Rings and Rods
 */

// @lc code=start
class Solution {
public:
  int countPoints(string rings) {
    // INSERT_YOUR_CODE
    // We will use an array of 10 integers to represent the rods.
    // Each bit in the integer will represent a color: 0b001 = R, 0b010 = G,
    // 0b100 = B
    int rods[10] = {0};
    for (int i = 0; i < rings.size(); i += 2) {
      char color = rings[i];
      int rod = rings[i + 1] - '0';
      if (color == 'R') {
        rods[rod] |= 0b001;
      } else if (color == 'G') {
        rods[rod] |= 0b010;
      } else if (color == 'B') {
        rods[rod] |= 0b100;
      }
    }
    int count = 0;
    for (int i = 0; i < 10; ++i) {
      if (rods[i] == 0b111) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end
