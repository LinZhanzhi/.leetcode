/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

// @lc code=start
class Solution {
public:
  vector<int> diStringMatch(string s) {
    vector<int> perm;
    int low = 0, high = s.size();
    for (char c : s) {
      if (c == 'I') {
        perm.push_back(low++);
      } else { // c == 'D'
        perm.push_back(high--);
      }
    }
    perm.push_back(low); // low == high here
    return perm;
  }
};
// @lc code=end
