/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

// Brief, Digested Understanding:
//
// The goal is to rearrange a singly linked list so that all nodes at odd
// indices (1st, 3rd, 5th, etc.) come first, followed by all nodes at even
// indices (2nd, 4th, 6th, etc.), while preserving the original relative order
// within both the odd and even groups. The first node is considered odd, the
// second is even, and so on. The rearrangement must be done in-place (O(1)
// extra space).
//
// For example, given [1,2,3,4,5], the output should be [1,3,5,2,4].
//
// High-Level Summary:
//
// The solution uses two pointers to separate the list into two sublists: one
// for odd-indexed nodes and one for even-indexed nodes. We iterate through the
// list, alternating the next pointers to build the odd and even lists in-place.
// At the end, we connect the last node of the odd list to the head of the even
// list. This approach ensures O(n) time complexity (one pass through the list)
// and O(1) space complexity (no extra data structures, just pointers).
//
// Time Complexity: O(n), where n is the number of nodes in the list.
// Space Complexity: O(1), as only a few pointers are used regardless of input
// size.

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
  ListNode *oddEvenList(ListNode *head) {
    // Edge case: If the list is empty or has only one node, return as is.
    if (!head || !head->next) {
      return head;
    }

    // Initialize pointers:
    // - odd points to the first node (odd index)
    // - even points to the second node (even index)
    // - evenHead stores the start of the even-indexed list for later
    // reconnection
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;

    // Traverse the list, rearranging next pointers to separate odd and even
    // nodes
    while (even && even->next) {
      // Link the current odd node to the next odd node (skipping the even node)
      odd->next = even->next;
      odd = odd->next; // Move odd pointer forward

      // Link the current even node to the next even node (skipping the odd
      // node)
      even->next = odd->next;
      even = even->next; // Move even pointer forward
    }

    // After the loop, odd points to the last node in the odd list.
    // Connect the end of the odd list to the head of the even list.
    odd->next = evenHead;

    // Return the head of the rearranged list.
    return head;
  }
};
// @lc code=end
