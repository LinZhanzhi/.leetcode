/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given the preorder traversal of a Binary Search Tree (BST) and need to reconstruct the tree.
 * Preorder traversal visits nodes in the order: Root -> Left -> Right.
 * A key property of BST is that for any node, all values in the left subtree are smaller,
 * and all values in the right subtree are larger.
 *
 * High-Level Summary:
 * -------------------
 * We can use a recursive approach with an upper bound constraint.
 * We maintain a global index \idx\ to traverse the \preorder\ array.
 * For each function call, we pass a \ound\.
 * - If the current value \preorder[idx]\ is greater than \ound\, it means this value does not belong
 *   to the current subtree (it belongs to an ancestor's right subtree). We return nullptr.
 * - Otherwise, we create a new node with \preorder[idx]\ and increment \idx\.
 * - We recursively construct the left subtree with the current node's value as the new bound.
 * - We recursively construct the right subtree with the original bound.
 *
 * Time Complexity: O(N), where N is the number of nodes. We visit each element in the array exactly once.
 * Space Complexity: O(H), where H is the height of the tree, for the recursion stack.
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
#include <vector>
#include <climits>

using namespace std;

class Solution {
private:
    int idx = 0;

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int bound) {
        // If we have processed all elements or the current element exceeds the bound,
        // it cannot be part of the current subtree.
        if (idx == preorder.size() || preorder[idx] > bound) {
            return nullptr;
        }

        // Create the root node for the current subtree
        TreeNode* root = new TreeNode(preorder[idx++]);

        // Construct the left subtree. All elements must be smaller than the current root's value.
        root->left = build(preorder, root->val);

        // Construct the right subtree. All elements must be smaller than the parent's bound.
        root->right = build(preorder, bound);

        return root;
    }
};
// @lc code=end
