/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    // Use a dummy node to handle edge cases (e.g., head needs to be removed)
    ListNode dummy(0, head);
    ListNode *current = &dummy;

    while (current->next != nullptr) {
      if (current->next->val == val) {
        // Remove the node by skipping it
        ListNode *temp = current->next;
        current->next = current->next->next;
        delete temp; // Free memory if required
      } else {
        current = current->next;
      }
    }

    return dummy.next;
  }
};
// @lc code=end
