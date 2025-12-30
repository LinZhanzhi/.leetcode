/*
 * @lc app=leetcode id=998 lang=cpp
 *
 * [998] Maximum Binary Tree II
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * The problem asks us to insert a new value \al\ into an existing Maximum Binary Tree.
 * A Maximum Binary Tree is defined recursively: the root is the maximum value in the array,
 * the left child is the Maximum Binary Tree of the subarray to the left, and the right child
 * is the Maximum Binary Tree of the subarray to the right.
 * Crucially, the new value \al\ is appended to the *end* of the underlying array \\.
 * We need to return the new root of the tree representing \ + [val]\.
 *
 * High-Level Summary:
 * -------------------
 * Since \al\ is appended to the end of the array, it will always be to the "right" of any node
 * that is larger than it.
 * 1. If \al\ is larger than the current \
oot\, then \al\ becomes the new root. The old \
oot\
 *    (representing the entire original array) becomes the left child of \al\ because the original
 *    array comes before \al\.
 * 2. If \al\ is smaller than the current \
oot\, then \al\ belongs in the right subtree of \
oot\.
 *    We recursively insert \al\ into \
oot->right\.
 *
 * Time Complexity: O(H), where H is the height of the tree. In the worst case (skewed tree), O(N).
 * Space Complexity: O(H) due to recursion stack.
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // Base case: If the tree is empty (or we reached a null link),
        // the new value forms a new leaf node.
        if (!root) {
            return new TreeNode(val);
        }

        // Case 1: The new value is greater than the current root's value.
        // Since \al\ is appended to the end of the array, it is the new maximum
        // of the range covering the current tree plus \al\.
        // The entire current tree (\
oot\) corresponds to elements that appear
        // *before* \al\ in the array. Thus, \
oot\ becomes the left child of the new node.
        if (val > root->val) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // Case 2: The new value is smaller than the current root's value.
        // Since \al\ is at the end of the array, it belongs to the subarray
        // corresponding to the right child of the current root.
        // We recursively insert \al\ into the right subtree.
        root->right = insertIntoMaxTree(root->right, val);

        // Return the unchanged root of the current subtree.
        return root;
    }
};
// @lc code=end
