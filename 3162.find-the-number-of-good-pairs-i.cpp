/*
 * @lc app=leetcode id=3162 lang=cpp
 *
 * [3162] Find the Number of Good Pairs I
 */

// @lc code=start
class Solution {
public:
  int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    int count = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        int d = nums2[j] * k;
        if (nums1[i] % d == 0) {
          ++count;
        }
      }
    }
    return count;
  }
};
// @lc code=end
