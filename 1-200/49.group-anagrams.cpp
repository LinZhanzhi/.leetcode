/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mp;
    for (const string &s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto &p : mp) {
      result.push_back(move(p.second));
    }
    return result;
  }
};
// @lc code=end
