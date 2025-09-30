/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// Brief, Digested Understanding:
// ----
// The problem asks us to convert a 2D grid of 0s and 1s into a Quad-Tree data
// structure. A Quad-Tree recursively divides the grid into four equal quadrants
// until each region contains only 0s or only 1s. Each node in the tree
// represents a region: if the region is uniform (all 0s or all 1s), it's a leaf
// node; otherwise, it's an internal node with four children for its four
// subregions.

// High-Level Summary:
// ----
// The solution uses recursion to build the Quad-Tree. For any subgrid, we check
// if all its values are the same (uniform).
// - If so, we create a leaf node with the value (0 or 1).
// - If not, we split the grid into four equal quadrants and recursively build
// the tree for each quadrant. The recursion continues until all regions are
// uniform. The time complexity is O(n^2 log n) in the worst case (where n is
// the grid size), since each level divides the grid into four, and each cell is
// checked at most log n times. The space complexity is O(n^2) for the tree
// nodes in the worst case.

// @lc code=start
#include <vector> // Include vector for using std::vector
using std::vector;

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
  // The main function to construct the Quad-Tree from the grid.
  Node *construct(vector<vector<int>> &grid) {
    int n = grid.size(); // Get the size of the grid (n x n)
    // Start the recursive construction from the top-left corner (0,0) and size
    // n
    return build(grid, 0, 0, n);
  }

private:
  // Helper function to recursively build the Quad-Tree.
  // (x, y) is the top-left corner of the current subgrid, and 'len' is its
  // size.
  Node *build(const vector<vector<int>> &grid, int x, int y, int len) {
    // First, check if all values in the current subgrid are the same (uniform).
    bool isUniform = true;
    int firstVal = grid[x][y]; // The value to compare against
    for (int i = x; i < x + len; ++i) {
      for (int j = y; j < y + len; ++j) {
        if (grid[i][j] != firstVal) {
          isUniform = false;
          break; // No need to check further if a different value is found
        }
      }
      if (!isUniform)
        break;
    }

    // If the region is uniform, create a leaf node.
    if (isUniform) {
      // The 'val' field is set to true if the value is 1, false if 0.
      // 'isLeaf' is true because this node represents a uniform region.
      return new Node(firstVal == 1, true);
    }

    // If not uniform, split the region into four quadrants and recurse.
    int half = len / 2; // Each quadrant will be of size half x half

    // Recursively build each of the four children:
    // topLeft: (x, y)
    Node *topLeft = build(grid, x, y, half);
    // topRight: (x, y + half)
    Node *topRight = build(grid, x, y + half, half);
    // bottomLeft: (x + half, y)
    Node *bottomLeft = build(grid, x + half, y, half);
    // bottomRight: (x + half, y + half)
    Node *bottomRight = build(grid, x + half, y + half, half);

    // Create an internal node with these four children.
    // The 'val' field can be set arbitrarily (commonly set to true/false).
    // 'isLeaf' is false because this node has children.
    return new Node(
        true, // The value can be either true or false for internal nodes.
        false, topLeft, topRight, bottomLeft, bottomRight);
  }
};
// @lc code=end
