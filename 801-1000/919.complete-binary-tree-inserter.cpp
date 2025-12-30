/*
 * @lc app=leetcode id=919 lang=cpp
 *
 * [919] Complete Binary Tree Inserter
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

#include <queue> // We need queue for BFS traversal.
using std::queue;

/*
    Brief Digested Understanding:
    ----
    The problem is about maintaining a "complete binary tree" (where every level
    is full except possibly the last, and nodes are as far left as possible)
    as we repeatedly insert new nodes. The key requirement is that every
    insertion must preserve this "completeness" property, and for each
   insertion, we are to return the value of the parent node where the new node
   is attached.

    High-Level Summary:
    ----
    We approach this by using a queue to keep track of candidate parent nodes
    that do NOT have both left and right children filled, so we know at each
    insertion exactly where the next node belongs.
    - On initialization, we perform a level-order (BFS) traversal to fill
      this candidate queue.
    - For insertion, we always use the node at the front of the queue as the
      parent to attach the new node; if the parent becomes "full" (both
   children), we pop it out and the next insertion uses the next candidate.
    - get_root() always returns the original root pointer.
    - Time Complexity: Initial construction is O(N), where N is the number of
   nodes, since we need to traverse the tree once. Each insert/get_root is O(1).
    - Space Complexity: O(N) for the queue and references.

    The solution is structured to utilize helper functions for clarity and
   modularity.
*/

class CBTInserter {
private:
  // Store the root node pointer for get_root().
  TreeNode *_root;
  // Queue of parent candidates (those with at least one empty child slot).
  queue<TreeNode *> candidates;

  // Helper function: Populate the 'candidates' queue with all nodes
  // missing at least one child, using BFS traversal.
  void initializeCandidates(TreeNode *root) {
    queue<TreeNode *> q;
    if (root)
      q.push(root);
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      // If this node is not full, add it to candidates queue.
      if (!(node->left && node->right)) {
        candidates.push(node);
      }
      // Always push left and right if they exist, to traverse whole tree.
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    // After this, 'candidates' contains all nodes with at least one empty child
    // slot, in insert order.
  }

public:
  // Constructor: Takes the CBT root, initializes structure, and finds
  // candidates for future insertions.
  CBTInserter(TreeNode *root) : _root(root) {
    // Populate the candidates queue with all incomplete nodes in level order.
    initializeCandidates(root);
  }

  // Inserts a value as a new TreeNode, respecting completeness.
  // Returns the value of the parent node to which the new node was attached.
  int insert(int val) {
    // The parent will always be the first node in the candidate queue.
    TreeNode *parent = candidates.front();

    // Create the new node.
    TreeNode *newNode = new TreeNode(val);

    // Attach the new node to the appropriate child (first left, then right).
    if (!parent->left) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }

    // Add the new node to candidates, as it may receive children later.
    candidates.push(newNode);

    // If parent is now full (has both left & right), remove from candidates.
    if (parent->left && parent->right) {
      candidates.pop();
    }

    // Return the parent's value per problem requirement.
    return parent->val;
  }

  // Returns the root of the current tree.
  TreeNode *get_root() { return _root; }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
