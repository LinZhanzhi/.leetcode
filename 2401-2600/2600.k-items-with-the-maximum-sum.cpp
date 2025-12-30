/*
 * @lc app=leetcode id=2600 lang=cpp
 *
 * [2600] K Items With the Maximum Sum
 */

// @lc code=start
class Solution {
public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int takeOnes = std::min(numOnes, k);
    k -= takeOnes;
    int takeZeros = std::min(numZeros, k);
    k -= takeZeros;
    int takeNegOnes = k; // whatever is left, must be taken from -1s
    return takeOnes * 1 + takeZeros * 0 + takeNegOnes * -1;
  }
};
// @lc code=end
