/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 */

// @lc code=start
class Solution {
public:
  long long pickGifts(vector<int> &gifts, int k) {
    priority_queue<int> pq(gifts.begin(), gifts.end());
    while (k-- > 0) {
      int top = pq.top();
      pq.pop();
      int reduced = (int)sqrt(top);
      pq.push(reduced);
    }
    long long sum = 0;
    while (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
    return sum;
  }
};
// @lc code=end
