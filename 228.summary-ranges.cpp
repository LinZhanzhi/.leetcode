/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> result;
    int n = nums.size();
    int i = 0;
    while (i < n) {
      int start = i;
      // Move i to the end of the current range
      while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
        i++;
      }
      if (start == i) {
        result.push_back(to_string(nums[start]));
      } else {
        result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
      }
      i++;
    }
    return result;
  }
};
// @lc code=end
