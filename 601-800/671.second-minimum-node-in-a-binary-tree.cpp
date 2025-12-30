/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
  int findSecondMinimumValue(TreeNode *root) {
    // The minimum value in the tree (root value, since root is guaranteed to be
    // the smallest)
    int min1 = root->val;
    // Use a long to store the answer, initialized to the largest possible value
    long ans = LONG_MAX;

    // Helper function to traverse the tree and update ans if a better candidate
    // is found
    function<void(TreeNode *)> dfs = [&](TreeNode *node) {
      if (!node)
        return;
      // If node's value is greater than min1 and less than current ans, update
      // ans
      if (min1 < node->val && node->val < ans) {
        ans = node->val;
      }
      // If node's value equals min1, need to check its children for possible
      // candidates
      else if (node->val == min1) {
        dfs(node->left);
        dfs(node->right);
      }
    };

    // Start DFS from the root
    dfs(root);
    // If ans was updated, return it; otherwise, return -1 (no second minimum
    // found)
    return ans < LONG_MAX ? ans : -1;
  }
};
// @lc code=end
