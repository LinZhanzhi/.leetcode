/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to find the lexicographically smallest string formed by concatenating characters from a leaf to the root.
 * The tree nodes contain values 0-25 representing 'a'-'z'.
 *
 * High-Level Summary:
 * -------------------
 * We can use Depth First Search (DFS) to traverse from the root to all leaves.
 * We maintain the current path from the root to the current node.
 * When we reach a leaf, we reverse the current path to get the string from leaf to root.
 * We compare this string with the smallest string found so far and update if necessary.
 *
 * Time Complexity: O(N * H), where N is the number of nodes and H is the height of the tree.
 *   - In the worst case (a line with branches at the end), we might do O(N) work for O(N) leaves, but actually the sum of path lengths over all leaves is bounded.
 *   - Specifically, sum of depths of all leaves. In worst case O(N^2) for skewed trees, but typically O(N log N).
 *   - Given N <= 8500, O(N^2) is acceptable (~7*10^7 ops).
 * Space Complexity: O(H) for recursion stack and path storage.
 */

#include <string>
#include <algorithm>
#include <vector>

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
public:
    string smallest = "|"; // Initialize with a value larger than 'z' ('|' is ASCII 124, 'z' is 122)

    void dfs(TreeNode* node, string& path) {
        if (!node) return;

        // Append current character to path
        path.push_back(char('a' + node->val));

        // If leaf node, check the candidate string
        if (!node->left && !node->right) {
            string candidate = path;
            reverse(candidate.begin(), candidate.end());
            if (candidate < smallest) {
                smallest = candidate;
            }
        }

        dfs(node->left, path);
        dfs(node->right, path);

        // Backtrack
        path.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);
        return smallest;
    }
};
// @lc code=end
