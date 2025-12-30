/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a doubly linked list where each node may have a child pointer to
 * another doubly linked list, potentially forming a multilevel structure. Our
 * goal is to "flatten" this structure into a single-level doubly linked list,
 * so that all nodes appear in a single sequence, and all child pointers are set
 * to null. When a node has a child, the entire child list should be inserted
 * immediately after that node, before its next node.
 *
 * High-Level Summary:
 * ----
 * This solution uses recursion to flatten the multilevel doubly linked list.
 * The main idea is to recursively flatten each child list and insert it between
 * the current node and its next node. The recursive function returns the tail
 * of the flattened list, which allows us to correctly connect the next part of
 * the list after the child. This approach naturally follows the depth-first
 * traversal order and is easy to understand, as each recursive call handles one
 * level of the list at a time.
 *
 * Time Complexity: O(N), where N is the total number of nodes in all levels
 * (each node is visited once). Space Complexity: O(N) in the worst case due to
 * recursion stack (if the list is deeply nested).
 */

class Solution {
public:
  // Public function to flatten the list starting from head.
  Node *flatten(Node *head) {
    // Edge case: if the list is empty, just return null.
    if (!head)
      return nullptr;

    // Call the recursive helper to flatten the list.
    flattenDFS(head);

    // Return the head of the flattened list.
    return head;
  }

private:
  // Helper function that flattens the list starting from 'node'.
  // It returns the tail node of the flattened list.
  Node *flattenDFS(Node *node) {
    Node *curr = node; // Pointer to traverse the list.
    Node *last =
        node; // Will keep track of the last node in the flattened list.

    while (curr) {
      Node *next =
          curr->next; // Save the next node, as we may overwrite curr->next.

      // If the current node has a child, we need to flatten the child list.
      if (curr->child) {
        // Recursively flatten the child list. The function returns the tail of
        // the child list.
        Node *childTail = flattenDFS(curr->child);

        // Connect the current node's next to its child.
        curr->next = curr->child;
        curr->child->prev = curr;

        // If there was a next node, connect the tail of the child list to it.
        if (next) {
          childTail->next = next;
          next->prev = childTail;
        }

        // Set the child pointer to null as required by the problem.
        curr->child = nullptr;

        // Move last pointer to the tail of the child list.
        last = childTail;
      } else {
        // If there is no child, the last node is the current node.
        last = curr;
      }

      // Move to the next node (which may have been updated if there was a
      // child).
      curr = next;
    }

    // Return the last node in the flattened list segment.
    return last;
  }
};
// @lc code=end
