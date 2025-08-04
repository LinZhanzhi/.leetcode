/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;

    // First pass: interleave copied nodes with original nodes
    Node *curr = head;
    while (curr) {
      Node *copy = new Node(curr->val);
      copy->next = curr->next;
      curr->next = copy;
      curr = copy->next;
    }

    // Second pass: assign random pointers for the copied nodes
    curr = head;
    while (curr) {
      if (curr->random) {
        curr->next->random = curr->random->next;
      }
      curr = curr->next->next;
    }

    // Third pass: separate the original and copied lists
    curr = head;
    Node *copiedHead = head->next;
    while (curr) {
      Node *copy = curr->next;
      curr->next = copy->next;
      if (copy->next) {
        copy->next = copy->next->next;
      }
      curr = curr->next;
    }

    return copiedHead;
  }
};
// @lc code=end
