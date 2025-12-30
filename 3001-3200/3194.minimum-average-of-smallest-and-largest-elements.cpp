/*
 * @lc app=leetcode id=3194 lang=cpp
 *
 * [3194] Minimum Average of Smallest and Largest Elements
 */

// @lc code=start
class Solution {
public:
  double minimumAverage(vector<int> &nums) {
    vector<double> averages;
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      double avg = (nums[left] + nums[right]) / 2.0;
      averages.push_back(avg);
      left++;
      right--;
    }
    return *min_element(averages.begin(), averages.end());
  }
};
// @lc code=end
