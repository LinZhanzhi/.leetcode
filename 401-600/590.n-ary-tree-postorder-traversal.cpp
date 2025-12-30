/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
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
  vector<int> postorder(Node *root) {
    // If the tree is empty, return an empty result
    if (!root)
      return {};
    vector<int> result;
    stack<Node *> stk;
    // Start with the root node
    stk.push(root);
    // Iterate while there are nodes to process
    while (!stk.empty()) {
      Node *node = stk.top();
      stk.pop();
      // Add the node's value to the result
      result.push_back(node->val);
      // Push all children to the stack
      // Children are pushed in order, so after reversal, postorder is achieved
      for (auto child : node->children) {
        if (child)
          stk.push(child);
      }
    }
    // Reverse the result to get postorder traversal
    reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
