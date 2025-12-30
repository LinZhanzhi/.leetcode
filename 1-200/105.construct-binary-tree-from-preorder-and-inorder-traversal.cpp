/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
  // Main function to build tree from preorder and inorder traversals
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Map each value in inorder to its index for O(1) lookups
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < inorder.size(); ++i) {
      inorder_map[inorder[i]] = i;
    }
    // Recursive lambda to build the tree
    // preL, preR: current range in preorder
    // inL, inR: current range in inorder
    function<TreeNode *(int, int, int, int)> build =
        [&](int preL, int preR, int inL, int inR) -> TreeNode * {
      // Base case: no elements to construct
      if (preL > preR || inL > inR)
        return nullptr;
      // The first element in preorder is the root
      int rootVal = preorder[preL];
      TreeNode *root = new TreeNode(rootVal);
      // Find the root index in inorder
      int inRootIdx = inorder_map[rootVal];
      // Number of nodes in left subtree
      int leftSize = inRootIdx - inL;
      // Recursively build left and right subtrees
      root->left = build(preL + 1, preL + leftSize, inL, inRootIdx - 1);
      root->right = build(preL + leftSize + 1, preR, inRootIdx + 1, inR);
      return root;
    };
    // Build the tree using the full range of preorder and inorder
    return build(0, preorder.size() - 1, 0, inorder.size() - 1);
  }
};
// @lc code=end
