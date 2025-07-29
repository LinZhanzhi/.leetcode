/*
 * @lc app=leetcode id=2475 lang=cpp
 *
 * [2475] Number of Unequal Triplets in Array
 */

// @lc code=start
class Solution {
public:
  int unequalTriplets(vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }
    vector<int> counts;
    for (auto &p : freq) {
      counts.push_back(p.second);
    }
    int n = nums.size();
    int res = 0;
    int left = 0;
    for (int i = 0; i < counts.size(); ++i) {
      for (int j = i + 1; j < counts.size(); ++j) {
        for (int k = j + 1; k < counts.size(); ++k) {
          res += counts[i] * counts[j] * counts[k];
        }
      }
    }
    return res;
  }
};
// @lc code=end
