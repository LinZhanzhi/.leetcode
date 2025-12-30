/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */

// @lc code=start
class Solution {
public:
  int countMatches(vector<vector<string>> &items, string ruleKey,
                   string ruleValue) {
    int idx = 0;
    if (ruleKey == "type")
      idx = 0;
    else if (ruleKey == "color")
      idx = 1;
    else if (ruleKey == "name")
      idx = 2;
    int count = 0;
    for (const auto &item : items) {
      if (item[idx] == ruleValue)
        ++count;
    }
    return count;
  }
};
// @lc code=end
