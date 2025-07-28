/*
 * @lc app=leetcode id=2273 lang=cpp
 *
 * [2273] Find Resultant Array After Removing Anagrams
 */

// @lc code=start
class Solution {
public:
  vector<string> removeAnagrams(vector<string> &words) {
    vector<string> res;
    for (int i = 0; i < words.size(); ++i) {
      if (res.empty()) {
        res.push_back(words[i]);
      } else {
        string prev = res.back();
        string curr = words[i];
        sort(prev.begin(), prev.end());
        sort(curr.begin(), curr.end());
        if (prev != curr) {
          res.push_back(words[i]);
        }
      }
    }
    return res;
  }
};
// @lc code=end
