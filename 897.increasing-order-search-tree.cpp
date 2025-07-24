/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
  TreeNode *increasingBST(TreeNode *root) {
    TreeNode *dummy = new TreeNode(0);
    TreeNode *curr = dummy;

    std::function<void(TreeNode *)> inorder = [&](TreeNode *node) {
      if (!node)
        return;
      inorder(node->left);
      node->left = nullptr;
      curr->right = node;
      curr = node;
      inorder(node->right);
    };

    inorder(root);
    return dummy->right;
  }
};
// @lc code=end
