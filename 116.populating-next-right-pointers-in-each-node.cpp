/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node *connect(Node *root) {
    // If the tree is empty, return nullptr
    if (!root)
      return nullptr;

    // Start with the leftmost node of the current level (initially root)
    Node *leftmost = root;

    // Since it's a perfect binary tree, if leftmost->left is nullptr, we've
    // reached the last level
    while (leftmost->left) {
      // Traverse the current level using the next pointers
      Node *head = leftmost;
      while (head) {
        // Connect the left child to the right child
        head->left->next = head->right;

        // If there is a next node, connect the right child to the next node's
        // left child
        if (head->next) {
          head->right->next = head->next->left;
        }
        // Move to the next node in the current level
        head = head->next;
      }
      // Move down to the leftmost node of the next level
      leftmost = leftmost->left;
    }
    // Return the root after all next pointers are set
    return root;
  }
};
// @lc code=end
