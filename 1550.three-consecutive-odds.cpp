/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  bool threeConsecutiveOdds(vector<int> &arr) {
    if (arr.size() < 3)
      return false;
    for (size_t i = 0; i + 2 < arr.size(); ++i) {
      if (arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2)
        return true;
    }
    return false;
  }
};
// @lc code=end
