/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given an array of integers (possibly with duplicates). For any given
 * target value, we need to randomly pick and return one of the indices where
 * the target appears in the array. Each valid index must have an equal chance
 * of being chosen. The array is fixed after construction, and we may be asked
 * to pick indices for different targets multiple times.
 *
 * High-Level Summary:
 * ----
 * The solution uses the "Reservoir Sampling" algorithm to ensure each index of
 * the target value is picked with equal probability, without extra space for
 * storing all indices. When pick(target) is called, we scan through the array,
 * and for each occurrence of the target, we randomly decide whether to select
 * its index, updating our choice as we go. This ensures uniform randomness. The
 * constructor stores the input array for repeated use. Time complexity for pick
 * is O(N), where N is the array size. Space complexity is O(N) for storing the
 * array.
 */

// @lc code=start
#include <cstdlib> // For rand()
#include <vector>  // For std::vector

using std::vector;

class Solution {
private:
  vector<int> nums; // Store the input array for repeated pick queries

public:
  // Constructor: Store the input array for later use
  Solution(vector<int> &nums) {
    // Copy the input array to the member variable
    this->nums = nums;
  }

  // Randomly pick an index where nums[index] == target, with equal probability
  int pick(int target) {
    int count = 0;   // Counts how many times we've seen the target so far
    int result = -1; // Stores the currently selected index

    // Iterate through the array to find all indices of the target
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        // For the k-th occurrence, select it with probability 1/k
        // rand() % (++count) == 0 returns true with probability 1/count
        ++count;
        if (rand() % count == 0) {
          result = i; // Update result to current index
        }
      }
    }
    // After the loop, result holds a randomly chosen index of the target
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
