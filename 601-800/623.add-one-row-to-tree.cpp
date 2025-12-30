/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 */

// Brief, Digested Understanding:
// ----
// The task is to insert a new row of nodes with a given value into a binary
// tree at a specified depth. If the depth is 1, we create a new root node with
// the given value and make the original tree its left child. Otherwise, for
// every node at depth-1, we insert two new nodes with the given value as its
// new left and right children, and attach the original left and right subtrees
// to these new nodes, respectively.

// High-Level Summary:
// ----
// The solution uses recursion to traverse the tree until it reaches nodes at
// depth-1. For each such node, it creates two new nodes with the specified
// value, attaches the original left subtree to the new left node, and the
// original right subtree to the new right node. If depth is 1, a new root is
// created. The time complexity is O(N), where N is the number of nodes, since
// each node is visited at most once. The space complexity is O(H), where H is
// the height of the tree, due to the recursion stack.

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
private:
  // Helper function to recursively add a row at the given depth.
  void addRowHelper(TreeNode *node, int val, int currentDepth,
                    int targetDepth) {
    // Base case: if node is null, nothing to do.
    if (!node)
      return;

    // If we've reached the level just above the target depth,
    // we need to insert new nodes as children of this node.
    if (currentDepth == targetDepth - 1) {
      // Create new left node with value 'val' and attach the original left
      // subtree.
      TreeNode *newLeft = new TreeNode(val);
      newLeft->left = node->left;
      node->left = newLeft;

      // Create new right node with value 'val' and attach the original right
      // subtree.
      TreeNode *newRight = new TreeNode(val);
      newRight->right = node->right;
      node->right = newRight;
      // No need to recurse further from here, as the new row is inserted.
    } else {
      // Otherwise, keep traversing down the tree.
      addRowHelper(node->left, val, currentDepth + 1, targetDepth);
      addRowHelper(node->right, val, currentDepth + 1, targetDepth);
    }
  }

public:
  // Main function to add one row to the tree.
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    // Special case: if depth is 1, create a new root node.
    if (depth == 1) {
      TreeNode *newRoot = new TreeNode(val);
      newRoot->left = root; // The original tree becomes the left child.
      return newRoot;
    }
    // Otherwise, use the helper to insert the row at the correct depth.
    addRowHelper(root, val, 1, depth);
    return root;
  }
};
// @lc code=end
