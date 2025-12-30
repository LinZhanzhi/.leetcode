/*
 * @lc app=leetcode id=3477 lang=cpp
 *
 * [3477] Fruits Into Baskets II
 */

// @lc code=start
class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = fruits.size();
    vector<bool> used(n, false);
    int unplaced = 0;
    for (int i = 0; i < n; ++i) {
      bool placed = false;
      for (int j = 0; j < n; ++j) {
        if (!used[j] && baskets[j] >= fruits[i]) {
          used[j] = true;
          placed = true;
          break;
        }
      }
      if (!placed)
        ++unplaced;
    }
    return unplaced;
  }
};
// @lc code=end
