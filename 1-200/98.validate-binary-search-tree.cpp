/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
  bool isValidBST(TreeNode *root) {
    function<bool(TreeNode *, long long, long long)> validate =
        [&](TreeNode *node, long long lower, long long upper) -> bool {
      if (!node)
        return true;
      if (node->val <= lower || node->val >= upper)
        return false;
      return validate(node->left, lower, node->val) &&
             validate(node->right, node->val, upper);
    };
    return validate(root, LLONG_MIN, LLONG_MAX);
  }
};
// @lc code=end
