/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// Brief, Digested Understanding:
//
// The goal is to find the lowest common ancestor (LCA) of two nodes, p and q,
// in a binary tree. The LCA is the deepest node in the tree that has both p and
// q as descendants (a node can be a descendant of itself). We need to traverse
// the tree and determine the lowest node where the paths to p and q meet.
//
// High-Level Summary:
//
// We use a recursive approach to traverse the tree. At each node, we check if
// it is either p or q, or if p and q are found in different subtrees of the
// current node. If both p and q are found in different subtrees, the current
// node is their LCA. If only one of p or q is found in the subtree, we return
// that node up the recursion stack. The time complexity is O(N), where N is the
// number of nodes in the tree, since we may visit every node once. The space
// complexity is O(H), where H is the height of the tree, due to the recursion
// stack.

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  // This function finds the lowest common ancestor (LCA) of nodes p and q in
  // the binary tree rooted at 'root'.
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // Base case: If the current node is null, we've reached the end of a path
    // without finding p or q.
    if (root == nullptr) {
      return nullptr;
    }
    // If the current node is either p or q, we've found one of the nodes.
    // According to the definition, a node can be a descendant of itself.
    if (root == p || root == q) {
      return root;
    }

    // Recursively search for p and q in the left and right subtrees.
    TreeNode *left =
        lowestCommonAncestor(root->left, p, q); // Search left subtree
    TreeNode *right =
        lowestCommonAncestor(root->right, p, q); // Search right subtree

    // If both left and right are non-null, it means p and q are found in
    // different subtrees. Therefore, the current node is their lowest common
    // ancestor.
    if (left != nullptr && right != nullptr) {
      return root;
    }

    // If only one side is non-null, return that side (either p or q was found
    // below). If both are null, this will return null up the stack.
    return left != nullptr ? left : right;
  }
};
// @lc code=end
