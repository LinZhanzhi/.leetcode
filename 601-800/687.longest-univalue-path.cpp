/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
 * For a given binary tree, the problem asks to find the length of the longest
 * path (in terms of edges) where all nodes along the path have the same value.
 * This "univalue" path can be anywhere in the tree and does not need to pass
 * through the root. The challenge is to efficiently traverse the tree and keep
 * track of the maximum such path, considering that it may span the "V" shape
 * formed by going down to both left and right children from a single node.
 *
 * High-Level Summary:
 * ----
 * To solve this problem, we use a post-order depth-first search (DFS)
 * traversal. At each node, we recursively compute the longest univalue path
 * length that can be extended up from both its left and right children. If the
 * child exists and has the same value as the current node, we can extend the
 * path. The longest path through any node is the sum of such extendable paths
 * from both sides. We update the global maximum accordingly. The helper
 * function returns only the *single-side* maximum extension to the parent,
 * ensuring correctness for parent-child extension. The time complexity is O(N),
 * where N is the number of nodes, as each node is visited once; space
 * complexity is O(H), where H is the height of the tree (O(N) in the worst case
 * for recursion stack).
 */

// Modular helper function is used for clean and educational breakdown.
class Solution {
public:
  int longestUnivaluePath(TreeNode *root) {
    // This variable will hold the maximum univalue path found globally.
    int maxLen = 0;

    // Helper function that returns the length of the longest univalue path
    // that can be extended upwards from this node.
    std::function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
      if (!node)
        return 0; // Base case: null node contributes zero length.

      // Recursively get lengths from left and right children.
      int left = dfs(node->left);
      int right = dfs(node->right);

      // Initialize local extension lengths as 0.
      int leftPath = 0, rightPath = 0;

      // If left child exists and has the same value, we can extend the path.
      if (node->left && node->left->val == node->val) {
        leftPath = left + 1; // Add current edge
      }

      // Do likewise for the right child.
      if (node->right && node->right->val == node->val) {
        rightPath = right + 1;
      }

      // Update the global result with the sum of left and right extensions.
      // This accounts for paths that pass through the current node
      // connecting both sides.
      maxLen = std::max(maxLen, leftPath + rightPath);

      // Return to parent the *single* direction that can be continued (higher
      // of two).
      return std::max(leftPath, rightPath);
    };

    // Kick off the DFS traversal from the root.
    dfs(root);

    // Return the final answer (in edges, not nodes).
    return maxLen;
  }
};
// @lc code=end
