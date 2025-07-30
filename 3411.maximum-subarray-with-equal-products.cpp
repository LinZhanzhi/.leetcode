/*
 * @lc app=leetcode id=3411 lang=cpp
 *
 * [3411] Maximum Subarray With Equal Products
 */

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maxLength(vector<int> &nums) {
    int n = nums.size();
    int maxlen = 0;
    for (int i = 0; i < n; ++i) {
      long long prod = 1;
      int g = nums[i];
      int l = nums[i];
      for (int j = i; j < n; ++j) {
        prod *= nums[j];
        g = std::gcd(g, nums[j]);
        l = l / std::gcd(l, nums[j]) * nums[j];
        if (prod == 1LL * l * g) {
          maxlen = std::max(maxlen, j - i + 1);
        }
        // Early break if prod gets too large (to avoid overflow)
        if (prod > 1e12)
          break;
      }
    }
    return maxlen;
  }
};
// @lc code=end
