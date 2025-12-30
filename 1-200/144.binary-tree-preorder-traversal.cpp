/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        
        // Push root onto stack if it exists
        if (root != nullptr) {
            st.push(root);
        }
        
        // Iterative preorder traversal using stack
        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();
            
            // Process current node (root)
            result.push_back(current->val);
            
            // Push right child first, then left child
            // (so left child is processed first due to stack LIFO)
            if (current->right != nullptr) {
                st.push(current->right);
            }
            if (current->left != nullptr) {
                st.push(current->left);
            }
        }
        
        return result;
    }
};
// @lc code=end

