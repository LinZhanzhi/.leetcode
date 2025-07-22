/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Handle edge cases
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        
        // Two-pointer technique
        // When one pointer reaches the end, switch to the other list's head
        // This ensures both pointers travel the same total distance
        while (ptrA != ptrB) {
            // Move ptrA to next node, or to headB if at end
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            
            // Move ptrB to next node, or to headA if at end
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }
        
        // ptrA and ptrB are now either at the intersection node or both null
        return ptrA;
    }
};
// @lc code=end

