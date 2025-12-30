/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    int n = s.size();

    // Helper function to check if s[l..r] is a palindrome
    auto isPalindrome = [&](int l, int r) {
      while (l < r) {
        if (s[l] != s[r])
          return false;
        ++l;
        --r;
      }
      return true;
    };

    // Backtracking function
    function<void(int)> dfs = [&](int start) {
      if (start == n) {
        res.push_back(path);
        return;
      }
      for (int end = start; end < n; ++end) {
        if (isPalindrome(start, end)) {
          path.push_back(s.substr(start, end - start + 1));
          dfs(end + 1);
          path.pop_back();
        }
      }
    };

    dfs(0);
    return res;
  }
};
// @lc code=end
