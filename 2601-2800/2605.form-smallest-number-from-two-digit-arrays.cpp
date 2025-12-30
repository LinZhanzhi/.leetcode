/*
 * @lc app=leetcode id=2605 lang=cpp
 *
 * [2605] Form Smallest Number From Two Digit Arrays
 */

// @lc code=start
class Solution {
public:
  int minNumber(vector<int> &nums1, vector<int> &nums2) {
    // Find the smallest number that contains at least one digit from each array
    // If there is a common digit, return the smallest such digit
    // Otherwise, return the smallest two-digit number formed by picking one
    // digit from each array

    // Use sets for fast lookup
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    // Check for common digits
    int minCommon = 10;
    for (int d : nums1) {
      if (s2.count(d)) {
        minCommon = min(minCommon, d);
      }
    }
    if (minCommon != 10)
      return minCommon;

    // No common digit, so form the smallest two-digit number
    int min1 = *min_element(nums1.begin(), nums1.end());
    int min2 = *min_element(nums2.begin(), nums2.end());
    return min(min1 * 10 + min2, min2 * 10 + min1);
  }
};
// @lc code=end
