/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
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

#include <algorithm> // For std::max
#include <string>    // For std::string
#include <vector>    // For std::vector

using std::string;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about visually representing a binary tree as a 2D string
 * matrix, where each node is placed in a specific position to reflect the
 * tree's structure. The root is centered at the top, and each child is placed
 * at calculated positions in the rows below, with empty strings filling unused
 * cells. The challenge is to compute the correct size of the matrix and
 * recursively place each node in its correct spot.
 *
 * High-Level Summary:
 * ----
 * To solve this, we first compute the height of the tree, which determines the
 * number of rows and columns in the result matrix. The number of columns is
 * always 2^(height+1) - 1. We then initialize the matrix with empty strings.
 * Using a recursive helper function, we place each node's value as a string in
 * its correct position, calculated based on the current row and the left/right
 * column bounds. The helper function recurses for left and right children,
 * updating the column bounds accordingly. This approach ensures each node is
 * centered in its subtree's range. The time complexity is O(N), where N is the
 * number of nodes, and the space complexity is O(2^h), where h is the tree's
 * height, due to the matrix size.
 */

// Helper function to compute the height of the binary tree.
// The height is the number of edges from the root to the deepest leaf.
// For a single node, height is 0.
int getHeight(TreeNode *node) {
  if (!node)
    return -1; // Base case: null node has height -1
  // Recursively compute the height of left and right subtrees
  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);
  // The height of the current node is max of left/right + 1
  return 1 + std::max(leftHeight, rightHeight);
}

// Helper function to fill the matrix with node values.
// node: current tree node
// res: reference to the result matrix
// row: current row in the matrix
// left: left boundary (inclusive) of the current subtree's column range
// right: right boundary (inclusive) of the current subtree's column range
void fill(TreeNode *node, vector<vector<string>> &res, int row, int left,
          int right) {
  if (!node || left > right)
    return; // Base case: nothing to place
  // The column to place the current node is the middle of [left, right]
  int mid = left + (right - left) / 2;
  // Place the node's value as a string
  res[row][mid] = std::to_string(node->val);
  // Recursively fill the left subtree in the left half
  fill(node->left, res, row + 1, left, mid - 1);
  // Recursively fill the right subtree in the right half
  fill(node->right, res, row + 1, mid + 1, right);
}

class Solution {
public:
  vector<vector<string>> printTree(TreeNode *root) {
    // Step 1: Compute the height of the tree
    int height = getHeight(root);
    // Step 2: Compute the number of rows (height + 1) and columns (2^(height+1)
    // - 1)
    int m = height + 1;
    int n = (1 << (height + 1)) - 1; // 2^(height+1) - 1
    // Step 3: Initialize the result matrix with empty strings
    vector<vector<string>> res(m, vector<string>(n, ""));
    // Step 4: Fill the matrix with node values using the helper function
    fill(root, res, 0, 0, n - 1);
    // Step 5: Return the filled matrix
    return res;
  }
};
// @lc code=end
