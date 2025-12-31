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
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * The problem asks us to find the maximum absolute difference between a node and any
 * of its ancestors in a binary tree. An ancestor is any node appearing on the path
 * from the root to the node itself.
 *
 * High-Level Summary:
 * -------------------
 * I will use a bottom-up (post-order) DFS approach as requested.
 * Instead of passing min/max down, each node will return the minimum and maximum
 * values found in its own subtree to its parent.
 *
 * Algorithm:
 * 1. Perform a post-order traversal (DFS).
 * 2. For each node, recursively call DFS on its left and right children to get
 *    the min and max values of the left and right subtrees.
 * 3. The current node is an ancestor to all nodes in its subtrees. Therefore, calculate
 *    the absolute difference between the current node's value and the min/max returned
 *    by its children. Update the global maximum difference `ans` with these values.
 * 4. Compute the min and max for the current subtree (including the current node itself)
 *    and return them to the parent.
 *    - Current Subtree Min = min(node.val, left_subtree_min, right_subtree_min)
 *    - Current Subtree Max = max(node.val, left_subtree_max, right_subtree_max)
 *
 * Time Complexity:
 *   - O(N), where N is the number of nodes. We visit each node once.
 *
 * Space Complexity:
 *   - O(H), where H is the height of the tree, for the recursion stack.
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// @lc code=start
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return maxDiff;
    }

private:
    int maxDiff = 0;

    // Returns a pair {min_val, max_val} for the subtree rooted at 'node'.
    pair<int, int> dfs(TreeNode* node) {
        // Initialize min and max with the current node's value.
        int curMin = node->val;
        int curMax = node->val;

        // Process left child
        if (node->left) {
            pair<int, int> left = dfs(node->left);
            // Since 'node' is an ancestor of the left subtree, check differences
            maxDiff = max(maxDiff, abs(node->val - left.first));
            maxDiff = max(maxDiff, abs(node->val - left.second));

            // Update current subtree's min and max
            curMin = min(curMin, left.first);
            curMax = max(curMax, left.second);
        }

        // Process right child
        if (node->right) {
            pair<int, int> right = dfs(node->right);
            // Since 'node' is an ancestor of the right subtree, check differences
            maxDiff = max(maxDiff, abs(node->val - right.first));
            maxDiff = max(maxDiff, abs(node->val - right.second));

            // Update current subtree's min and max
            curMin = min(curMin, right.first);
            curMax = max(curMax, right.second);
        }

        return {curMin, curMax};
    }
};
// @lc code=end