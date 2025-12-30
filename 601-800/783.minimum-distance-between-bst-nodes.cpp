/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
  int minDiffInBST(TreeNode *root) {
    int minDiff = INT_MAX;
    TreeNode *prev = nullptr;

    // Helper function for in-order traversal
    std::function<void(TreeNode *)> inorder = [&](TreeNode *node) {
      if (!node)
        return;
      inorder(node->left);
      if (prev) {
        minDiff = std::min(minDiff, node->val - prev->val);
      }
      prev = node;
      inorder(node->right);
    };

    inorder(root);
    return minDiff;
  }
};
// @lc code=end
