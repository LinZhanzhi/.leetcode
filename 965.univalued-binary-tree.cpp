/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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
  bool isUnivalTree(TreeNode *root) {
    int val = root->val;
    std::function<bool(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node)
        return true;
      if (node->val != val)
        return false;
      return dfs(node->left) && dfs(node->right);
    };
    return dfs(root);
  }
};
// @lc code=end
