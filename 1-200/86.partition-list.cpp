/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
  ListNode *partition(ListNode *head, int x) {
    // Create two dummy nodes to start the before and after lists.
    // 'before_head' will be the head of the list with nodes < x.
    // 'after_head' will be the head of the list with nodes >= x.
    ListNode *before_head = new ListNode(0);
    ListNode *after_head = new ListNode(0);

    // 'before' and 'after' are pointers used to build the two lists.
    ListNode *before = before_head;
    ListNode *after = after_head;

    // Traverse the original list.
    while (head != nullptr) {
      if (head->val < x) {
        // If the current node's value is less than x,
        // append it to the 'before' list.
        before->next = head;
        before = before->next;
      } else {
        // Otherwise, append it to the 'after' list.
        after->next = head;
        after = after->next;
      }
      // Move to the next node in the original list.
      head = head->next;
    }

    // Terminate the 'after' list to avoid cycles.
    after->next = nullptr;

    // Connect the 'before' list with the 'after' list.
    before->next = after_head->next;

    // The head of the new list is the next node after the dummy 'before_head'.
    ListNode *result = before_head->next;

    // Clean up the dummy nodes to avoid memory leaks.
    delete before_head;
    delete after_head;

    // Return the head of the partitioned list.
    return result;
  }
};
// @lc code=end
