/*
 * @lc app=leetcode id=2164 lang=cpp
 *
 * [2164] Sort Even and Odd Indices Independently
 */

// @lc code=start
class Solution {
public:
  vector<int> sortEvenOdd(vector<int> &nums) {
    vector<int> even, odd;
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 == 0)
        even.push_back(nums[i]);
      else
        odd.push_back(nums[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());
    int e = 0, o = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 == 0)
        nums[i] = even[e++];
      else
        nums[i] = odd[o++];
    }
    return nums;
  }
};
// @lc code=end
