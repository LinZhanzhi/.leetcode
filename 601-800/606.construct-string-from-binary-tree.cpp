/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
 * The goal is to convert a binary tree into a string that reflects its
 * structure using preorder traversal. Each node's value is included, and
 * children are represented in parentheses. Parentheses for missing children are
 * omitted unless needed to preserve the tree's structure (i.e., when a right
 * child exists but the left child is missing). This ensures the string can be
 * uniquely mapped back to the original tree.
 *
 * High-Level Summary:
 * ----
 * The solution uses a recursive approach to traverse the tree in preorder
 * (node, left, right). For each node, we:
 *   - Add its value to the string.
 *   - If it has children, recursively process the left and right subtrees,
 * adding parentheses as required by the rules.
 *   - Omit empty parentheses unless a right child exists without a left child,
 * in which case we include "()" for the left. The main function delegates the
 * string construction to a helper function for clarity. Time Complexity: O(N),
 * where N is the number of nodes (each node is visited once). Space Complexity:
 * O(H), where H is the height of the tree (due to recursion stack).
 */

#include <string> // For std::string and std::to_string

using std::string;

// Helper function to recursively build the string representation of the tree.
class Solution {
public:
  // Public interface: starts the recursive string construction.
  string tree2str(TreeNode *root) {
    // Call the recursive helper to build the string from the root.
    return tree2strHelper(root);
  }

private:
  // Recursive helper function to construct the string for a given subtree.
  string tree2strHelper(TreeNode *node) {
    // Base case: if the node is null, return an empty string.
    if (!node)
      return "";

    // Start with the current node's value.
    string result = std::to_string(node->val);

    // If the node has at least one child, we may need to add parentheses.
    // There are three cases to consider:
    // 1. Both left and right children exist.
    // 2. Only left child exists.
    // 3. Only right child exists (left is null).
    if (node->left || node->right) {
      // Always include left child in parentheses, even if it's empty,
      // if there is a right child (to preserve structure).
      result += "(" + tree2strHelper(node->left) + ")";
    }

    // Only include right child if it exists.
    if (node->right) {
      // Right child must always be in parentheses, and if left child is
      // missing, the above code ensures we already included "()" for the left.
      result += "(" + tree2strHelper(node->right) + ")";
    }

    // If the node is a leaf (no children), just its value is enough.
    return result;
  }
};
// @lc code=end
