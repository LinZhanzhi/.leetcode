/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

#include <queue>
#include <vector>

using namespace std;

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
  // Returns the values of the nodes visible from the right side of the binary
  // tree. The approach uses level order traversal (BFS) to visit each level of
  // the tree. For each level, the last node encountered is the rightmost node,
  // which is visible from the right side.
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result; // Stores the rightmost node values for each level
    if (!root)
      return result; // If the tree is empty, return an empty result

    queue<TreeNode *> q; // Queue for BFS traversal
    q.push(root);        // Start BFS with the root node

    while (!q.empty()) {
      int levelSize = q.size(); // Number of nodes at the current level

      // Traverse all nodes at the current level
      for (int i = 0; i < levelSize; ++i) {
        TreeNode *node = q.front();
        q.pop();

        // If this is the last node in the current level, add its value to the
        // result
        if (i == levelSize - 1) {
          result.push_back(node->val);
        }

        // Add left and right children to the queue for the next level
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
    return result; // Return the list of rightmost node values
  }
};
