/*
 * @lc app=leetcode id=2974 lang=cpp
 *
 * [2974] Minimum Number Game
 */

// @lc code=start
class Solution {
public:
  vector<int> numberGame(vector<int> &nums) {
    // INSERT_YOUR_CODE
    sort(nums.begin(), nums.end());
    vector<int> arr;
    int n = nums.size();
    for (int i = 0; i < n; i += 2) {
      // Alice removes nums[i] (min), Bob removes nums[i+1] (next min)
      // Bob appends his (nums[i+1]), then Alice appends hers (nums[i])
      arr.push_back(nums[i + 1]);
      arr.push_back(nums[i]);
    }
    return arr;
  }
};
// @lc code=end
