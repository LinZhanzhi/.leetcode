/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
// Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };
class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;
    // If the left and right heights are the same, the tree is perfect, and the
    // number of nodes is 2^height - 1.
    int leftHeight = getLeftHeight(root);
    int rightHeight = getRightHeight(root);
    if (leftHeight == rightHeight) {
      return (1 << leftHeight) - 1;
    }
    // If the left and right heights are not the same, the tree is not perfect,
    // and we need to count the nodes in the left and right subtrees.
    return 1 + countNodes(root->left) + countNodes(root->right);
  }

private:
  // Helper function to compute the height of the leftmost path from the given
  // node.
  int getLeftHeight(TreeNode *node) {
    int height = 0;
    while (node) {
      ++height;
      node = node->left;
    }
    return height;
  }

  // Helper function to compute the height of the rightmost path from the given
  // node.
  int getRightHeight(TreeNode *node) {
    int height = 0;
    while (node) {
      ++height;
      node = node->right;
    }
    return height;
  }
};
// @lc code=end
