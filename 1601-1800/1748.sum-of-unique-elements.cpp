/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

// @lc code=start
class Solution {
public:
  int sumOfUnique(vector<int> &nums) {
    int freq[101] = {0};
    for (int n : nums) {
      freq[n]++;
    }
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
      if (freq[i] == 1)
        sum += i;
    }
    return sum;
  }
};
// @lc code=end
