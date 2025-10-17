/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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

/*
 * Brief Digested Understanding:
 * ----
 * The main idea of this problem is to remove all nodes in a binary tree that
 * are part of a subtree which does **not** contain the value 1. That is,
 * for every node, if the whole subtree beneath it (including itself) consists
 * only of nodes with value 0, we cut off that whole subtree. The result should
 * be the root of the pruned tree, possibly even nullptr if the entire tree is
 * pruned away. It’s a top-down filtering of the binary tree, focusing on
 * whether or not each part contains the value 1 anywhere in its descendants.
 *
 * High-Level Summary:
 * ----
 * To solve this, we will use recursion in a post-order (bottom-up) manner,
 * because whether a node is pruned depends on its whole subtree. For every
 * node, we recursively prune its left and right subtrees. If, after this
 * pruning, both left and right become null and the value of the current node is
 * 0, then this node should also be pruned (i.e., return null). Otherwise, keep
 * the node (and its pruned children). The main algorithmic actions are:
 *   - Recursively check/prune left and right children first (post-order).
 *   - If both children and itself are "0-only" (null or 0-valued), prune node.
 * We expect time complexity O(N), where N is the number of nodes (each visited
 * once); space complexity is O(H) for recursion stack, with H = height of the
 * tree.
 */

// Helper function to recursively prune the tree
TreeNode *pruneSubtree(TreeNode *node) {
  if (!node) {
    // Base case: If the current node is null, simply return null
    return nullptr;
  }

  // Recursively prune the left subtree first
  node->left = pruneSubtree(node->left);

  // Then recursively prune the right subtree
  node->right = pruneSubtree(node->right);

  // If both left and right child are pruned (i.e., null) AND current node is 0,
  // this whole subtree does not contain a 1, so prune this node too
  if (node->val == 0 && node->left == nullptr && node->right == nullptr) {
    // Prune by returning nullptr to the parent call
    return nullptr;
  }

  // Otherwise, keep this node (with possibly pruned children)
  return node;
}

class Solution {
public:
  TreeNode *pruneTree(TreeNode *root) {
    // Start the recursion from the root
    // This will return either the root of the pruned tree or nullptr
    // if the entire tree is pruned away
    return pruneSubtree(root);
  }
};
// @lc code=end
