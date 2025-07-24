/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start
class Solution {
public:
  vector<int> decompressRLElist(vector<int> &nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i += 2) {
      int freq = nums[i];
      int val = nums[i + 1];
      result.insert(result.end(), freq, val);
    }
    return result;
  }
};
// @lc code=end
