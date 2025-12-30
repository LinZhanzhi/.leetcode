/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode dummy(0); // Dummy node for the sorted list
    dummy.next = nullptr;

    ListNode *curr = head;
    while (curr) {
      ListNode *next = curr->next; // Save next node to process

      // Find the correct place to insert curr in the sorted part
      ListNode *prev = &dummy;
      while (prev->next && prev->next->val < curr->val) {
        prev = prev->next;
      }

      // Insert curr between prev and prev->next
      curr->next = prev->next;
      prev->next = curr;

      curr = next; // Move to the next node in the original list
    }

    return dummy.next;
  }
};
// @lc code=end
