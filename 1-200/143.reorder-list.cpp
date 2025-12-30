/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
  void reorderList(ListNode *head) {
    if (!head || !head->next || !head->next->next)
      return;

    // Step 1: Find the middle of the list
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    ListNode *prev = nullptr;
    ListNode *curr = slow->next;
    while (curr) {
      ListNode *nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    slow->next = nullptr; // Cut the list

    // Step 3: Merge the two halves
    ListNode *first = head;
    ListNode *second = prev;
    while (second) {
      ListNode *tmp1 = first->next;
      ListNode *tmp2 = second->next;
      first->next = second;
      second->next = tmp1;
      first = tmp1;
      second = tmp2;
    }
  }
};
// @lc code=end
