/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;
    // Find the first index i from the end where nums[i] < nums[i+1].
    // This is the rightmost position where the current number can be increased
    // to form a larger permutation, because everything after i is in
    // non-increasing order (already the largest possible arrangement for that
    // suffix). By increasing nums[i], we can construct the next
    // lexicographically greater permutation. If no such i exists, the array is
    // already in the largest possible permutation. In this case, reversing the
    // entire array gives the smallest possible permutation, because the prefix
    // nums[0, i-1] is empty (i == -1), so the whole array is the suffix to
    // reverse. If i >= 0, we only reverse the suffix nums[i+1:] to get the
    // minimal arrangement for that part, while keeping nums[0, i] (the prefix)
    // as is.
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      i--;
    }
    if (i >= 0) {
      // Find the element just larger than nums[i] from the end.
      // Swapping nums[i] with this ensures we get the next larger permutation.
      int j = n - 1;
      while (nums[j] <= nums[i]) {
        j--;
      }
      // Swap them to make the sequence just larger at position i.
      std::swap(nums[i], nums[j]);
    }
    // Reverse the elements after i.
    // This puts the suffix in the smallest possible order, ensuring the next
    // permutation is minimal and just larger than the original.
    std::reverse(nums.begin() + i + 1, nums.end());
    //
    // Why does this give the next permutation?
    // - The suffix nums[i+1:] is in descending order, so the current
    // permutation is the largest for that prefix.
    // - By swapping nums[i] with the next larger element, we make the prefix
    // just larger.
    // - Reversing the suffix gives the smallest possible order for the new
    // prefix, so the result is the next lexicographical permutation.
  }
};
// @lc code=end
