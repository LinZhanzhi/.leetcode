/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 */

// Brief Digested Understanding:
// ----
// This problem asks us to add a new value to a Binary Search Tree (BST) –
// a special kind of binary tree where every node's left child is less than it,
// and every right child is greater. The new value is guaranteed not to exist
// in the tree already. We need to return the tree's root after inserting the
// value, preserving BST properties. The actual position where the new node is
// inserted depends on the value: smaller values go left, larger go right. The
// tree structure must still work as a proper BST after insertion.
//
// High-Level Summary:
// ----
// We'll approach this problem with a simple recursive algorithm
// that searches for the correct position in the BST to insert the new value.
// Starting from the root, we compare the value to be inserted with the current
// node. If the value is smaller, we recursively insert it into the left
// subtree. If the value is larger, we move to the right subtree. When we hit a
// nullptr child, that's where we place a new node. This maintains the BST
// property. The solution is modular, with a helper function for insertion to
// handle recursion. Time complexity: O(H) where H is the height of the BST
// (O(log N) for balanced trees, O(N) for skewed trees), and space is also O(H)
// due to recursion (call stack).

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
  /**
   * Public interface to insert a value into the BST.
   * Returns the root of the modified tree (could be a new root if tree was
   * empty).
   */
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    // Call the recursive helper to do the actual insertion.
    return insertHelper(root, val);
  }

private:
  /**
   * Recursive helper to insert a value into a BST rooted at 'node'.
   * Arguments:
   *   - node: current root of subtree (could be nullptr).
   *   - val: value to insert (guaranteed not to exist in the tree).
   * Returns:
   *   - new subtree root after insertion.
   */
  TreeNode *insertHelper(TreeNode *node, int val) {
    // Base case: found a null spot, so we insert here.
    if (node == nullptr) {
      // Create a new node for this value, with empty children.
      return new TreeNode(val);
    }
    // Decide to go left or right depending on value.
    if (val < node->val) {
      // If value is less, insert into the left subtree.
      // Recursively update node->left with the inserted subtree.
      node->left = insertHelper(node->left, val);
    } else {
      // If value is greater, insert into the right subtree.
      // Recursively update node->right with the inserted subtree.
      node->right = insertHelper(node->right, val);
    }
    // Return node to link back in the parent recursion.
    return node;
  }
};
// @lc code=end
