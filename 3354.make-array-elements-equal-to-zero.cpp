/*
 * @lc app=leetcode id=3354 lang=cpp
 *
 * [3354] Make Array Elements Equal to Zero
 */

// @lc code=start
class Solution {
public:
  // Simulates the process starting from index 'start' in direction 'dir'
  // Returns the resulting array after the process
  vector<int> simulateProcess(const vector<int> &nums, int start, int dir) {
    vector<int> arr = nums;
    int n = arr.size();
    int curr = start;
    int d = dir;
    while (curr >= 0 && curr < n) {
      if (arr[curr] == 0) {
        curr += d;
      } else if (arr[curr] > 0) {
        arr[curr]--;
        d = -d;
        curr += d;
      }
    }
    return arr;
  }

  // Checks if all elements in the array are zero
  bool isAllZero(const vector<int> &arr) {
    for (int x : arr) {
      if (x != 0) {
        return false;
      }
    }
    return true;
  }

  int countValidSelections(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    // For each position where nums[i] == 0, try both directions
    for (int i = 0; i < n; ++i) {
      if (nums[i] != 0)
        continue;
      for (int dir = -1; dir <= 1; dir += 2) { // dir = -1 (left), 1 (right)
        vector<int> arr = simulateProcess(nums, i, dir);
        if (isAllZero(arr))
          res++;
      }
    }
    return res;
  }
};
// @lc code=end
