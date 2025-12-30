/*
 * @lc app=leetcode id=1619 lang=cpp
 *
 * [1619] Mean of Array After Removing Some Elements
 */

// @lc code=start
class Solution {
public:
  double trimMean(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int remove = n / 20; // 5% of n
    int start = remove;
    int end = n - remove;
    double sum = 0;
    for (int i = start; i < end; ++i) {
      sum += arr[i];
    }
    return sum / (end - start);
  }
};
// @lc code=end
