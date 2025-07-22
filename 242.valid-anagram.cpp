/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
  bool isAnagram(const string &s, const string &t) {
    if (s.size() != t.size())
      return false;
    int freq[26] = {0};
    for (size_t i = 0; i < s.size(); ++i) {
      ++freq[s[i] - 'a'];
      --freq[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (freq[i] != 0)
        return false;
    }
    return true;
  }
};
/*
unicode version
#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        for (char c : t) count[c]--;
        for (auto& kv : count)
            if (kv.second != 0) return false;
        return true;
    }
};
*/
// @lc code=end
