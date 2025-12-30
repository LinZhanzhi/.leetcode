/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  // This function clones an undirected graph using DFS and a hash map to keep
  // track of already cloned nodes. The key idea is to recursively clone each
  // node and its neighbors, while avoiding cycles by storing already cloned
  // nodes in a map.
  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr; // If the input node is null, return null.

    // Map to keep track of cloned nodes. Key: original node, Value: cloned
    // node.
    unordered_map<Node *, Node *> cloned;

    // DFS function to clone the graph.
    function<Node *(Node *)> dfs = [&](Node *curr) -> Node * {
      // If the node is already cloned, return the clone.
      if (cloned.count(curr))
        return cloned[curr];

      // Create a new node with the same value as the current node.
      Node *copy = new Node(curr->val);
      // Store the clone in the map before cloning neighbors to handle cycles.
      cloned[curr] = copy;

      // Recursively clone all the neighbors.
      for (Node *neighbor : curr->neighbors) {
        copy->neighbors.push_back(dfs(neighbor));
      }
      return copy;
    };

    // Start DFS from the given node.
    return dfs(node);
  }
};
// @lc code=end
