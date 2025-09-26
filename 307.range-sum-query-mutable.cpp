/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to efficiently support two operations on an array:
 *   1. Update the value at a specific index.
 *   2. Query the sum of a subarray between two indices (inclusive).
 * Since both operations can be called up to 30,000 times and the array can be
 * large, a naive approach (recomputing sums each time) would be too slow. We
 * need a data structure that allows both fast updates and fast range sum
 * queries.
 */

/*
 * High-Level Summary:
 * ----
 * We use a Binary Indexed Tree (Fenwick Tree) to efficiently support both point
 * updates and prefix/range sum queries in O(log n) time. The Fenwick Tree
 * maintains prefix sums in a way that allows us to update a single element and
 * query the sum of any prefix quickly. For sumRange(left, right), we compute
 * prefixSum(right) - prefixSum(left-1). The class stores both the original
 * array (to compute the delta for updates) and the Fenwick Tree.
 *
 * Time Complexity:
 *   - update(index, val): O(log n)
 *   - sumRange(left, right): O(log n)
 * Space Complexity:
 *   - O(n) for the Fenwick Tree and a copy of the array.
 */

#include <vector> // Include vector for dynamic array support.
using std::vector;

// @lc code=start
class NumArray {
private:
  vector<int> bit;  // Binary Indexed Tree (Fenwick Tree) for prefix sums.
  vector<int> nums; // Store the original array to compute deltas on update.
  int n;            // Length of the input array.

  // Helper function to update the Fenwick Tree at position i by delta.
  void add(int i, int delta) {
    // Fenwick Tree is 1-indexed, so increment i by 1.
    ++i;
    // Update all relevant nodes in the tree.
    while (i <= n) {
      bit[i] += delta;
      // Move to the next responsible node.
      i += (i & -i);
    }
  }

  // Helper function to compute prefix sum from 0 to i (inclusive).
  int prefixSum(int i) {
    int res = 0;
    // Fenwick Tree is 1-indexed, so increment i by 1.
    ++i;
    // Traverse up the tree, accumulating sums.
    while (i > 0) {
      res += bit[i];
      // Move to parent node.
      i -= (i & -i);
    }
    return res;
  }

public:
  // Constructor: Initialize the Fenwick Tree and store the input array.
  NumArray(vector<int> &nums) {
    n = nums.size();
    this->nums = nums;           // Copy the input array for delta calculations.
    bit = vector<int>(n + 1, 0); // Fenwick Tree is 1-indexed.
    // Build the Fenwick Tree by adding each element.
    for (int i = 0; i < n; ++i) {
      add(i, nums[i]);
    }
  }

  // Update the value at index to val.
  void update(int index, int val) {
    int delta = val - nums[index]; // Compute the change needed.
    nums[index] = val;             // Update the stored value.
    add(index, delta);             // Apply the change to the Fenwick Tree.
  }

  // Return the sum of elements from left to right (inclusive).
  int sumRange(int left, int right) {
    // Use prefix sums to compute the range sum efficiently.
    return prefixSum(right) - prefixSum(left - 1);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
