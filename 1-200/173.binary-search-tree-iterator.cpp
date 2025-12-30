/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
#include <stack>

class BSTIterator {
private:
  std::stack<TreeNode *> stk;

  // Helper to push all left children of a node onto the stack
  void pushLeft(TreeNode *node) {
    while (node) {
      stk.push(node);
      node = node->left;
    }
  }

public:
  BSTIterator(TreeNode *root) {
    // Initialize the stack with the leftmost path from root
    pushLeft(root);
  }

  int next() {
    // The top of the stack is the next smallest element
    TreeNode *node = stk.top();
    stk.pop();
    int res = node->val;
    // If the node has a right child, push all its left children
    if (node->right) {
      pushLeft(node->right);
    }
    return res;
  }

  bool hasNext() { return !stk.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
