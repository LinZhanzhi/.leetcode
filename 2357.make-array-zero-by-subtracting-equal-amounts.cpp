/*
 * @lc app=leetcode id=2357 lang=cpp
 *
 * [2357] Make Array Zero by Subtracting Equal Amounts
 */

// @lc code=start
class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    // The minimum number of operations is equal to the number of unique
    // non-zero elements in nums.
    unordered_set<int> s;
    for (int num : nums) {
      if (num != 0)
        s.insert(num);
    }
    return s.size();
  }
};
// @lc code=end
