/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head)
      return nullptr;

    // Helper function to find the middle node and its previous node
    auto findMiddle = [](ListNode *head) -> std::pair<ListNode *, ListNode *> {
      ListNode *prev = nullptr;
      ListNode *slow = head;
      ListNode *fast = head;
      while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      return {prev, slow};
    };

    // Recursive function to build BST
    std::function<TreeNode *(ListNode *)> buildBST =
        [&](ListNode *head) -> TreeNode * {
      if (!head)
        return nullptr;
      if (!head->next)
        return new TreeNode(head->val);

      auto [prev, mid] = findMiddle(head);
      if (prev)
        prev->next = nullptr; // Split the list

      TreeNode *root = new TreeNode(mid->val);
      root->left = buildBST((prev ? head : nullptr));
      root->right = buildBST(mid->next);
      return root;
    };

    return buildBST(head);
  }
};
// @lc code=end
