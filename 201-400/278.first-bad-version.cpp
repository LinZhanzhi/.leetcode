/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (isBadVersion(mid)) {
        // If mid is bad, the first bad version is at mid or before
        right = mid;
      } else {
        // If mid is good, the first bad version is after mid
        left = mid + 1;
      }
    }

    // At this point, left == right and points to the first bad version
    return left;
  }
};
// @lc code=end
