/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0)
      return {};

    // Helper function to generate all BSTs for values from start to end
    /*
    The function generate is a recursive function that generates all unique BSTs
    for a given range of values.
    It takes two parameters: start and end, which represent the range of values
    to generate the BSTs for.
    The function returns a vector of pointers to the root nodes of all unique
    BSTs for the given range.
    */
    function<vector<TreeNode *>(int, int)> generate =
        [&](int start, int end) -> vector<TreeNode *> {
      // If the range is empty, return an empty vector.
      vector<TreeNode *> res;
      if (start > end) {
        res.push_back(nullptr);
        return res;
      }
      // For each value in the range, generate all unique BSTs.
      for (int i = start; i <= end; ++i) {
        // Generate all unique BSTs for the left subtree.
        vector<TreeNode *> leftTrees = generate(start, i - 1);
        // Generate all unique BSTs for the right subtree.
        vector<TreeNode *> rightTrees = generate(i + 1, end);
        // For each left and right subtree, create a new BST with the current
        // value as the root.
        for (auto left : leftTrees) {
          for (auto right : rightTrees) {
            TreeNode *root = new TreeNode(i);
            root->left = left;
            root->right = right;
            res.push_back(root);
          }
        }
      }
      return res;
    };

    return generate(1, n);
  }
};
// @lc code=end
