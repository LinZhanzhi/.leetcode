/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
public:
  void duplicateZeros(vector<int> &arr) {
    int n = arr.size();
    int zeros = 0;
    // First, count the number of zeros in the array.
    // This will help us determine how many elements need to be shifted.
    for (int i = 0; i < n; ++i) {
      if (arr[i] == 0)
        ++zeros;
    }
    // i: pointer to the current element in the original array (from the end)
    // j: pointer to the position in the "virtual" extended array (with
    // duplicated zeros)
    int i = n - 1;
    int j = n + zeros - 1;
    // Iterate backwards, moving and duplicating zeros as needed
    while (i < j) {
      // If j is within bounds, copy the element at i to position j
      if (j < n)
        arr[j] = arr[i];
      // If the current element is zero, we need to duplicate it
      if (arr[i] == 0) {
        --j;
        // Write the duplicated zero if j is within bounds
        if (j < n)
          arr[j] = 0;
      }
      --i;
      --j;
    }
  }
};
// @lc code=end
