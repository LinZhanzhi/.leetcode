/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {
    unordered_set<int> seen;
    for (int num : nums) {
      if (seen.count(num)) {
        return num;
      }
      seen.insert(num);
    }
    return -1; // Should never reach here
  }
};
// @lc code=end
