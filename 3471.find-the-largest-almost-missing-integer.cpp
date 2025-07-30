/*
 * @lc app=leetcode id=3471 lang=cpp
 *
 * [3471] Find the Largest Almost Missing Integer
 */

// @lc code=start
class Solution {
public:
  // Helper to update the appearance map for all elements with positive count in
  // subfreq
  void updateAppearances(const unordered_map<int, int> &subfreq,
                         unordered_map<int, int> &appear) {
    for (const auto &[x, c] : subfreq) {
      if (c > 0)
        appear[x]++;
    }
  }

  // Helper to find the largest integer that appears in exactly one substring
  int findLargestUnique(const unordered_map<int, int> &appear) {
    int res = -1;
    for (const auto &[x, c] : appear) {
      if (c == 1)
        res = max(res, x);
    }
    return res;
  }

  int largestInteger(vector<int> &nums, int k) {
    unordered_map<int, int> subfreq; // frequency in the substring
    unordered_map<int, int> appear;  // appearances in different substring

    int n = nums.size();
    // Initialize subfreq with the first window
    for (int i = 0; i < k; i++) {
      subfreq[nums[i]]++;
    }
    updateAppearances(subfreq, appear);

    // Slide the window and update subfreq and appear
    for (int i = 1; i < n && i + k - 1 < n; i++) {
      subfreq[nums[i - 1]]--;
      subfreq[nums[i + k - 1]]++;
      updateAppearances(subfreq, appear);
    }

    return findLargestUnique(appear);
  }
};
// @lc code=end
