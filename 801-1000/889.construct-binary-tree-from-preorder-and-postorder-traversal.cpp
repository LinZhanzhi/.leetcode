/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 */

// Brief Digested Understanding:
// ----
// Given the preorder and postorder traversals of a binary tree with unique
// values, the problem asks us to reconstruct the original tree. We know the
// tree is valid and all elements are unique. The preorder lists root first,
// then left subtree, then right subtree. Postorder lists left subtree, then
// right subtree, then root. There can be multiple valid trees since preorder
// and postorder together do not always uniquely identify a binary tree unless
// certain structural constraints are present. We're allowed to return any valid
// reconstruction.

// High-Level Summary:
// ----
// The main algorithm operates recursively.
// At each step, the first element in preorder is the root of the current
// subtree. The next element in preorder is always the root of the left subtree
// (if it exists). We find the left subtree's root value in postorder, which
// lets us deduce the size of the left subtree. Knowing this, we can partition
// preorder and postorder ranges accordingly and recursively build left and
// right subtrees. We build a map from value to index for O(1) lookups in
// postorder. The time complexity is O(N), as each node is visited once, and
// with index map, no repeated scanning; space is O(N) for recursion and the
// map.

#include <unordered_map> // For fast value-to-index mapping in postorder.
#include <vector>        // For std::vector to represent traversal arrays.

using std::unordered_map;
using std::vector;

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
  // Helper function to construct the tree from preorder and postorder
  TreeNode *build(const vector<int> &preorder, int preStart, int preEnd,
                  const vector<int> &postorder, int postStart, int postEnd,
                  const unordered_map<int, int> &postIndexMap) {
    // Base case: if there are no elements to consider
    if (preStart > preEnd || postStart > postEnd)
      return nullptr;

    // Create the root node with the first element of preorder
    TreeNode *root = new TreeNode(preorder[preStart]);

    // If there is only one node in this subtree, return it (leaf case)
    if (preStart == preEnd)
      return root;

    // The left child's value (guaranteed to exist because preStart < preEnd)
    int leftChildVal = preorder[preStart + 1];

    // Find the position of the left child's value in postorder for subtree size
    int idx = postIndexMap.at(leftChildVal);

    // Number of nodes in the left subtree
    int leftSize = idx - postStart + 1;

    // Recursively build left and right subtrees
    root->left = build(preorder, preStart + 1, preStart + leftSize, postorder,
                       postStart, idx, postIndexMap);

    root->right = build(preorder, preStart + leftSize + 1, preEnd, postorder,
                        idx + 1, postEnd - 1, postIndexMap);

    return root;
  }

  // Main entry: wrapper around helper function
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    // Edge case: if input is empty, return nullptr
    if (preorder.empty() || postorder.empty())
      return nullptr;

    // Build a value->index hash map for O(1) lookups in postorder
    unordered_map<int, int> postIndexMap;
    for (int i = 0; i < postorder.size(); ++i) {
      postIndexMap[postorder[i]] = i;
    }

    // Initiate recursive building for the full range of both lists
    return build(preorder, 0, preorder.size() - 1, postorder, 0,
                 postorder.size() - 1, postIndexMap);
  }
};
// @lc code=end
