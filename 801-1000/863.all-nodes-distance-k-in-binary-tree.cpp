/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>         // For BFS traversal.
#include <unordered_map> // For mapping from node pointer to its parent pointer.
#include <unordered_set> // For visited set to avoid revisiting nodes.
#include <vector>        // For the vector container.

using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;

/**
 * ---------------------------------------------------------------------------
 * Brief Digested Understanding:
 * ---------------------------------------------------------------------------
 * The problem asks us to find all the nodes in a binary tree that are exactly
 * K edges away from a given target node. The "distance" is the number of edges
 * connecting two nodes, and we can travel both upwards (towards parents) and
 * downwards (toward children), unlike regular tree traversals. So, the
 * challenge is not just traversing children from the target, but also
 * potentially needing to go up to the parent and back down another branch.
 *
 * The key idea is that from the target, we can expand to "neighbors" in any
 * direction. This is somewhat like finding all nodes at `K` distance in an
 * undirected graph, where each tree link (child or parent) is an edge.
 *
 * ---------------------------------------------------------------------------
 * High-Level Summary:
 * ---------------------------------------------------------------------------
 * The solution transforms the binary tree into an undirected graph context
 * by recording parent pointers for every node, so each node is aware of its
 * parent as well as its children.
 *
 * Steps:
 *   1. Traverse the tree and build a mapping of each node to its parent.
 *   2. Starting at the target node, do a breadth-first search (BFS), treating
 *      neighbors as left, right, and parent (if they exist and haven't been
 *      visited yet), counting each BFS level as 1 unit of distance.
 *   3. When the BFS reaches the k-th level, collect all node values in the
 * current layer.
 *
 * This method ensures that we visit every node exactly once and efficiently
 * gather the answer.
 *
 * Time Complexity: O(N), where N is the number of nodes (since each node is
 * visited at most once).
 * Space Complexity: O(N), for the parent map and queues/sets used.
 */

// Helper function to create a mapping from child nodes to their parent nodes.
void buildParentMap(TreeNode *node, TreeNode *parent,
                    unordered_map<TreeNode *, TreeNode *> &parentMap) {
  if (node == nullptr)
    return;                 // Base case: null node.
  parentMap[node] = parent; // Map current node to its parent.
  buildParentMap(node->left, node, parentMap);  // Recurse on left subtree.
  buildParentMap(node->right, node, parentMap); // Recurse on right subtree.
}

// Helper function to perform a BFS search outward from the target,
// considering left, right, and parent as neighbors.
// Returns all node values at distance exactly k from the target node.
vector<int>
bfsFindNodesAtDistanceK(TreeNode *target, int k,
                        unordered_map<TreeNode *, TreeNode *> &parentMap) {
  unordered_set<TreeNode *>
      visited; // Set to keep track of visited nodes so we don't revisit them.
  queue<TreeNode *> q; // Queue for BFS.
  int currDistance =
      0; // Current BFS layer represents the distance from the target.

  // Start BFS from the target node.
  q.push(target);
  visited.insert(target);

  // Standard BFS loop, processing levels one at a time.
  while (!q.empty()) {
    int levelSize = q.size(); // Number of nodes at the current distance.
    if (currDistance == k) {
      // If we've reached the desired distance, collect all node values at this
      // level.
      vector<int> result;
      for (int i = 0; i < levelSize; ++i) {
        TreeNode *node = q.front();
        q.pop();
        result.push_back(node->val);
      }
      // Once we've collected the results at distance k, return immediately.
      return result;
    }
    // For each node at the current BFS level, expand to its unvisited
    // neighbors.
    for (int i = 0; i < levelSize; ++i) {
      TreeNode *node = q.front();
      q.pop();

      // Visit the left child if it exists and hasn't been visited.
      if (node->left && visited.find(node->left) == visited.end()) {
        q.push(node->left);
        visited.insert(node->left);
      }
      // Visit the right child if it exists and hasn't been visited.
      if (node->right && visited.find(node->right) == visited.end()) {
        q.push(node->right);
        visited.insert(node->right);
      }
      // Visit the parent if it exists and hasn't been visited.
      TreeNode *parent = parentMap[node];
      if (parent && visited.find(parent) == visited.end()) {
        q.push(parent);
        visited.insert(parent);
      }
    }
    // Move to the next layer/distance in BFS.
    currDistance++;
  }
  // If no nodes are exactly distance k away, return an empty vector.
  return vector<int>();
}

class Solution {
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    // Step 1: Build parent pointers for each node.
    unordered_map<TreeNode *, TreeNode *>
        parentMap; // Maps a child node to its parent.
    buildParentMap(root, nullptr, parentMap);

    // Step 2: BFS from the target node to find all nodes at exactly k distance.
    return bfsFindNodesAtDistanceK(target, k, parentMap);
  }
};
// @lc code=end
