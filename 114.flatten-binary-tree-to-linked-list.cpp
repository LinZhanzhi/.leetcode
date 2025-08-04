/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
class Solution {
public:
  void flatten(TreeNode *root) {
    if (!root)
      return;
    TreeNode *curr = root;
    while (curr) {
      if (curr->left) {
        // Find the rightmost node of left subtree
        TreeNode *prev = curr->left;
        while (prev->right) {
          prev = prev->right;
        }
        // Connect right subtree to the rightmost node
        prev->right = curr->right;
        // Move left subtree to right
        curr->right = curr->left;
        curr->left = nullptr;
      }
      curr = curr->right;
    }
  }
};
// @lc code=end
