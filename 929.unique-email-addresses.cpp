/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
class Solution {
public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> uniqueEmails;
    for (const string &email : emails) {
      string local, domain;
      int atPos = email.find('@');
      local = email.substr(0, atPos);
      domain = email.substr(atPos + 1);

      string processedLocal;
      for (char c : local) {
        if (c == '+')
          break;
        if (c == '.')
          continue;
        processedLocal += c;
      }

      uniqueEmails.insert(processedLocal + "@" + domain);
    }
    return uniqueEmails.size();
  }
};
// @lc code=end
