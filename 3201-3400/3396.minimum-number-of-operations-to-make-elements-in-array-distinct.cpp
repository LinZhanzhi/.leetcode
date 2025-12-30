/*
 * @lc app=leetcode id=3396 lang=cpp
 *
 * [3396] Minimum Number of Operations to Make Elements in Array Distinct
 */

// @lc code=start
class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int n = nums.size();
    int cnt3 = n / 3;
    int rem = n % 3;
    int times = cnt3 + (rem > 0);
    int nowtimes = times;
    unordered_map<int, int> freq;
    if (rem > 0) {
      for (int i = 0; i < rem; ++i) {
        int v = nums.back();
        nums.pop_back();
        freq[v]++;
        if (freq[v] > 1) {
          return nowtimes;
        }
      }
      --nowtimes;
    }
    while (nowtimes > 0) {
      for (int i = 0; i < 3; ++i) {
        int v = nums.back();
        nums.pop_back();
        freq[v]++;
        if (freq[v] > 1) {
          return nowtimes;
        }
      }
      --nowtimes;
    }
    return nowtimes;
  }
};
// @lc code=end