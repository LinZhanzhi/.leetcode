/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// Brief, Digested Understanding:
//
// The goal is to find the lowest common ancestor (LCA) of two nodes, p and q,
// in a binary search tree (BST). The LCA is the lowest node in the tree that
// has both p and q as descendants (a node can be a descendant of itself).
// Because the tree is a BST, for any node, all values in its left subtree are
// less than its value, and all values in its right subtree are greater. This
// property allows us to efficiently find the LCA by comparing the values of p
// and q to the current node as we traverse the tree.
//
// High-Level Summary:
//
// The solution leverages the BST property to traverse the tree from the root:
// - If both p and q have values less than the current node, the LCA must be in
// the left subtree.
// - If both p and q have values greater than the current node, the LCA must be
// in the right subtree.
// - If p and q are on different sides of the current node (or one is the
// current node), then the current node is their LCA. This approach is
// efficient, requiring O(h) time, where h is the height of the tree, and O(1)
// space if implemented iteratively.
//
// Time Complexity: O(h), where h is the height of the BST (O(log n) for
// balanced, O(n) for skewed). Space Complexity: O(1) for the iterative approach
// (O(h) if recursion is used).

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
  // Function to find the lowest common ancestor of nodes p and q in a BST.
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // Start traversing from the root node.
    TreeNode *current = root;
    // Loop until we find the split point, which is the LCA.
    while (current) {
      // If both p and q are less than current, LCA is in the left subtree.
      if (p->val < current->val && q->val < current->val) {
        // Move to the left child.
        current = current->left;
      }
      // If both p and q are greater than current, LCA is in the right subtree.
      else if (p->val > current->val && q->val > current->val) {
        // Move to the right child.
        current = current->right;
      }
      // If p and q are on different sides, or one is equal to current,
      // then current is the LCA.
      else {
        // This is the split point, so return current as the LCA.
        return current;
      }
    }
    // If the tree is empty or p and q are not present, return nullptr.
    // (Per problem constraints, p and q will always exist, so this is just for
    // completeness.)
    return nullptr;
  }
};
// @lc code=end
