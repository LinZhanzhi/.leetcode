/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int, int> inorder_map;
    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
      inorder_map[inorder[i]] = i;
    }

    function<TreeNode *(int, int, int, int)> build =
        [&](int in_left, int in_right, int post_left,
            int post_right) -> TreeNode * {
      if (in_left > in_right || post_left > post_right)
        return nullptr;
      int root_val = postorder[post_right];
      TreeNode *root = new TreeNode(root_val);
      int in_root_idx = inorder_map[root_val];
      int left_size = in_root_idx - in_left;
      root->left =
          build(in_left, in_root_idx - 1, post_left, post_left + left_size - 1);
      root->right = build(in_root_idx + 1, in_right, post_left + left_size,
                          post_right - 1);
      return root;
    };

    return build(0, n - 1, 0, n - 1);
  }
};
// @lc code=end
