/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;
    while (prev->next && prev->next->next) {
      ListNode *first = prev->next;
      ListNode *second = first->next;
      // Swap
      first->next = second->next;
      second->next = first;
      prev->next = second;
      // Move prev to next pair
      prev = first;
    }
    return dummy.next;
  }
};
// @lc code=end
