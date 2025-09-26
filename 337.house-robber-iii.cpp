/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
 * In this problem, each house is a node in a binary tree. The thief cannot rob
 * two directly connected houses (parent and child) on the same night, or the
 * alarm will go off. The goal is to find the maximum amount of money the thief
 * can rob from the tree, following this rule.
 *
 * The core challenge is to decide, for each node, whether to rob it (and skip
 * its children) or skip it (and allow robbing its children), and to do this
 * optimally for the whole tree.
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses dynamic programming with recursion. For each node, we
 * compute two values:
 *   1. The maximum money if we rob this node (so we cannot rob its children,
 * but can rob its grandchildren).
 *   2. The maximum money if we do NOT rob this node (so we can rob its
 * children).
 *
 * We use a helper function that returns a pair of values for each node: {max if
 * not robbed, max if robbed}. The final answer is the maximum of these two
 * values at the root.
 *
 * Time Complexity: O(N), where N is the number of nodes, since each node is
 * visited once. Space Complexity: O(H), where H is the height of the tree (due
 * to recursion stack).
 */

class Solution {
public:
  // Main function to compute the maximum amount that can be robbed
  int rob(TreeNode *root) {
    // Call the helper function which returns a pair:
    //   - first: max money if this node is NOT robbed
    //   - second: max money if this node IS robbed
    std::pair<int, int> result = robSubtree(root);
    // The answer is the maximum of robbing or not robbing the root
    return std::max(result.first, result.second);
  }

private:
  // Helper function that returns a pair<int, int> for each node
  //   - first: max money if node is NOT robbed
  //   - second: max money if node IS robbed
  std::pair<int, int> robSubtree(TreeNode *node) {
    if (!node) {
      // Base case: if the node is null, both values are 0
      return {0, 0};
    }

    // Recursively solve for left and right subtrees
    std::pair<int, int> left = robSubtree(node->left);
    std::pair<int, int> right = robSubtree(node->right);

    // If we rob this node, we cannot rob its children
    int robThis = node->val + left.first + right.first;

    // If we do NOT rob this node, we can choose to rob or not rob its children
    int notRobThis =
        std::max(left.first, left.second) + std::max(right.first, right.second);

    // Return the pair: {notRobThis, robThis}
    return {notRobThis, robThis};
  }
};
// @lc code=end
