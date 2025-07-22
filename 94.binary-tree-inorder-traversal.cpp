/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        
        // Iterative inorder traversal using stack
        while (current != nullptr || !st.empty()) {
            // Go to the leftmost node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            
            // Process current node
            current = st.top();
            st.pop();
            result.push_back(current->val);
            
            // Move to right subtree
            current = current->right;
        }
        
        return result;
    }
};
// @lc code=end

