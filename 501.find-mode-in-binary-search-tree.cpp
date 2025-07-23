/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
class Solution {
public:
  vector<int> findMode(TreeNode *root) {
    vector<int> res;          // Stores the mode(s) of the BST
    int currVal = 0;          // Current value being processed
    int currCount = 0;        // Count of the current value
    int maxCount = 0;         // Maximum count found so far
    TreeNode *prev = nullptr; // Pointer to previous node in inorder traversal

    // Inorder traversal lambda to process nodes in sorted order
    function<void(TreeNode *)> inorder = [&](TreeNode *node) {
      if (!node)
        return;
      inorder(node->left); // Traverse left subtree

      // If previous node exists and has the same value, increment count
      if (prev && prev->val == node->val) {
        currCount++;
      } else {
        currCount = 1; // Reset count for a new value
      }

      // If current count exceeds maxCount, update result and maxCount
      if (currCount > maxCount) {
        res.clear();
        res.push_back(node->val);
        maxCount = currCount;
      } else if (currCount == maxCount) {
        // If current count equals maxCount, add value to result
        res.push_back(node->val);
      }
      prev = node; // Update previous node

      inorder(node->right); // Traverse right subtree
    };

    inorder(root); // Start inorder traversal from root
    return res;
  }
};
// @lc code=end
