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
 * Brief Digested Understanding:
 * The problem asks us to process a linked list and, for each node, find the value of the *next* node in the sequence that is strictly larger than the current node. If no such larger node exists later in the list, the result for that node is 0. We need to return these "next greater values" as an array (vector) corresponding to the original list order.
 *
 * High-Level Summary:
 * To solve this efficiently, we first convert the linked list into a standard array (vector) to allow random access and easier indexing. Then, we use the "Monotonic Stack" pattern. We iterate through the values, maintaining a stack of *indices* representing nodes for which we haven't yet found a "next greater" value. The stack will always store indices whose corresponding values are in decreasing order. When we encounter a current value larger than the value at the stack's top index, it means we've found the "next greater" element for that index. We pop the index, record the current value as the answer, and repeat until the stack property is restored. This approach ensures we process each element at most twice (push and pop), resulting in O(N) time complexity.
 */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // Step 1: Convert the linked list to a vector for easier access.
        // This allows us to work with indices and random access, which is
        // difficult with a raw linked list.
        vector<int> values;
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        // Step 2: Initialize the answer vector with 0s.
        // If we don't find a next greater element for a node, it remains 0.
        int n = values.size();
        vector<int> answer(n, 0);

        // Step 3: Use a Monotonic Stack to find the next greater element.
        // The stack will store 'indices' of the elements in the 'values' array.
        // We maintain the invariant that values corresponding to indices in the stack
        // are strictly decreasing.
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            // While the stack is not empty and the current value is greater
            // than the value associated with the index at the top of the stack:
            // We have found the "next greater node" for the element at st.top().
            while (!st.empty() && values[st.top()] < values[i]) {
                int index = st.top();
                st.pop();
                // Update the answer for that index with the current value.
                answer[index] = values[i];
            }

            // Push the current index onto the stack to find its next greater element later.
            st.push(i);
        }

        return answer;
    }
};