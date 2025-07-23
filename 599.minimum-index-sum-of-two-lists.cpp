/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    unordered_map<string, int> idx1;
    for (int i = 0; i < list1.size(); ++i) {
      idx1[list1[i]] = i;
    }
    vector<string> res;
    int min_sum = INT_MAX;
    for (int j = 0; j < list2.size(); ++j) {
      auto it = idx1.find(list2[j]);
      if (it != idx1.end()) {
        int sum = it->second + j;
        if (sum < min_sum) {
          res.clear();
          res.push_back(list2[j]);
          min_sum = sum;
        } else if (sum == min_sum) {
          res.push_back(list2[j]);
        }
      }
    }
    return res;
  }
};
// @lc code=end
