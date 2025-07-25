/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
class Solution {
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr) {
    // The problem reduces to checking if both arrays have the same multiset of
    // elements, since any permutation can be achieved by reversing subarrays.
    sort(target.begin(), target.end());
    sort(arr.begin(), arr.end());
    return target == arr;
  }
};
// @lc code=end
