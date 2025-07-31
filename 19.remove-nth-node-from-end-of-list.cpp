/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // INSERT_YOUR_CODE
    ListNode dummy(0, head);
    ListNode *fast = &dummy;
    ListNode *slow = &dummy;
    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; ++i) {
      fast = fast->next;
    }
    // now fast is pointing at (n+1)th node from the beginning, 1 indexed
    // Move both pointers until fast reaches the end
    // say the list length is len
    // this loop will run (len+1) - (n+1) = len - n times
    // when this loop ends, slow will be pointing at the (len-n)th node from the
    // beginning, 1 indexed next of slow is the node to be deleted
    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    // Remove the nth node from end
    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return dummy.next;
  }
};
// @lc code=end
