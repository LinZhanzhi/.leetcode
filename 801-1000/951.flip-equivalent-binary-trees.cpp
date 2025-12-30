/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
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

/**
 * Brief Digested Understanding:
 * ----
 * The heart of this problem is determining if two binary trees can be made
 * identical by repeatedly flipping any number of their nodes (flip: swap that
 * node's left and right children). The problem does not care *which* nodes you
 * flip or how often; only whether such a sequence can make both trees look
 * exactly the same. This means that at each equivalent node in both trees, we
 * have a choice:
 *   - Either their children (left & right) are already in the same positions,
 * or
 *   - they are in the opposite positions, and we can flip one node to line them
 * up. The challenge is to check this recursively for all nodes in both trees,
 * handling all necessary flips.
 *
 * Key constraint: Node values are unique, and there may be empty subtrees.
 *
 * High-Level Summary:
 * ----
 * To solve this, we recursively compare the two trees starting from the roots:
 *   - If both nodes are null, they're trivially equivalent.
 *   - If one is null and the other isn't, they're not equivalent.
 *   - If their values differ, they're not equivalent.
 * Otherwise, we must check if their subtrees are flip equivalent by examining
 * both possible alignments:
 *   (a) Their left children match AND their right children match (no flip), OR
 *   (b) Their left child matches the other's right child and vice versa (flip).
 * This recursive check continues for all pairs of subtrees.
 *
 * We'll modularize with a helper function for recursion. Time complexity is
 * O(N), since you must potentially visit every node in both trees once; space
 * complexity O(H) for the call stack, where H is the height of the tree.
 */

// Bring std::nullptr_t into scope if not using "using namespace std;", but the
// LeetCode judge does not require it.

// Helper function to encapsulate flip equivalence logic.
class Solution {
public:
  // Main function called by LeetCode infrastructure.
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    // Call helper function to determine flip equivalence.
    return isFlipEquivalent(root1, root2);
  }

private:
  /**
   * Helper function: Checks if two subtrees are flip equivalent.
   * @param n1 Pointer to current node in first tree.
   * @param n2 Pointer to current node in second tree.
   * @return true if subtrees are flip equivalent, false otherwise.
   */
  bool isFlipEquivalent(TreeNode *n1, TreeNode *n2) {
    // Base case: If both nodes are null, they're equivalent at this level.
    if (!n1 && !n2)
      return true;

    // If only one is null, or their values don't match, not equivalent.
    if (!n1 || !n2 || n1->val != n2->val)
      return false;

    // Check both configurations:
    // 1. No swap required: left with left, right with right.
    bool noFlip = isFlipEquivalent(n1->left, n2->left) &&
                  isFlipEquivalent(n1->right, n2->right);

    // 2. Swap required: left with right, right with left.
    bool flip = isFlipEquivalent(n1->left, n2->right) &&
                isFlipEquivalent(n1->right, n2->left);

    // Return true if either configuration works.
    return noFlip || flip;
  }
};
// @lc code=end
