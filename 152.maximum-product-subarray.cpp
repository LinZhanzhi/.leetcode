/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.empty())
      return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      int curr = nums[i];
      int tempMax = max({curr, maxProd * curr, minProd * curr});
      int tempMin = min({curr, maxProd * curr, minProd * curr});
      maxProd = tempMax;
      minProd = tempMin;
      result = max(result, maxProd);
    }
    return result;
  }
};
// @lc code=end
