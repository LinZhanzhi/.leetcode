/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        // No need to explicitly delete nodes if the problem does not require it,
        // as LeetCode handles memory cleanup after the function returns.
        // This avoids unnecessary memory operations and can improve memory usage.
        ListNode* current = head;
        while (current && current->next) {
            if (current->val == current->next->val) {
                // Just skip the duplicate node, let LeetCode handle memory
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
// @lc code=end

