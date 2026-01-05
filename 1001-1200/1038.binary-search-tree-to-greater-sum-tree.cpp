/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to transform a Binary Search Tree (BST) into a "Greater Sum Tree".
 * In this new tree, each node's value is updated to be the sum of its original value plus all values in the tree that are greater than it.
 * Since it's a BST, "greater" values are found in the right subtree and in the ancestors where the current node is in the left subtree.
 * Essentially, we want to accumulate sums starting from the largest value down to the smallest.
 *
 * High-Level Summary:
 * -------------------
 * 1. **Reverse In-Order Traversal**: A standard in-order traversal (Left -> Root -> Right) visits nodes in ascending order.
 *    If we reverse this (Right -> Root -> Left), we visit nodes in descending order (largest to smallest).
 * 2. **Running Sum**: We maintain a running sum of all nodes visited so far.
 *    - As we visit each node in this reverse order, we add its value to the running sum.
 *    - Then, we update the node's value to this new running sum.
 *    - This works because at any point, the running sum contains the sum of all nodes greater than the current node (visited previously) plus the current node itself.
 *
 * Time Complexity: O(N), where N is the number of nodes. We visit each node exactly once.
 * Space Complexity: O(H), where H is the height of the tree, due to the recursion stack.
 */

class Solution {
private:
    int currentSum = 0; // Stores the sum of all nodes visited so far (which are greater than the current node).

    void reverseInorder(TreeNode* node) {
        if (!node) return;

        // 1. Traverse the right subtree first (larger values).
        reverseInorder(node->right);

        // 2. Process the current node.
        // Add the current node's value to the running sum.
        currentSum += node->val;
        // Update the current node's value to the new sum.
        node->val = currentSum;

        // 3. Traverse the left subtree (smaller values).
        reverseInorder(node->left);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        currentSum = 0; // Initialize sum.
        reverseInorder(root);
        return root;
    }
};