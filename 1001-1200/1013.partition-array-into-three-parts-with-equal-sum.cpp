/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
class Solution {
public:
  bool canThreePartsEqualSum(vector<int> &arr) {
    int total = 0;
    for (int num : arr)
      total += num;
    if (total % 3 != 0)
      return false;
    int target = total / 3;
    int sum = 0, count = 0;
    for (int i = 0; i < arr.size(); ++i) {
      sum += arr[i];
      if (sum == target) {
        ++count;
        sum = 0;
        // To ensure three non-empty parts, we only check for two partitions
        // before the end
        if (count == 2 && i < arr.size() - 1)
          return true;
      }
    }
    return false;
  }
};
// @lc code=end
