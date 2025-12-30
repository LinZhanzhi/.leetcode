/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

// Brief, Digested Understanding:
//
// The goal is to count all paths in a binary tree where the sum of the node
// values along the path equals a given targetSum. A path can start and end at
// any node, but it must always go downwards (from parent to child, not upwards
// or skipping nodes). We need to consider every possible path that follows this
// rule, not just those starting at the root or ending at a leaf.

// High-Level Summary:
//
// The solution uses a recursive approach to traverse the tree. For each node,
// we consider all paths that start at that node and go downwards, counting how
// many of them sum to targetSum. We do this for every node in the tree, so
// every possible starting point is checked. The main function recursively
// explores each node as a potential starting point, and a helper function
// counts the number of valid paths starting from a given node. The overall time
// complexity is O(N^2) in the worst case (for a skewed tree), where N is the
// number of nodes, but for balanced trees, it is more efficient. Space
// complexity is O(H), where H is the height of the tree, due to recursion stack
// usage.

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
  // Main function to count all paths in the tree that sum to targetSum
  int pathSum(TreeNode *root, int targetSum) {
    // Base case: if the current node is null, there are no paths
    if (!root)
      return 0;

    // Count the paths that start from the current node
    int pathsFromRoot = countPathsFromNode(root, targetSum);

    // Recursively count paths in the left and right subtrees
    int pathsFromLeft = pathSum(root->left, targetSum);
    int pathsFromRight = pathSum(root->right, targetSum);

    // The total number of paths is the sum of all three counts
    return pathsFromRoot + pathsFromLeft + pathsFromRight;
  }

private:
  // Helper function to count the number of paths starting from a given node
  // that sum to the remainingSum
  int countPathsFromNode(TreeNode *node, long long remainingSum) {
    // If the node is null, there are no paths
    if (!node)
      return 0;

    // Initialize the count for this node
    int count = 0;

    // If the current node's value matches the remaining sum, we found a valid
    // path
    if (node->val == remainingSum) {
      count += 1;
    }

    // Recursively check for paths in the left and right subtrees,
    // reducing the remaining sum by the current node's value
    count += countPathsFromNode(node->left, remainingSum - node->val);
    count += countPathsFromNode(node->right, remainingSum - node->val);

    // Return the total count of valid paths starting from this node
    return count;
  }
};
// @lc code=end
