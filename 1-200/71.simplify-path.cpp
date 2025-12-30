/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
  string simplifyPath(string path) {
    vector<string> stack;
    int n = path.size();
    int i = 0;
    while (i < n) {
      // Skip consecutive slashes
      while (i < n && path[i] == '/')
        i++;
      if (i == n)
        break;
      int start = i;
      while (i < n && path[i] != '/')
        i++;
      string part = path.substr(start, i - start);
      if (part == "." || part == "") {
        // do nothing, skip
        continue;
      } else if (part == "..") {
        if (!stack.empty())
          stack.pop_back();
      } else {
        stack.push_back(part);
      }
    }
    string res = "/";
    for (int j = 0; j < stack.size(); ++j) {
      res += stack[j];
      if (j != stack.size() - 1)
        res += "/";
    }
    return res;
  }
};
// @lc code=end
