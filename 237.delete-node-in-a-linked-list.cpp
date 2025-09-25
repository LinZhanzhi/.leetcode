/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

/*
 * Brief, Digested Understanding:
 * ----
 * In this problem, you are given a node from a singly-linked list (not the
 * head), and you need to "delete" this node from the list. However, you do not
 * have access to the head of the list or the previous node. The goal is to
 * remove the given node's value from the list and ensure the list remains
 * valid, with all other nodes in order. Since you can't actually remove the
 * node pointer itself (because you don't have the previous node), you must
 * instead overwrite the node's value and next pointer so that the list appears
 * as if the node was deleted.
 *
 * High-Level Summary:
 * ----
 * The solution works by copying the value from the next node into the current
 * node, and then updating the current node's next pointer to skip over the next
 * node. This effectively removes the next node from the list, but since the
 * current node now contains the next node's value, it appears as if the
 * original node was deleted. This approach is possible because the node to be
 * deleted is guaranteed not to be the last node in the list.
 *
 * Time Complexity: O(1) — Only a constant number of operations are performed.
 * Space Complexity: O(1) — No extra space is used.
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  void deleteNode(ListNode *node) {
    // The node to be "deleted" is not the last node, so node->next is
    // guaranteed to exist.

    // Step 1: Copy the value from the next node into the current node.
    // This makes the current node's value the same as the next node's value.
    node->val = node->next->val;

    // Step 2: Update the current node's next pointer to skip the next node.
    // This effectively removes the next node from the list, as nothing points
    // to it now.
    ListNode *nodeToDelete =
        node->next; // Store the node to be deleted for clarity.
    node->next = node->next->next;

    // (Optional in C++): Free the memory of the removed node.
    // In LeetCode, this is not strictly necessary, but it's good practice in
    // C++.
    delete nodeToDelete;
  }
};
// @lc code=end
