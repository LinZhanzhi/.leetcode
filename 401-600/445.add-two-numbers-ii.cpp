/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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

/*
 * Brief, Digested Understanding:
 * ----
 * We are given two singly-linked lists, each representing a non-negative
 * integer, where each node contains a single digit and the most significant
 * digit comes first (at the head). Our task is to add these two numbers and
 * return the sum as a new linked list, also with the most significant digit
 * first. We must handle the addition digit by digit, taking care of carries,
 * and we are not allowed to reverse the input lists.
 *
 * High-Level Summary:
 * ----
 * The main challenge is that the most significant digit is at the head, so we
 * cannot simply add from the tail as we do with normal addition. To solve this,
 * we use two stacks to store the digits of each list, so that we can pop from
 * the stacks and add from least significant to most significant digit (i.e.,
 * from the end of the lists). We then build the result list by prepending new
 * nodes for each digit of the sum. This approach avoids reversing the input
 * lists and efficiently handles carries.
 *
 * Time Complexity: O(N + M), where N and M are the lengths of the two lists.
 * Space Complexity: O(N + M), due to the use of stacks to store the digits.
 */

#include <stack> // Include stack for storing digits of the lists

class Solution {
public:
  // Helper function to push all digits of a linked list onto a stack
  void pushListToStack(ListNode *head, std::stack<int> &s) {
    // Traverse the list and push each value onto the stack
    while (head) {
      s.push(head->val);
      head = head->next;
    }
  }

  // Main function to add two numbers represented by linked lists
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    std::stack<int> s1, s2; // Stacks to hold the digits of l1 and l2

    // Push all digits of l1 and l2 onto their respective stacks
    pushListToStack(l1, s1);
    pushListToStack(l2, s2);

    int carry = 0;              // Variable to store carry-over during addition
    ListNode *result = nullptr; // Head of the resulting linked list

    // Continue adding while there are digits left in either stack or a carry
    // remains
    while (!s1.empty() || !s2.empty() || carry) {
      int sum = carry; // Start with the carry from the previous addition

      // If there are digits left in s1, add the top digit to sum
      if (!s1.empty()) {
        sum += s1.top();
        s1.pop();
      }

      // If there are digits left in s2, add the top digit to sum
      if (!s2.empty()) {
        sum += s2.top();
        s2.pop();
      }

      // The new digit is sum % 10, and the new carry is sum / 10
      int digit = sum % 10;
      carry = sum / 10;

      // Prepend the new digit to the result list
      ListNode *newNode = new ListNode(digit);
      newNode->next = result;
      result = newNode;
    }

    // Return the head of the resulting linked list
    return result;
  }
};
// @lc code=end
