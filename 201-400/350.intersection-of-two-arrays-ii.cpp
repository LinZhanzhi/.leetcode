/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> counts;
    vector<int> result;
    for (int num : nums1) {
      counts[num]++;
    }
    for (int num : nums2) {
      if (counts[num] > 0) {
        result.push_back(num);
        counts[num]--;
      }
    }
    return result;
  }

  // What if the given array is already sorted? How would you optimize your
  // algorithm?
  //   vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
  //     sort(nums1.begin(), nums1.end());
  //     sort(nums2.begin(), nums2.end());
  //     vector<int> result;
  //     int i = 0, j = 0;
  //     while (i < nums1.size() && j < nums2.size()) {
  //       if (nums1[i] < nums2[j]) {
  //         i++;
  //       } else if (nums1[i] > nums2[j]) {
  //         j++;
  //       } else {
  //         result.push_back(nums1[i]);
  //         i++;
  //         j++;
  //       }
  //     }
  //     return result;
  //   }
};
// @lc code=end
