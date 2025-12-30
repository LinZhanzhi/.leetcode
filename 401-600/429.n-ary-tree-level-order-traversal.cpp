/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to traverse an n-ary tree (where each node can have any number of
 * children) level by level, from top to bottom, and collect the values of nodes
 * at each level into separate lists. The result should be a list of lists,
 * where each inner list contains the values of nodes at a particular depth in
 * the tree.
 *
 * In other words, we want to visit all nodes at depth 0, then all at depth 1,
 * then depth 2, etc., and group their values together.
 */

/*
 * High-Level Summary:
 * ----
 * We use a Breadth-First Search (BFS) approach, which is ideal for level order
 * traversal. BFS uses a queue to process nodes level by level. For each level,
 * we:
 *   - Determine how many nodes are at the current level (by the queue's size).
 *   - Process each node at this level: record its value, and enqueue all its
 * children for the next level.
 *   - After processing all nodes at the current level, add the collected values
 * to the result.
 *
 * Time Complexity: O(N), where N is the total number of nodes (each node is
 * visited once). Space Complexity: O(N), for the queue and the result storage.
 */

// @lc code=start
#include <queue>  // For std::queue
#include <vector> // For std::vector

using std::queue;
using std::vector;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  // Function to perform level order traversal on an n-ary tree.
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>>
        result; // This will store the final level order traversal.

    // Edge case: If the tree is empty, return an empty result.
    if (!root)
      return result;

    queue<Node *> q; // Queue to facilitate BFS traversal.
    q.push(root);    // Start with the root node.

    // Continue until there are no more nodes to process.
    while (!q.empty()) {
      int levelSize = q.size(); // Number of nodes at the current level.
      vector<int> currentLevel; // To store values of nodes at this level.

      // Process all nodes at the current level.
      for (int i = 0; i < levelSize; ++i) {
        Node *node = q.front(); // Get the next node in the queue.
        q.pop();                // Remove it from the queue.

        currentLevel.push_back(
            node->val); // Add its value to the current level.

        // Enqueue all children of the current node for the next level.
        for (Node *child : node->children) {
          if (child) { // Check for non-null children (defensive, though usually
                       // not needed).
            q.push(child);
          }
        }
      }
      // After processing the current level, add it to the result.
      result.push_back(currentLevel);
    }

    return result; // Return the level order traversal.
  }
};
// @lc code=end
