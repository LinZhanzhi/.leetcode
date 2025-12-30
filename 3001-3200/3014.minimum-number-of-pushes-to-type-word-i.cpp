/*
 * @lc app=leetcode id=3014 lang=cpp
 *
 * [3014] Minimum Number of Pushes to Type Word I
 */

// @lc code=start
class Solution {
public:
  int minimumPushes(string word) {
    // len of word
    int len = word.size();
    // count how many 8 is in len
    int cnt8 = len / 8;
    // remainder that don't meet 8
    int rem = len % 8;
    // first 8 letters use 1 * 8 push, next 8 letters use 2 * 8 pushes, etc.
    // so the cost is 1 * 8 + 2 * 8 + ... + cnt8 * 8
    int cost = (1 + cnt8) * cnt8 * 8 / 2;
    // the remaining letters use (cnt8 + 1) push each
    cost += (cnt8 + 1) * rem;
    return cost;
  }
};
// @lc code=end
