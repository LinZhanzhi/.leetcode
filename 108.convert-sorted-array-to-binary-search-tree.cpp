/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return buildBST(nums.data(), 0, nums.size() - 1);
    }
    
private:
    // Use pointer arithmetic to avoid repeated bounds checking and vector indexing
    TreeNode* buildBST(const int* arr, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(*(arr + mid));
        root->left = buildBST(arr, left, mid - 1);
        root->right = buildBST(arr, mid + 1, right);
        return root;
    }
};
// @lc code=end
