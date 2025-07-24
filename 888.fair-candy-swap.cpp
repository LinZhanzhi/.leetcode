/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
 */

// @lc code=start
class Solution {
public:
  vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
    int sumA = 0, sumB = 0;
    for (int a : aliceSizes)
      sumA += a;
    for (int b : bobSizes)
      sumB += b;
    int delta = (sumB - sumA) / 2; // Bob needs to give delta more to Alice

    unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
    for (int a : aliceSizes) {
      int b = a + delta;
      if (bobSet.count(b)) {
        return {a, b};
      }
    }
    return {}; // Should never reach here due to problem guarantee
  }
};
// @lc code=end
