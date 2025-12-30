/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 */

// Brief, Digested Understanding:
//
// The problem asks us to find the largest value in each row (level) of a binary
// tree. For every level of the tree (from top to bottom), we need to determine
// the maximum value among all nodes at that level. The result should be a list
// where each element corresponds to the largest value found at each level of
// the tree.
//
// In other words, we are "scanning" each row of the tree and picking the
// biggest number in that row.

// High-Level Summary:
//
// The most natural way to process a tree level by level is to use Breadth-First
// Search (BFS) with a queue. For each level, we process all nodes at that
// level, track the maximum value, and then enqueue their children for the next
// level. We repeat this until all levels are processed. The time complexity is
// O(N), where N is the number of nodes, since each node is visited once. The
// space complexity is O(W), where W is the maximum width of the tree (the
// largest number of nodes at any level), due to the queue used for BFS.

#include <queue>  // For std::queue to perform BFS.
#include <vector> // For std::vector to store the result.

using std::queue;
using std::vector;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Helper function to process one level of the tree and return the maximum value
// at that level.
int findLevelMax(queue<TreeNode *> &q, int levelSize) {
  int maxVal =
      q.front()
          ->val; // Initialize maxVal with the first node's value at this level.
  for (int i = 0; i < levelSize; ++i) {
    TreeNode *node = q.front();
    q.pop();
    // Update maxVal if the current node's value is greater.
    if (node->val > maxVal) {
      maxVal = node->val;
    }
    // Enqueue left child if it exists.
    if (node->left) {
      q.push(node->left);
    }
    // Enqueue right child if it exists.
    if (node->right) {
      q.push(node->right);
    }
  }
  return maxVal;
}

class Solution {
public:
  // Main function to find the largest value in each tree row.
  vector<int> largestValues(TreeNode *root) {
    vector<int> result; // This will store the largest value for each level.
    if (!root) {
      // If the tree is empty, return an empty vector.
      return result;
    }

    queue<TreeNode *> q; // Queue for BFS traversal.
    q.push(root);        // Start BFS with the root node.

    // Continue until all levels are processed.
    while (!q.empty()) {
      int levelSize = q.size(); // Number of nodes at the current level.
      // Use the helper to find the max value at this level and enqueue
      // children.
      int maxVal = findLevelMax(q, levelSize);
      result.push_back(maxVal); // Store the max value for this level.
    }

    return result; // Return the list of largest values per level.
  }
};
// @lc code=end
