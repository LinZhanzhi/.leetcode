/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
#include <queue>
class RecentCounter {
public:
  std::queue<int> q;
  RecentCounter() {}

  int ping(int t) {
    q.push(t);
    while (!q.empty() && q.front() < t - 3000) {
      q.pop();
    }
    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
