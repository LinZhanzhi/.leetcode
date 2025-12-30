/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
 * The goal is to transform a given Binary Search Tree (BST) so that each node's
 * value becomes the sum of its original value plus all values greater than it
 * in the tree. In other words, for every node, we want to add up all the values
 * that are larger than the current node's value (including itself) and set this
 * as the new value. This leverages the BST property that all values in the
 * right subtree are greater than the current node, and all values in the left
 * subtree are smaller.
 *
 * High-Level Summary:
 * ----
 * The most efficient way to solve this is to traverse the tree in reverse
 * in-order (right -> node -> left), which visits nodes from largest to
 * smallest. We keep a running sum of all previously visited nodes (which are
 * greater), and for each node, we update its value by adding this sum. This
 * approach ensures each node gets the correct "greater sum" value in O(n) time,
 * where n is the number of nodes. The space complexity is O(h), where h is the
 * height of the tree, due to recursion stack.
 */

// Helper function to perform reverse in-order traversal and update node values.
class Solution {
public:
  // Public function to start the conversion process.
  TreeNode *convertBST(TreeNode *root) {
    int runningSum = 0; // This variable will keep track of the sum of all nodes
                        // visited so far.
    convertHelper(root, runningSum); // Start the reverse in-order traversal.
    return root;                     // Return the modified tree root.
  }

private:
  // Helper function that traverses the tree in reverse in-order (right -> node
  // -> left). 'sum' is passed by reference so that all recursive calls share
  // and update the same value.
  void convertHelper(TreeNode *node, int &sum) {
    if (!node)
      return; // Base case: if the node is null, do nothing.

    // First, visit the right subtree (all greater values).
    convertHelper(node->right, sum);

    // Update the running sum and the current node's value.
    // At this point, 'sum' contains the sum of all values greater than the
    // current node.
    sum += node->val; // Add the current node's value to the running sum.
    node->val = sum;  // Update the node's value to the running sum.

    // Then, visit the left subtree (all smaller values).
    convertHelper(node->left, sum);
  }
};
// @lc code=end
