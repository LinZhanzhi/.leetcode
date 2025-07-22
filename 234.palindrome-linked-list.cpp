/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  bool isPalindrome(ListNode *head) {
    if (!head || !head->next)
      return true;
    // Find the middle (slow will point to middle)
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // Reverse the second half
    ListNode *prev = nullptr;
    ListNode *curr = slow;
    while (curr) {
      ListNode *nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    // Compare first and second half
    ListNode *first = head;
    ListNode *second = prev;
    while (second) {
      if (first->val != second->val)
        return false;
      first = first->next;
      second = second->next;
    }
    return true;
  }
};
// @lc code=end
