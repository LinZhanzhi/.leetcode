/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <algorithm> // Include algorithm for std::max_element
#include <vector>    // Include vector for std::vector

using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * The core of this problem is to build a binary tree from an array of unique
 * integers, where each node is the maximum value in its subarray, and its left
 * and right children are recursively built from the subarrays to the left and
 * right of that maximum value. The process continues until the subarrays are
 * empty, at which point the recursion stops. The result is a binary tree where
 * the root is always the largest value, and each subtree is built in the same
 * way from the remaining elements.
 *
 * High-Level Summary:
 * ----
 * To solve this, we use a recursive approach:
 *   - For a given subarray, find the index of the maximum value.
 *   - Create a tree node with that value.
 *   - Recursively build the left subtree from the elements before the maximum.
 *   - Recursively build the right subtree from the elements after the maximum.
 *   - The recursion base case is when the subarray is empty (left > right), in
 * which case we return nullptr. This approach ensures that each node is
 * constructed according to the problem's rules. The time complexity is O(n^2)
 * in the worst case (e.g., sorted input), since for each node we may scan a
 * linear subarray. The space complexity is O(n) for the recursion stack and the
 * tree nodes.
 */

// Helper function to find the index of the maximum element in nums between left
// and right (inclusive)
int findMaxIndex(const vector<int> &nums, int left, int right) {
  // Initialize maxIndex to left
  int maxIndex = left;
  // Iterate through the subarray to find the maximum value's index
  for (int i = left + 1; i <= right; ++i) {
    if (nums[i] > nums[maxIndex]) {
      maxIndex = i;
    }
  }
  return maxIndex;
}

// Helper function to recursively build the maximum binary tree from
// nums[left...right]
TreeNode *buildTree(const vector<int> &nums, int left, int right) {
  // Base case: if the subarray is empty, return nullptr (no node)
  if (left > right) {
    return nullptr;
  }
  // Find the index of the maximum value in the current subarray
  int maxIndex = findMaxIndex(nums, left, right);
  // Create a new tree node with the maximum value
  TreeNode *node = new TreeNode(nums[maxIndex]);
  // Recursively build the left subtree from elements before the maximum
  node->left = buildTree(nums, left, maxIndex - 1);
  // Recursively build the right subtree from elements after the maximum
  node->right = buildTree(nums, maxIndex + 1, right);
  // Return the constructed node
  return node;
}

class Solution {
public:
  // Main function to construct the maximum binary tree from the input vector
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    // Call the recursive helper on the full array (indices 0 to nums.size()-1)
    return buildTree(nums, 0, nums.size() - 1);
  }
};
// @lc code=end
