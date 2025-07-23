/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
  int getMinimumDifference(TreeNode *root) {
    int minDiff =
        INT_MAX; // Initialize minimum difference to maximum possible value
    TreeNode *prev =
        nullptr; // Pointer to keep track of previous node in inorder traversal

    // Lambda function for inorder traversal
    std::function<void(TreeNode *)> inorder = [&](TreeNode *node) {
      if (!node)
        return;
      inorder(node->left); // Traverse left subtree
      if (prev) {
        // Update minDiff if the difference between current and previous node is
        // smaller
        minDiff = std::min(minDiff, std::abs(node->val - prev->val));
      }
      prev = node;          // Update previous node to current
      inorder(node->right); // Traverse right subtree
    };

    inorder(root);  // Start inorder traversal from root
    return minDiff; // Return the minimum absolute difference found
  }
};
// @lc code=end
