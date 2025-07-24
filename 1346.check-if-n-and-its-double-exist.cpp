/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    unordered_set<int> seen;
    for (int num : arr) {
      if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
        return true;
      }
      seen.insert(num);
    }
    return false;
  }
};
// @lc code=end
