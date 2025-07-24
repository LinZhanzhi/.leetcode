/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution {
public:
  int maxNumberOfBalloons(string text) {
    vector<int> count(26, 0);
    for (char c : text) {
      count[c - 'a']++;
    }
    // "balloon" needs: b:1, a:1, l:2, o:2, n:1
    int res = min({count['b' - 'a'], count['a' - 'a'], count['l' - 'a'] / 2,
                   count['o' - 'a'] / 2, count['n' - 'a']});
    return res;
  }
};
// @lc code=end
