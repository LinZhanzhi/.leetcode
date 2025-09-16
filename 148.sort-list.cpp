/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
  // Helper function to merge two sorted lists
  ListNode *merge(ListNode *l1, ListNode *l2) {
    // Dummy node for the sorted list
    ListNode dummy(0);
    ListNode *tail = &dummy;
    // Merge the two lists
    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    // Append the remaining nodes
    if (l1)
      tail->next = l1;
    if (l2)
      tail->next = l2;
    // Return the sorted list
    return dummy.next;
  }

  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    // Find the middle of the list
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // Cut the list into two halves
    prev->next = nullptr;

    // Sort each half
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);

    // Merge sorted halves
    return merge(l1, l2);
  }
};
// @lc code=end
