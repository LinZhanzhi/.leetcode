/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    if (s.length() < 10)
      return result;
    unordered_map<string, int> seen;
    for (size_t i = 0; i + 9 < s.length(); ++i) {
      string sub = s.substr(i, 10);
      seen[sub]++;
    }
    for (const auto &p : seen) {
      if (p.second > 1) {
        result.push_back(p.first);
      }
    }
    return result;
  }
};
// @lc code=end
