/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks: Given an array of integers, how many moves does it take to
 * make all elements equal if, in each move, you can increment every element
 * except one by 1? The key insight is that incrementing n-1 elements by 1 is
 * equivalent to decrementing one element by 1. So, the problem reduces to: How
 * many total decrements are needed to make all elements equal to the smallest
 * value in the array?
 *
 * High-Level Summary:
 * ----
 * The optimal strategy is to make all elements equal to the minimum value in
 * the array. For each element, the number of moves needed is its difference
 * from the minimum. Summing these differences for all elements gives the
 * answer.
 *
 * Algorithm Steps:
 *   1. Find the minimum value in the array.
 *   2. For each element, compute the difference between it and the minimum.
 *   3. Sum all these differences to get the total number of moves.
 *
 * Time Complexity: O(n), where n is the number of elements in the array (one
 * pass to find min, one pass to sum). Space Complexity: O(1), as only a few
 * variables are used regardless of input size.
 */

#include <algorithm> // Include algorithm for std::min_element
#include <vector>    // Include vector for std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to compute the minimum number of moves
  int minMoves(vector<int> &nums) {
    // Find the minimum value in the array
    int minVal = findMin(nums);

    // Calculate the total number of moves required
    return totalMovesToMin(nums, minVal);
  }

private:
  // Helper function to find the minimum value in the array
  int findMin(const vector<int> &nums) {
    // Use std::min_element to efficiently find the minimum
    // std::min_element returns an iterator to the smallest element
    return *std::min_element(nums.begin(), nums.end());
  }

  // Helper function to sum the differences between each element and the minimum
  int totalMovesToMin(const vector<int> &nums, int minVal) {
    int moves = 0; // Initialize the move counter
    // Iterate through each element in the array
    for (int num : nums) {
      // For each element, add the difference to the move counter
      // This represents the number of decrements needed for this element
      moves += (num - minVal);
    }
    return moves; // Return the total number of moves
  }
};
// @lc code=end
