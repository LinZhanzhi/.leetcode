/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
  bool isCousins(TreeNode *root, int x, int y) {
    // INSERT_YOUR_CODE
    if (!root)
      return false;
    std::queue<std::tuple<TreeNode *, TreeNode *, int>>
        q; // node, parent, depth
    q.push({root, nullptr, 0});
    TreeNode *x_parent = nullptr;
    TreeNode *y_parent = nullptr;
    int x_depth = -1, y_depth = -1;
    while (!q.empty()) {
      auto [node, parent, depth] = q.front();
      q.pop();
      if (node->val == x) {
        x_parent = parent;
        x_depth = depth;
      }
      if (node->val == y) {
        y_parent = parent;
        y_depth = depth;
      }
      if (node->left)
        q.push({node->left, node, depth + 1});
      if (node->right)
        q.push({node->right, node, depth + 1});
    }
    return (x_depth == y_depth) && (x_parent != y_parent);
  }
};
// @lc code=end
