/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
#include <string>
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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> result;
    if (!root)
      return result;

    dfs(root, "", result);
    return result;
  }

private:
  void dfs(TreeNode *node, string path, vector<string> &result) {
    // Add current node to path
    if (!path.empty()) {
      path += "->";
    }
    path += to_string(node->val);

    // If it's a leaf node, add the path to result
    if (!node->left && !node->right) {
      result.push_back(path);
      return;
    }

    // Recursively traverse left and right children
    if (node->left) {
      dfs(node->left, path, result);
    }
    if (node->right) {
      dfs(node->right, path, result);
    }
  }
};
// @lc code=end
