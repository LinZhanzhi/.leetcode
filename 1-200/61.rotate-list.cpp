/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next || k == 0)
      return head;

    // First, compute the length of the list and get the tail
    int len = 1;
    ListNode *tail = head;
    while (tail->next) {
      tail = tail->next;
      len++;
    }

    // Make the list circular
    tail->next = head;

    // Find the new tail: (len - k % len - 1)th node
    // and the new head: (len - k % len)th node
    k = k % len;
    int stepsToNewHead = len - k;
    ListNode *newTail = tail;
    while (stepsToNewHead--) {
      newTail = newTail->next;
    }
    ListNode *newHead = newTail->next;

    // Break the circle
    newTail->next = nullptr;

    return newHead;
  }
};
// @lc code=end
