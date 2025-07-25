/*
 * @lc app=leetcode id=1640 lang=cpp
 *
 * [1640] Check Array Formation Through Concatenation
 */

// @lc code=start
class Solution {
public:
  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    // INSERT_YOUR_REWRITE_HERE
    // Optimize for memory and runtime by using pointers and avoiding
    // unnecessary copies
    unordered_map<int, const vector<int> *> mp;
    for (const auto &piece : pieces) {
      if (!piece.empty()) {
        mp[piece[0]] = &piece;
      }
    }
    int i = 0, n = arr.size();
    while (i < n) {
      auto it = mp.find(arr[i]);
      if (it == mp.end())
        return false;
      const vector<int> *p = it->second;
      for (int num : *p) {
        if (i >= n || arr[i] != num)
          return false;
        ++i;
      }
    }
    return true;
  }
};
// @lc code=end
