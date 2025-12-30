/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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
 * We are given a binary tree and want to find the smallest subtree that
 * contains all of the deepest nodes (i.e., nodes that are farthest from the
 * root). The answer should be the root of the lowest subtree that has all the
 * deepest nodes as descendants. In essence, this is the lowest common ancestor
 * (LCA) of all the deepest leaves. If there is only one deepest node, it itself
 * forms the required subtree.
 */

/*
 * High-Level Summary:
 * ----
 * To solve this problem, we traverse the entire tree in a post-order fashion.
 * At each node, we compute the deepest depth among its descendants and find
 * which node in its subtree acts as the LCA of all deepest nodes. If the left
 * and right subtrees have the same maximum depth, then this node is the LCA for
 * all deepest nodes found so far. Otherwise, we propagate the answer upward
 * from the side which contains nodes at the greater depth. We use a helper
 * function returning both the maximum depth and subtree pointer. This approach
 * ensures O(N) time and space complexity for N nodes, efficiently visiting each
 * node once.
 */

class Solution {
public:
  // Helper function definition:
  // Returns a pair: (the pointer to the answer subtree, and its maximum depth
  // from here)
  std::pair<TreeNode *, int> deepestSubtreeHelper(TreeNode *node) {
    // Base Case: null node has depth -1 and no subtree
    if (!node)
      return {nullptr, -1};

    // Recursively compute for left and right children
    auto left = deepestSubtreeHelper(node->left);
    auto right = deepestSubtreeHelper(node->right);

    // If both sides are of equal maximum depth,
    // current node is the LCA (lowest common ancestor) of deepest nodes
    if (left.second == right.second) {
      // Depth from this node to the deepest leaf is left.second + 1
      return {node, left.second + 1};
    }
    // Otherwise, propagate the deeper side up
    if (left.second > right.second) {
      // The left child subtree has all the deepest nodes
      return {left.first, left.second + 1};
    } else {
      // The right child subtree has all the deepest nodes
      return {right.first, right.second + 1};
    }
  }

  // Main function to be called by the user or online judge
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    // Call the helper to get both the answer subtree's root and the relevant
    // depth
    return deepestSubtreeHelper(root).first;
  }
};
// @lc code=end
