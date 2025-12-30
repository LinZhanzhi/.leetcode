/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
 * Brief, Digested Understanding:
 * ----
 * The goal is to remove a node with a specific value (key) from a Binary Search
 * Tree (BST). In a BST, for any node, all values in the left subtree are less,
 * and all values in the right subtree are greater. When deleting a node, we
 * must maintain the BST property, which means carefully rearranging the tree if
 * the node has children. There are three main cases: the node has no children
 * (just remove it), one child (replace it with its child), or two children
 * (replace it with its in-order successor or predecessor).
 *
 * High-Level Summary:
 * ----
 * The solution recursively searches for the node with the given key.
 * - If the key is less than the current node's value, search the left subtree.
 * - If the key is greater, search the right subtree.
 * - If the key matches, perform deletion:
 *   - If the node has no children, return nullptr.
 *   - If the node has one child, return that child.
 *   - If the node has two children, find the smallest node in the right subtree
 * (in-order successor), copy its value to the current node, and recursively
 * delete the successor. The helper function `findMin` is used to find the
 * minimum node in a subtree. Time complexity is O(height of tree), and space
 * complexity is O(height) due to recursion.
 */

// Helper function to find the node with the minimum value in a BST subtree.
// This is used to find the in-order successor when deleting a node with two
// children.
TreeNode *findMin(TreeNode *node) {
  // The minimum value in a BST is always at the leftmost node.
  while (node && node->left) {
    node = node->left;
  }
  return node;
}

class Solution {
public:
  // Main function to delete a node with the given key from the BST.
  TreeNode *deleteNode(TreeNode *root, int key) {
    // Base case: if the tree is empty, nothing to delete.
    if (!root)
      return nullptr;

    // If the key to be deleted is less than the root's value,
    // then it lies in the left subtree.
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    }
    // If the key to be deleted is greater than the root's value,
    // then it lies in the right subtree.
    else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    }
    // If the key is the same as the root's value, this is the node to delete.
    else {
      // Case 1: Node with only one child or no child.
      if (!root->left) {
        // If there is no left child, return the right child (may be nullptr).
        TreeNode *rightChild = root->right;
        delete root; // Free the memory of the node to be deleted.
        return rightChild;
      } else if (!root->right) {
        // If there is no right child, return the left child.
        TreeNode *leftChild = root->left;
        delete root; // Free the memory of the node to be deleted.
        return leftChild;
      }
      // Case 2: Node with two children.
      // Get the in-order successor (smallest in the right subtree).
      TreeNode *minNode = findMin(root->right);
      // Copy the in-order successor's value to this node.
      root->val = minNode->val;
      // Delete the in-order successor recursively.
      root->right = deleteNode(root->right, minNode->val);
    }
    // Return the (possibly updated) root pointer.
    return root;
  }
};
// @lc code=end
