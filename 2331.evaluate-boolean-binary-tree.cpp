/*
 * @lc app=leetcode id=2331 lang=cpp
 *
 * [2331] Evaluate Boolean Binary Tree
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
  bool evaluateTree(TreeNode *root) {
    if (!root->left && !root->right) {
      // Leaf node: return its boolean value
      return root->val == 1;
    }
    bool leftVal = evaluateTree(root->left);
    bool rightVal = evaluateTree(root->right);
    if (root->val == 2) {
      // OR operation
      return leftVal || rightVal;
    } else {
      // AND operation (root->val == 3)
      return leftVal && rightVal;
    }
  }
};
// @lc code=end
