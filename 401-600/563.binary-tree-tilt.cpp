/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
  int findTilt(TreeNode *root) {
    int totalTilt = 0;
    // Helper function to compute sum of subtree and accumulate tilt
    function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
      if (!node)
        return 0;
      int leftSum = dfs(node->left);
      int rightSum = dfs(node->right);
      totalTilt += abs(leftSum - rightSum);
      return leftSum + rightSum + node->val;
    };
    dfs(root);
    return totalTilt;
  }
};
// @lc code=end
