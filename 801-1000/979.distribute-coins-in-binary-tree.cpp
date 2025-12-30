/*
 * @lc app=leetcode id=979 lang=cpp
 *
 * [979] Distribute Coins in Binary Tree
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We have a binary tree with N nodes and N coins in total.
 * We want to distribute the coins such that every node has exactly 1 coin.
 * We can move coins between adjacent nodes (parent-child).
 * We need to find the minimum number of moves.
 *
 * High-Level Summary:
 * -------------------
 * This problem can be solved using a post-order traversal (DFS).
 * For any subtree, if it has C coins and N nodes, it has an excess of C - N coins.
 * - If C - N > 0, it means this subtree has extra coins that must be moved out to its parent.
 * - If C - N < 0, it means this subtree needs coins from its parent.
 * - The number of moves required for the edge connecting this subtree to its parent is exactly bs(C - N).
 *
 * We can compute this balance for every node (representing the subtree rooted at that node).
 * The total moves will be the sum of bs(balance) for all nodes.
 *
 * Algorithm:
 * 1. Define a helper function dfs(node) that returns the "balance" of the subtree rooted at
ode.
 *    Balance = (coins in left subtree excess) + (coins in right subtree excess) + (node.val - 1).
 *    Wait, let's refine:
 *    dfs(node) returns the excess coins of the subtree rooted at
ode.
 *    Excess =
ode.val + left_excess + right_excess - 1.
 *    (The -1 is because the node itself needs 1 coin).
 * 2. In the DFS, we add bs(left_excess) + abs(right_excess) to the global moves counter.
 *    This counts the moves across the edges connecting
ode to
ode->left and
ode to
ode->right.
 * 3. The base case is when
ode is null, returning 0 excess.
 *
 * Time Complexity: O(N) - We visit every node once.
 * Space Complexity: O(H) - Recursion stack height.
 */

#include <cmath>
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
    int moves = 0;

    // Returns the excess coins in the subtree rooted at 'node'.
    // Positive value means the subtree has extra coins to give to parent.
    // Negative value means the subtree needs coins from parent.
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left_excess = dfs(node->left);
        int right_excess = dfs(node->right);

        // The number of moves through the edges connecting to children
        // is the absolute value of the excess flow.
        moves += abs(left_excess) + abs(right_excess);

        // Current node's excess is its own value + children's excess - 1 (for itself)
        return node->val + left_excess + right_excess - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
// @lc code=end
