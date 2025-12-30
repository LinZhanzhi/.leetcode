/*
 * @lc app=leetcode id=2389 lang=cpp
 *
 * [2389] Longest Subsequence With Limited Sum
 */

// @lc code=start
class Solution {
public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    vector<int> answer;
    for (int q : queries) {
      // Find the largest k such that prefix[k] <= q
      int left = 0, right = n;
      while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (prefix[mid] <= q) {
          left = mid;
        } else {
          right = mid - 1;
        }
      }
      answer.push_back(left);
    }
    return answer;
  }
};
// @lc code=end
