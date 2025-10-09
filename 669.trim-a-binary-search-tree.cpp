/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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
 * The problem asks us to "trim" a binary search tree (BST) so that all its
 * nodes have values within a given range [low, high]. Any node with a value
 * outside this range should be removed, and the resulting tree should still
 * be a valid BST, preserving the relative structure of the remaining nodes.
 * The root of the trimmed tree may change if the original root is out of range.
 *
 * High-Level Summary:
 * ----
 * We solve this problem using recursion, leveraging the BST property:
 * - If a node's value is less than low, all nodes in its left subtree are
 *   also less than low, so we discard the left subtree and only consider the
 *   right subtree.
 * - If a node's value is greater than high, all nodes in its right subtree
 *   are also greater than high, so we discard the right subtree and only
 *   consider the left subtree.
 * - If a node's value is within [low, high], we recursively trim both its
 *   left and right subtrees.
 * The recursion ensures that the structure of the remaining nodes is preserved.
 * Time complexity is O(N), where N is the number of nodes, since each node is
 * visited once. Space complexity is O(H), where H is the height of the tree,
 * due to the recursion stack.
 */

class Solution {
public:
  // Main function to trim the BST so that all its elements are in [low, high]
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    // Base case: If the current node is null, return null (empty subtree)
    if (!root)
      return nullptr;

    // If the current node's value is less than low,
    // discard the left subtree and recursively trim the right subtree.
    if (root->val < low) {
      // All nodes in the left subtree are also < low (BST property)
      return trimBST(root->right, low, high);
    }

    // If the current node's value is greater than high,
    // discard the right subtree and recursively trim the left subtree.
    if (root->val > high) {
      // All nodes in the right subtree are also > high (BST property)
      return trimBST(root->left, low, high);
    }

    // If the current node's value is within [low, high],
    // recursively trim both left and right subtrees.
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    // Return the current node, as it is within the valid range.
    return root;
  }
};
// @lc code=end
