/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
 * This problem asks us to find the maximum width of a binary tree, where the
 * width of a level is defined as the number of positions between the leftmost
 * and rightmost non-null nodes at that level, counting all the "null" positions
 * that would exist in a complete binary tree. In other words, we must consider
 * the "gaps" that would be present if the tree were filled out to a complete
 * binary tree at each level. The challenge is to correctly account for these
 * positions, not just the number of actual nodes per level.
 *
 * High-Level Summary:
 * ----
 * To solve this, we perform a level-order (BFS) traversal of the tree, but we
 * also assign a "position index" to each node as if the tree were a complete
 * binary tree. The root is at position 0, the left child of a node at position
 * p is at 2*p, and the right child is at 2*p+1. For each level, we record the
 * position of the first and last node, and the width is last - first + 1. We
 * keep track of the maximum width across all levels. This approach ensures that
 * nulls between nodes are counted. The solution is modularized with helper
 * functions for clarity. Time complexity is O(n), and space complexity is O(n),
 * where n is the number of nodes.
 */

#include <queue>   // For std::queue
#include <utility> // For std::pair

class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    // Edge case: if the tree is empty, width is 0
    if (!root)
      return 0;
    // Use a queue to perform BFS. Each element is a pair: (node pointer,
    // position index)
    std::queue<std::pair<TreeNode *, unsigned long long>> q;
    // Start with the root at position 0
    q.push({root, 0});
    int maxWidth = 0; // To keep track of the maximum width found

    // Process the tree level by level
    while (!q.empty()) {
      int levelSize = q.size(); // Number of nodes at the current level
      // The position index of the first node at this level
      unsigned long long levelStart = q.front().second;
      // Variables to store the first and last position indices at this level
      unsigned long long first = 0, last = 0;

      // Iterate through all nodes at the current level
      for (int i = 0; i < levelSize; ++i) {
        // Get the current node and its position index
        auto [node, pos] = q.front();
        q.pop();
        // Normalize the position to prevent overflow by subtracting levelStart
        // This keeps all positions at this level starting from 0
        pos -= levelStart;
        // For the first node, record its position
        if (i == 0)
          first = pos;
        // For the last node, record its position
        if (i == levelSize - 1)
          last = pos;
        // If the node has a left child, assign it position 2*pos
        if (node->left) {
          q.push({node->left, 2 * pos});
        }
        // If the node has a right child, assign it position 2*pos + 1
        if (node->right) {
          q.push({node->right, 2 * pos + 1});
        }
      }
      // The width of this level is last - first + 1
      int width = static_cast<int>(last - first + 1);
      // Update the maximum width if this level's width is greater
      if (width > maxWidth) {
        maxWidth = width;
      }
    }
    // Return the maximum width found
    return maxWidth;
  }
};
// @lc code=end
