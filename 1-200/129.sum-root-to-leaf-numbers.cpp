/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
  int sumNumbers(TreeNode *root) {
    // Helper function to perform DFS traversal
    std::function<int(TreeNode *, int)> dfs = [&](TreeNode *node,
                                                  int current) -> int {
      if (!node)
        return 0;
      current = current * 10 + node->val;
      if (!node->left && !node->right) {
        return current;
      }
      return dfs(node->left, current) + dfs(node->right, current);
    };
    return dfs(root, 0);
  }
};
// @lc code=end
