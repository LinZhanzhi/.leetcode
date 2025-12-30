/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
public:
  vector<int> addToArrayForm(vector<int> &num, int k) {
    vector<int> res;
    int i = num.size() - 1;
    while (i >= 0 || k > 0) {
      if (i >= 0) {
        k += num[i];
        i--;
      }
      res.push_back(k % 10);
      k /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
