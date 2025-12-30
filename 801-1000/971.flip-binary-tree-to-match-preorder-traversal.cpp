/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given a binary tree and a target preorder traversal sequence oyage.
 * We can swap the left and right children of any node.
 * We need to find the minimum set of nodes to flip so that the tree's preorder traversal matches oyage.
 * If it's impossible, return [-1].
 *
 * High-Level Summary:
 * -------------------
 * We perform a DFS traversal that mimics a preorder traversal (Root -> Left -> Right).
 * We maintain a pointer index to the current expected value in oyage.
 * At each node:
 * 1. Verify if the current node's value matches oyage[index]. If not, the configuration is invalid.
 * 2. If the node has a left child and that child's value does NOT match the next expected value in oyage (oyage[index+1]),
 *    it implies we might need to flip the current node (process Right then Left).
 *    - We record the flip.
 *    - We traverse Right then Left.
 * 3. Otherwise, we proceed with the standard order (Left then Right).
 *
 * Time Complexity: O(N) - We visit each node exactly once.
 * Space Complexity: O(N) - Recursion stack depth and result storage.
 */

#include <vector>
#include <algorithm>

using namespace std;

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

// @lc code=start
class Solution {
private:
    vector<int> flipped_nodes;
    int index;
    bool possible;

    void dfs(TreeNode* node, const vector<int>& voyage) {
        if (!node || !possible) return;

        // Check if current node matches expected value
        if (node->val != voyage[index]) {
            possible = false;
            return;
        }

        // Move to next expected value
        index++;

        // Check if we need to flip
        // If left child exists but doesn't match the next value in voyage,
        // we assume we must flip to try and match the right child instead.
        if (node->left && node->left->val != voyage[index]) {
            flipped_nodes.push_back(node->val);
            dfs(node->right, voyage);
            dfs(node->left, voyage);
        } else {
            // Standard preorder: Left then Right
            dfs(node->left, voyage);
            dfs(node->right, voyage);
        }
    }

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        flipped_nodes.clear();
        index = 0;
        possible = true;

        dfs(root, voyage);

        if (!possible) {
            return {-1};
        }

        return flipped_nodes;
    }
};
// @lc code=end
