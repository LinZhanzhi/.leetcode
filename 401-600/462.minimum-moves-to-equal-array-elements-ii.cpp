/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to make all elements in an integer array equal using the fewest
 * possible moves, where each move increments or decrements a single element
 * by 1. The challenge is to determine the optimal value to which all elements
 * should be changed, and then calculate the total number of moves required to
 * achieve this.
 *
 * High-Level Summary:
 * ----
 * The optimal strategy is to make all elements equal to the median of the
 * array. This is because the sum of absolute differences (which represents the
 * total moves) is minimized at the median. The solution involves sorting the
 * array to find the median, then summing the absolute differences between each
 * element and the median. Sorting takes O(n log n) time, and the rest is O(n),
 * so the overall time complexity is O(n log n). Space complexity is O(1) if
 * sorting in-place.
 */

#include <algorithm> // Include algorithm for std::sort and std::nth_element
#include <cstdlib>   // Include cstdlib for std::abs
#include <vector>    // Include vector for using std::vector

using std::vector;

class Solution {
public:
  // Main function to compute the minimum number of moves
  int minMoves2(vector<int> &nums) {
    // Find the median of the array, which minimizes the sum of absolute
    // differences.
    int median = findMedian(nums);

    // Calculate the total moves required to make all elements equal to the
    // median.
    return totalMovesToMedian(nums, median);
  }

private:
  // Helper function to find the median of the array.
  int findMedian(vector<int> &nums) {
    int n = nums.size();
    // Use nth_element to find the median in O(n) average time.
    // For even n, either middle value works (problem allows any).
    auto mid_iter = nums.begin() + n / 2;
    std::nth_element(nums.begin(), mid_iter, nums.end());
    return *mid_iter;
  }

  // Helper function to compute the total moves to make all elements equal to
  // the median.
  int totalMovesToMedian(const vector<int> &nums, int median) {
    int totalMoves = 0;
    // For each element, add the absolute difference to the median.
    for (int num : nums) {
      totalMoves += std::abs(num - median);
    }
    return totalMoves;
  }
};
// @lc code=end
