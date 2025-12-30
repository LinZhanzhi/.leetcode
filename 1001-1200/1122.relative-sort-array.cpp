/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> count;
    for (int num : arr1) {
      count[num]++;
    }
    vector<int> result;
    // Add elements in arr2 order
    for (int num : arr2) {
      while (count[num] > 0) {
        result.push_back(num);
        count[num]--;
      }
    }
    // Add remaining elements sorted
    vector<int> rest;
    for (auto &[num, cnt] : count) {
      while (cnt-- > 0) {
        rest.push_back(num);
      }
    }
    sort(rest.begin(), rest.end());
    result.insert(result.end(), rest.begin(), rest.end());
    return result;
  }
};
// @lc code=end
