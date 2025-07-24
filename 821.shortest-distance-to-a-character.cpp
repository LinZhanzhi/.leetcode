/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> answer(n, n); // initialize with max possible distance

    // First pass: left to right
    int prev = -n;
    for (int i = 0; i < n; ++i) {
      if (s[i] == c)
        prev = i;
      answer[i] = abs(i - prev);
    }

    // Second pass: right to left
    prev = 2 * n;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == c)
        prev = i;
      answer[i] = min(answer[i], abs(i - prev));
    }

    return answer;
  }
};
// @lc code=end
