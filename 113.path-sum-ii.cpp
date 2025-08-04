/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> res;
    vector<int> path;
    function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int sum) {
      if (!node)
        return;
      path.push_back(node->val);
      if (!node->left && !node->right && sum == node->val) {
        res.push_back(path);
      } else {
        dfs(node->left, sum - node->val);
        dfs(node->right, sum - node->val);
      }
      path.pop_back();
    };
    dfs(root, targetSum);
    return res;
  }
};
// @lc code=end
