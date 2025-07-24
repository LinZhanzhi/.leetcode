/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {
    auto countBits = [](int x) {
      int count = 0;
      while (x) {
        count += x & 1;
        x >>= 1;
      }
      return count;
    };
    sort(arr.begin(), arr.end(), [&](int a, int b) {
      int ca = countBits(a), cb = countBits(b);
      if (ca == cb)
        return a < b;
      return ca < cb;
    });
    return arr;
  }
};
// @lc code=end
