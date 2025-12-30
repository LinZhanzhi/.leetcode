/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start
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
  void recoverTree(TreeNode *root) {
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;
    TreeNode *curr = root;

    while (curr) {
      // Morris traversal
      if (!curr->left) {
        // Visit node
        if (prev && prev->val > curr->val) {
          if (!first)
            first = prev;
          second = curr;
        }
        prev = curr;
        curr = curr->right;
      } else {
        // Find the inorder predecessor of curr
        TreeNode *pred = curr->left;
        while (pred->right && pred->right != curr) {
          pred = pred->right;
        }
        if (!pred->right) {
          // Make curr the right child of its inorder predecessor
          pred->right = curr;
          curr = curr->left;
        } else {
          // Revert the changes
          pred->right = nullptr;
          if (prev && prev->val > curr->val) {
            if (!first)
              first = prev;
            second = curr;
          }
          prev = curr;
          curr = curr->right;
        }
      }
    }
    if (first && second) {
      std::swap(first->val, second->val);
    }
  }
  //   void recoverTree(TreeNode *root) {
  //     // O(n) space solution: inorder traversal, collect nodes, find the two
  //     swapped, swap them vector<TreeNode*> nodes; function<void(TreeNode*)>
  //     inorder = [&](TreeNode* node) {
  //       if (!node) return;
  //       inorder(node->left);
  //       nodes.push_back(node);
  //       inorder(node->right);
  //     };
  //     inorder(root);
  //     TreeNode *first = nullptr, *second = nullptr;
  //     for (int i = 0; i + 1 < nodes.size(); ++i) {
  //       if (nodes[i]->val > nodes[i+1]->val) {
  //         if (!first) {
  //           first = nodes[i];
  //           second = nodes[i+1];
  //         } else {
  //           second = nodes[i+1];
  //           break;
  //         }
  //       }
  //     }
  //     if (first && second) {
  //       swap(first->val, second->val);
  //     }
  //   }
};
// @lc code=end
