/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
class Solution {
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    vector<pair<int, string>> people;
    int n = names.size();
    for (int i = 0; i < n; ++i) {
      people.push_back({heights[i], names[i]});
    }
    sort(people.rbegin(), people.rend());
    vector<string> result;
    for (const auto &p : people) {
      result.push_back(p.second);
    }
    return result;
  }
};
// @lc code=end
