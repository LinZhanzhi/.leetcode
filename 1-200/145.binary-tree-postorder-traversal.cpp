/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;
        
        // Iterative postorder traversal using stack
        while (current != nullptr || !st.empty()) {
            // Go to the leftmost node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            
            // Check if we can process the current node
            current = st.top();
            
            // If right child exists and hasn't been visited, go to right subtree
            if (current->right != nullptr && current->right != lastVisited) {
                current = current->right;
            } else {
                // Process current node (root)
                result.push_back(current->val);
                lastVisited = current;
                st.pop();
                current = nullptr;  // Move back up the tree
            }
        }
        
        return result;
    }
};
// @lc code=end

