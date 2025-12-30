/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> lastSeen;
    for (int i = 0; i < nums.size(); ++i) {
      if (lastSeen.count(nums[i]) && i - lastSeen[nums[i]] <= k) {
        return true;
      }
      lastSeen[nums[i]] = i;
    }
    return false;
  }
};
// @lc code=end
