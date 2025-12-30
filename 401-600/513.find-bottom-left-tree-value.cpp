/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 */

// Brief, Digested Understanding:
// ----
// The problem asks us to find the value of the leftmost node in the last
// (deepest) row of a binary tree. In other words, among all nodes at the
// greatest depth, we want the one that is furthest to the left.

// High-Level Summary:
// ----
// The most effective way to solve this is to perform a level-order traversal
// (also known as Breadth-First Search, BFS) of the tree. By traversing the tree
// level by level from top to bottom, and from left to right within each level,
// the first node we encounter at each level is the leftmost node for that
// level. We keep updating our answer with the first node of each level, and
// after the traversal, the last updated value will be the leftmost value in the
// last row. This approach has a time complexity of O(N), where N is the number
// of nodes, and a space complexity of O(W), where W is the maximum width of the
// tree (the largest number of nodes at any level).

#include <queue> // Include queue for BFS traversal

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
  // Main function to find the leftmost value in the last row of the tree
  int findBottomLeftValue(TreeNode *root) {
    // Use a helper function to perform BFS and find the answer
    return bfsLeftmostBottomValue(root);
  }

private:
  // Helper function to perform level-order traversal (BFS)
  int bfsLeftmostBottomValue(TreeNode *root) {
    // Edge case: if the tree is empty, though per constraints this won't happen
    if (!root)
      return -1;

    std::queue<TreeNode *> q; // Queue to hold nodes for BFS
    q.push(root);             // Start with the root node

    int leftmost = root->val; // Initialize leftmost with root's value

    // Continue until all levels are processed
    while (!q.empty()) {
      int levelSize = q.size(); // Number of nodes at the current level

      // For each level, process all nodes
      for (int i = 0; i < levelSize; ++i) {
        TreeNode *node = q.front();
        q.pop();

        // The first node at this level is the leftmost node
        if (i == 0) {
          leftmost = node->val;
        }

        // Add left child first to ensure left-to-right order
        if (node->left) {
          q.push(node->left);
        }
        // Add right child
        if (node->right) {
          q.push(node->right);
        }
      }
      // After this loop, leftmost is updated to the first node of the current
      // level
    }
    // After traversing all levels, leftmost holds the leftmost value of the
    // last row
    return leftmost;
  }
};
// @lc code=end
