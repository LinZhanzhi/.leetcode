/*
 * @lc app=leetcode id=558 lang=cpp
 *
 * [558] Logical OR of Two Binary Grids Represented as Quad-Trees
 */

// Brief, Digested Understanding:
// ----
// We are given two quad-trees, each representing a square binary matrix (with
// only 0s and 1s). Our task is to compute a new quad-tree that represents the
// logical OR of the two matrices. The quad-tree is a tree where each node
// represents a region of the matrix, and leaf nodes represent uniform regions
// (all 0s or all 1s). Internal nodes have four children for the four quadrants.
// The result quad-tree should be as compact as possible (merge children into a
// leaf if possible).

// High-Level Summary:
// ----
// The solution recursively merges the two input quad-trees. If either node is a
// leaf, we can determine the result for that region directly: if either is a
// leaf with value 1, the result is a leaf 1; if both are leaves with value 0,
// the result is a leaf 0; otherwise, we recursively merge the children. After
// merging, if all four children of a node are leaves with the same value, we
// merge them into a single leaf. The algorithm is recursive, and at each step,
// we check for possible simplification. Time complexity is O(N), where N is the
// number of nodes in the larger tree, since each node is visited once. Space
// complexity is O(H), where H is the height of the tree, due to recursion
// stack.

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
  // Helper function to merge two quad-trees using logical OR
  Node *intersect(Node *quadTree1, Node *quadTree2) {
    // If either node is null, treat as all 0s (should not happen in valid
    // input)
    if (!quadTree1)
      return cloneTree(quadTree2);
    if (!quadTree2)
      return cloneTree(quadTree1);

    // If either node is a leaf
    if (quadTree1->isLeaf) {
      // If quadTree1 is a leaf with value 1, the OR is always 1 for this region
      if (quadTree1->val) {
        return new Node(true, true);
      } else {
        // If quadTree1 is a leaf with value 0, the result is whatever quadTree2
        // is
        return cloneTree(quadTree2);
      }
    }
    if (quadTree2->isLeaf) {
      // If quadTree2 is a leaf with value 1, the OR is always 1 for this region
      if (quadTree2->val) {
        return new Node(true, true);
      } else {
        // If quadTree2 is a leaf with value 0, the result is whatever quadTree1
        // is
        return cloneTree(quadTree1);
      }
    }

    // Both nodes are not leaves, so recursively merge their children
    Node *topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
    Node *topRight = intersect(quadTree1->topRight, quadTree2->topRight);
    Node *bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
    Node *bottomRight =
        intersect(quadTree1->bottomRight, quadTree2->bottomRight);

    // If all four children are leaves and have the same value, merge them into
    // a single leaf
    if (isAllLeavesWithSameValue(topLeft, topRight, bottomLeft, bottomRight)) {
      bool mergedVal = topLeft->val;
      // Clean up the child nodes to avoid memory leaks
      delete topLeft;
      delete topRight;
      delete bottomLeft;
      delete bottomRight;
      return new Node(mergedVal, true);
    } else {
      // Otherwise, create an internal node with these four children
      return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
  }

private:
  // Helper function to check if all four nodes are leaves with the same value
  bool isAllLeavesWithSameValue(Node *a, Node *b, Node *c, Node *d) {
    // All must be leaves and have the same value
    return a->isLeaf && b->isLeaf && c->isLeaf && d->isLeaf &&
           a->val == b->val && b->val == c->val && c->val == d->val;
  }

  // Helper function to clone a tree (deep copy)
  Node *cloneTree(Node *node) {
    if (!node)
      return nullptr;
    if (node->isLeaf) {
      // Leaf node: just copy value and isLeaf
      return new Node(node->val, true);
    }
    // Internal node: recursively clone children
    return new Node(false, // value can be anything for internal node
                    false, cloneTree(node->topLeft), cloneTree(node->topRight),
                    cloneTree(node->bottomLeft), cloneTree(node->bottomRight));
  }
};
// @lc code=end
