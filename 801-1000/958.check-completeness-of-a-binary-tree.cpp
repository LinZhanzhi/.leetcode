/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/**
 * Brief Digested Understanding:
 * ----
 * For this problem, we are given the root of a binary tree and want to
 * determine whether this tree is "complete". In simple terms, a complete binary
 * tree has all its levels fully filled except possibly the last, and every node
 * in the last level is as far to the left as it can be. There can't be any gaps
 * in the tree where a left-side child is missing but right-side or further ones
 * exist.
 *
 * High-Level Summary:
 * ----
 * To check for completeness, we will use a breadth-first search (BFS) or
 * level-order traversal using a queue. We'll process nodes level by level, from
 * left to right. The idea is that once we encounter a null/missing child (i.e.,
 * a nullptr in the queue), all subsequent nodes in the BFS must also be null.
 * If instead we encounter a non-null node after a null node, the tree is not
 * complete.
 *
 * This approach works because a complete tree never has a non-null child after
 * a null has appeared in the level-order sequence. The time complexity is O(N)
 * where N is the number of nodes (since every node is visited once), and the
 * space complexity is also O(N) in the worst case (for the queue).
 */

// Include necessary headers for queue data structure
#include <queue>
using std::queue;

class Solution {
public:
  // Public method to check if a binary tree is complete
  bool isCompleteTree(TreeNode *root) {
    // Return true immediately if the tree has no nodes (technically complete)
    if (!root)
      return true;

    // Use a queue for the standard BFS (level-order traversal)
    queue<TreeNode *> q;
    q.push(root);

    // This flag becomes true after the first null child is seen
    bool end = false;

    // Begin BFS
    while (!q.empty()) {
      // Retrieve and remove the front of the queue
      TreeNode *current = q.front();
      q.pop();

      if (current == nullptr) {
        // Once we see a nullptr, set end flag
        end = true;
      } else {
        // If we see a non-null node after a null node, the tree is not complete
        if (end) {
          return false;
        }
        // Always add left and right children (may be nullptr) for proper order
        q.push(current->left);
        q.push(current->right);
      }
    }
    // If we finish BFS without contradiction, the tree is complete
    return true;
  }
};
// @lc code=end
