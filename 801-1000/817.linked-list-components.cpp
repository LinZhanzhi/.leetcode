/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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

#include <unordered_set> // To use std::unordered_set for efficient look-up
#include <vector>        // To use std::vector for the 'nums' parameter

using std::unordered_set;
using std::vector;

/**
 * Brief Digested Understanding:
 * ----
 * The problem asks us to count how many "connected groups" (components) of
 * integer values from the array 'nums' are found in the given linked list.
 * Two values are considered connected if they appear one after another in
 * the linked list, and both belong to 'nums'. Each such group is treated as
 * a single connected component; solo, isolated elements from 'nums' that
 * are not adjacent to any other 'nums' value also form a component.
 *
 * High-Level Summary:
 * ----
 * The main idea is to traverse the linked list and use a hash set for fast
 * lookups: for each node, check if its value is in the set of values from
 * 'nums'. When we encounter a node whose value is in 'nums' and either the
 * next node is NULL or not in 'nums', we've found the end of a component
 * and can increment our count. This algorithm works in O(n) time and O(n)
 * space, where n is the number of list nodes or the size of 'nums'. The key
 * tools are a hash set for fast membership testing and a single traversal
 * of the list, with helper functions used to maintain clarity and
 * modularity.
 */

// Helper function to convert nums array to hash set for O(1) lookups.
// This function takes the array of integers and returns an unordered_set
// containing the same integers for quick membership checks.
unordered_set<int> makeSet(const vector<int> &nums) {
  unordered_set<int> numSet;
  for (int num : nums) {
    numSet.insert(num); // Insert each value from nums into the set
  }
  return numSet;
}

// Helper function that counts the number of connected components in the linked
// list. A component consists of consecutive nodes in which all node values
// belong to numSet.
int countComponents(ListNode *head, const unordered_set<int> &numSet) {
  int components = 0;          // To count the number of components found
  ListNode *current = head;    // Start traversing from the head
  while (current != nullptr) { // Continue until the end of the linked list
    // Is current node's value in nums set?
    if (numSet.count(current->val)) {
      // If this is the end of a component:
      // - If next is null OR
      // - Next value is NOT in nums set,
      // then we've reached the end of this component.
      if (current->next == nullptr || !numSet.count(current->next->val)) {
        components++; // Increment the component count
      }
    }
    // Move to the next node in the linked list
    current = current->next;
  }
  return components;
}

class Solution {
public:
  int numComponents(ListNode *head, vector<int> &nums) {
    // First, build a set from nums for quick value lookups (O(1) per check)
    unordered_set<int> numSet = makeSet(nums);
    // Then, count the number of connected components in the list
    return countComponents(head, numSet);
  }
};
// @lc code=end
