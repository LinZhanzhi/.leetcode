/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */

// @lc code=start
class Solution {
public:
  int countLargestGroup(int n) {
    vector<int> count(37, 0); // max digit sum for n <= 10000 is 9+9+9+9=36
    for (int i = 1; i <= n; ++i) {
      int sum = 0, x = i;
      while (x) {
        sum += x % 10;
        x /= 10;
      }
      count[sum]++;
    }
    int max_size = *max_element(count.begin(), count.end());
    int res = 0;
    for (int c : count) {
      if (c == max_size)
        res++;
    }
    return res;
  }
};
// @lc code=end
