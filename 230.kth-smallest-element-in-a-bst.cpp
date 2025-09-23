/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// Brief, Digested Understanding:
// ----
// The main goal is to find the kth smallest value in a binary search tree
// (BST). In a BST, an in-order traversal (left, root, right) visits nodes in
// ascending order. Thus, the kth node visited during in-order traversal is the
// kth smallest element. The follow-up asks how to optimize if the BST is
// frequently modified (insertions/deletions) and kth smallest queries are
// frequent.

// High-Level Summary:
// ----
// The classic solution does an in-order traversal, counting nodes until the kth
// is found. This approach takes O(H + k) time per query, where H is the tree
// height, because we must traverse down to the leftmost node and then count up
// to the kth node in in-order sequence. However, if the BST is modified
// frequently (with many insertions or deletions) and kth smallest queries are
// also frequent, this becomes inefficient because each query may require a full
// traversal and recounting from scratch, leading to repeated work and poor
// performance for large or unbalanced trees. To optimize, we augment each node
// with a "subtree size" field (number of nodes in its subtree). This allows us
// to find the kth smallest in O(H) time by comparing k to the size of the left
// subtree at each step, similar to binary search. When inserting or deleting,
// we update subtree sizes accordingly.
//
// This approach is called an "Order-Statistic Tree" (OST).
//
// Time Complexity: O(H) per query, O(H) per insert/delete (for updating sizes).
// Space Complexity: O(N) for storing the tree and size fields.

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

// The following is the original Order-Statistic Tree (OST) implementation,
// which is not used for the LeetCode interface, but kept for reference and
// educational purposes. The actual solution for LeetCode is implemented below.

/*
// Augmented TreeNode definition for Order-Statistic Tree (OST).
struct OSTreeNode {
  int val;           // Value of the node.
  OSTreeNode *left;  // Pointer to left child.
  OSTreeNode *right; // Pointer to right child.
  int size; // Number of nodes in the subtree rooted at this node (including
            // itself).

  OSTreeNode(int x) : val(x), left(nullptr), right(nullptr), size(1) {}
};

class KthSmallestBST {
public:
  OSTreeNode *root;

  KthSmallestBST() : root(nullptr) {}

  // Insert a value into the BST and update subtree sizes.
  OSTreeNode *insert(OSTreeNode *node, int val) {
    if (!node) {
      // If the current spot is empty, create a new node.
      return new OSTreeNode(val);
    }
    if (val < node->val) {
      // Insert into the left subtree.
      node->left = insert(node->left, val);
    } else {
      // Insert into the right subtree (duplicates go right).
      node->right = insert(node->right, val);
    }
    // After insertion, update the size of this node's subtree.
    node->size = 1 + getSize(node->left) + getSize(node->right);
    return node;
  }

  // Public insert function.
  void insert(int val) { root = insert(root, val); }

  // Delete a value from the BST and update subtree sizes.
  OSTreeNode *remove(OSTreeNode *node, int val) {
    if (!node)
      return nullptr;
    if (val < node->val) {
      node->left = remove(node->left, val);
    } else if (val > node->val) {
      node->right = remove(node->right, val);
    } else {
      // Node to delete found.
      if (!node->left) {
        OSTreeNode *rightChild = node->right;
        delete node;
        return rightChild;
      } else if (!node->right) {
        OSTreeNode *leftChild = node->left;
        delete node;
        return leftChild;
      } else {
        // Node with two children: find inorder successor.
        OSTreeNode *succ = node->right;
        while (succ->left)
          succ = succ->left;
        node->val = succ->val;
        node->right = remove(node->right, succ->val);
      }
    }
    // Update size after deletion.
    node->size = 1 + getSize(node->left) + getSize(node->right);
    return node;
  }

  // Public remove function.
  void remove(int val) { root = remove(root, val); }

  // Find the kth smallest element in the BST.
  int kthSmallest(int k) { return kthSmallest(root, k); }

private:
  // Helper to get the size of a subtree (handles nullptr).
  int getSize(OSTreeNode *node) { return node ? node->size : 0; }

  // Recursive function to find the kth smallest element.
  int kthSmallest(OSTreeNode *node, int k) {
    // node is never nullptr if k is valid.
    int leftSize = getSize(node->left);
    if (k <= leftSize) {
      // The kth smallest is in the left subtree.
      return kthSmallest(node->left, k);
    } else if (k == leftSize + 1) {
      // The current node is the kth smallest.
      return node->val;
    } else {
      // The kth smallest is in the right subtree.
      // Adjust k to skip left subtree and current node.
      return kthSmallest(node->right, k - leftSize - 1);
    }
  }
};
*/

// LeetCode expects a function that takes a TreeNode* root and int k.
// We'll implement the classic in-order traversal solution here.

class Solution {
public:
  // This function returns the kth smallest value in the BST rooted at 'root'.
  int kthSmallest(TreeNode *root, int k) {
    // Vector to store the in-order traversal result.
    std::vector<int> inorder;
    // Helper function to perform in-order traversal.
    inorderTraversal(root, inorder, k);
    // The kth smallest is at index k-1 (since k is 1-indexed).
    return inorder[k - 1];
  }

private:
  // Helper function for in-order traversal.
  // Traverses the tree in-order and appends node values to 'inorder'.
  // Stops early if we've collected k elements for efficiency.
  void inorderTraversal(TreeNode *node, std::vector<int> &inorder, int k) {
    if (!node)
      return;
    // Traverse left subtree.
    inorderTraversal(node->left, inorder, k);
    // Add current node's value.
    if (inorder.size() < k) {
      inorder.push_back(node->val);
    }
    // If we've already found k elements, stop traversing.
    if (inorder.size() >= k)
      return;
    // Traverse right subtree.
    inorderTraversal(node->right, inorder, k);
  }
};

/*
 * Example usage:
 * -----
 * // Given a BST root and integer k:
 * Solution sol;
 * int val = sol.kthSmallest(root, k); // Returns the kth smallest value in the
 * BST.
 *
 * Edge Cases:
 * -----
 * - If k is out of bounds (<= 0 or > total nodes), this will cause
 * out-of-bounds access. LeetCode guarantees 1 <= k <= n.
 * - The BST may be unbalanced.
 * - All node values are unique or may have duplicates (problem allows
 * duplicates).
 */

// @lc code=end
