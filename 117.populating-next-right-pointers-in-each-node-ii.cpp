/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
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

/*
  Solution Explanation:
  - This solution connects each node's next pointer to its next right node in a
  binary tree (not necessarily perfect).
  - It uses a level-by-level traversal, but instead of a queue, it uses the
  already established next pointers to traverse each level.
  - For each level, a dummy node is used to build the next level's linked list
  via next pointers.
  - 'curr' iterates over the current level, and 'tail' builds the next level.
  - After finishing a level, move to the next level by setting curr =
  dummy.next.
  - This approach uses O(1) extra space (excluding recursion stack).
*/

class Solution {
public:
  Node *connect(Node *root) {
    if (!root)
      return nullptr;
    Node *curr = root;
    // Traverse level by level
    while (curr) {
      Node dummy(0);       // Dummy node to start the next level
      Node *tail = &dummy; // Tail to build the next level's next pointers
      // Iterate over the current level
      while (curr) {
        if (curr->left) {
          tail->next = curr->left; // Link left child if exists
          tail = tail->next;
        }
        if (curr->right) {
          tail->next = curr->right; // Link right child if exists
          tail = tail->next;
        }
        curr = curr->next; // Move to next node in current level
      }
      // Move to the next level
      curr = dummy.next;
    }
    return root;
  }
};
// @lc code=end
