/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int missing = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      missing ^= i ^ nums[i];
    }
    return missing;
  }
};
// @lc code=end
