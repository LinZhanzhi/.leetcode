/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  int minOperations(string s) {
    int n = s.size();
    int diff = 0;
    for (int i = 0; i < n; ++i) {
      // If index parity matches char, it's correct for "0101..." pattern
      if (s[i] - '0' != i % 2)
        diff++;
    }
    // diff: changes needed for "0101...", n-diff: for "1010..."
    return min(diff, n - diff);
  }
};
// @lc code=end
