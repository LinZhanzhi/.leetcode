/*
 * @lc app=leetcode id=3606 lang=cpp
 *
 * [3606] Coupon Code Validator
 */

// @lc code=start
class Solution {
public:
  vector<string> validateCoupons(vector<string> &code,
                                 vector<string> &businessLine,
                                 vector<bool> &isActive) {
    vector<string> validBusinessLines = {"electronics", "grocery", "pharmacy",
                                         "restaurant"};
    unordered_map<string, int> businessOrder = {
        {"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};
    vector<pair<int, string>> filtered; // (businessLine order, code)

    auto isValidCode = [](const string &s) {
      if (s.empty())
        return false;
      for (char c : s) {
        if (!(isalnum(c) || c == '_'))
          return false;
      }
      return true;
    };

    int n = code.size();
    for (int i = 0; i < n; ++i) {
      if (!isActive[i])
        continue;
      if (!isValidCode(code[i]))
        continue;
      if (businessOrder.find(businessLine[i]) == businessOrder.end())
        continue;
      filtered.emplace_back(businessOrder[businessLine[i]], code[i]);
    }

    // Sort by businessLine order, then code lex
    sort(filtered.begin(), filtered.end(),
         [](const pair<int, string> &a, const pair<int, string> &b) {
           if (a.first != b.first)
             return a.first < b.first;
           return a.second < b.second;
         });

    vector<string> result;
    for (auto &p : filtered) {
      result.push_back(p.second);
    }
    return result;
  }
};
// @lc code=end
