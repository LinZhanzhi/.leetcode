/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
  int uniquePaths(int m, int n) {
    // We can use combinatorics: the robot needs to make (m-1) downs and (n-1)
    // rights, in any order. The number of unique paths is C(m+n-2, m-1) =
    // (m+n-2)! / ((m-1)! * (n-1)!)
    long long res = 1;
    int N = m + n - 2;
    int k = min(m - 1, n - 1); // To minimize the number of multiplications
    for (int i = 1; i <= k; ++i) {
      res = res * (N - k + i) / i;
    }
    return (int)res;
  }
};
// @lc code=end
