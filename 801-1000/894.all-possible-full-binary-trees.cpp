/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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

/**
 * Brief Digested Understanding:
 * ----
 * This problem asks us to generate every structurally unique full binary tree
 * with exactly n nodes, where each node must have a value of 0, and every node
 * has either 0 or 2 children (full binary tree property). The result should be
 * a list of root nodes, each representing a unique tree structure. n must be
 * odd, since only odd node counts can form full binary trees where internal
 * nodes all have two children. The problem is essentially about generating all
 * valid tree shapes, not filling or searching values.
 *
 * High-Level Summary:
 * ----
 * To generate all possible full binary trees with n nodes, we use a recursive,
 * divide-and-conquer approach:
 * - For each number of nodes assigned to the left subtree (must be odd and
 * between 1 and n-2), recursively generate all left and right subtrees, and
 * connect them to a new root node.
 * - Use memoization to cache results for each n to avoid redundant computation.
 * - Base case: if n==1, return a single-node tree.
 * - Time complexity: The number of possible trees grows exponentially (roughly
 * Catalan numbers for odd n); with memoization, we ensure we only compute for
 * each n value once, but each result list can be large.
 * - Auxiliary space: O(2^n), as we may generate exponentially many unique tree
 * structures for larger n.
 */

#include <unordered_map>
#include <vector>

using std::vector;

// Helper function declarations can be placed outside the main Solution class
// for modularity, or as private members. Here, for clarity, they are included
// as private helpers.

class Solution {
public:
  // The main interface function, called by LeetCode.
  vector<TreeNode *> allPossibleFBT(int n) {
    // Use a memoization map from int (nodes left) to list of tree roots.
    memo.clear(); // Clear cache to ensure no stale data if Solution instance is
                  // reused
    return generateFBT(n);
  }

private:
  // Memoization map to cache all results for given n, so we don't recompute
  // subproblems.
  std::unordered_map<int, vector<TreeNode *>> memo;

  // Helper function to recursively generate all FBTs with 'nodes' nodes.
  vector<TreeNode *> generateFBT(int nodes) {
    // Check memoization: if already computed, reuse it.
    if (memo.count(nodes)) {
      return memo[nodes];
    }

    vector<TreeNode *> res;

    // Base Case:
    // A full binary tree with 1 node is just a single node (must have value 0).
    if (nodes == 1) {
      res.push_back(new TreeNode(0));
      memo[nodes] = res;
      return res;
    }

    // If the number of nodes is even, we cannot form a full binary tree.
    if (nodes % 2 == 0) {
      // No valid full binary tree structure for even number of nodes.
      return res;
    }

    // Divide nodes between a left and right subtree.
    // The root takes 1 node, so nodes-1 nodes left for children.
    // Both left and right must have odd counts, so iterate over all odd l
    // counts (1,3,...,nodes-2)
    for (int left = 1; left < nodes; left += 2) {
      int right = nodes - 1 - left; // Remaining nodes for right subtree

      // Recursively generate all left and right subtree combinations.
      vector<TreeNode *> leftTrees = generateFBT(left);
      vector<TreeNode *> rightTrees = generateFBT(right);

      // For every possible left and right subtree, create a new root and
      // attach.
      for (TreeNode *lsub : leftTrees) {
        for (TreeNode *rsub : rightTrees) {
          TreeNode *root =
              new TreeNode(0); // Node value must be 0 as per the problem
          root->left = lsub;
          root->right = rsub;
          res.push_back(root); // Save this tree configuration
        }
      }
    }

    // Store in memo, then return.
    memo[nodes] = res;
    return res;
  }
};
// @lc code=end
