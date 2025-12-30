/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
  ListNode *deleteDuplicates(ListNode *head) {
    // INSERT_YOUR_CODE
    if (!head)
      return nullptr;
    ListNode dummy(0, head);
    ListNode *prev = &dummy;
    ListNode *curr = head;

    while (curr) {
      bool duplicate = false;
      // Check if current node has duplicates
      while (curr->next && curr->val == curr->next->val) {
        duplicate = true;
        ListNode *temp = curr->next;
        curr->next = temp->next;
        delete temp; // Optional: free memory
      }
      if (duplicate) {
        // Remove the current node as well
        ListNode *temp = curr;
        curr = curr->next;
        delete temp; // Optional: free memory
        prev->next = curr;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    return dummy.next;
  }
};
// @lc code=end
