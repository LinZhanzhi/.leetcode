/*
 * @lc app=leetcode id=3069 lang=cpp
 *
 * [3069] Distribute Elements Into Two Arrays I
 */

// @lc code=start
class Solution {
public:
  vector<int> resultArray(vector<int> &nums) {
    vector<int> arr1, arr2;
    int n = nums.size();
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    for (int i = 2; i < n; ++i) {
      if (arr1.back() > arr2.back()) {
        arr1.push_back(nums[i]);
      } else {
        arr2.push_back(nums[i]);
      }
    }
    vector<int> result;
    result.insert(result.end(), arr1.begin(), arr1.end());
    result.insert(result.end(), arr2.begin(), arr2.end());
    return result;
  }
};
// @lc code=end
