/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        // No extra stack or queue, no extra data structures, just recursion
        return checkHeight(root) != -2;
    }
private:
    // Returns height if balanced, -2 if unbalanced
    int checkHeight(TreeNode* node) {
        if (!node) return -1; // height of empty tree is -1
        int lh = checkHeight(node->left);
        if (lh == -2) return -2;
        int rh = checkHeight(node->right);
        if (rh == -2) return -2;
        if (lh - rh > 1 || rh - lh > 1) return -2;
        return (lh > rh ? lh : rh) + 1;
    }
};
// @lc code=end
