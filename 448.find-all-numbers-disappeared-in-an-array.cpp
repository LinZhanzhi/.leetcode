/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();
    // Mark each number as visited by negating the value at its corresponding
    // index
    for (int i = 0; i < n; ++i) {
      int idx =
          abs(nums[i]) - 1; // Get the index corresponding to the value nums[i]
      if (nums[idx] > 0) {
        nums[idx] = -nums[idx]; // Mark as visited by making it negative
      }
    }
    vector<int> res;
    // After marking, the indices with positive values correspond to missing
    // numbers
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        res.push_back(i + 1); // i+1 is missing since its index was never marked
      }
    }
    return res;
  }
};
// @lc code=end
