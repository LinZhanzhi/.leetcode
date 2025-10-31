/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */

// Brief Digested Understanding:
// ----
// Each cell in the given n x n grid contains either a '/', a '\', or a blank
// space. These slashes can "cut" or divide the square into smaller regions, and
// the whole n x n grid can have several connected regions that are separated by
// these slashes. The core challenge is to correctly count the number of such
// regions in the grid, taking into account how slashes break up the space,
// sometimes creating corners, isolated islands, or rings. It's less about
// drawing, more about connectivity, and each grid square may be split up
// internally into smaller cells, depending on where the slash is placed.

// High-Level Summary:
// ----
// We solve this problem by treating each 1x1 cell as being sub-divided into 4
// mini-triangles (one for each side). The reason is that a single slash inside
// a square can split that square into two separate regions, so dividing the
// square gives us a way to represent all possible splits and connections. We'll
// create a union-find (Disjoint Set Union / DSU) data structure to model which
// triangles are connected parts of the same region, based on the slashes in the
// grid. For each cell's triangles, we union them as needed (depending on if the
// cell contains a slash, backslash, or nothing), and also union triangles from
// adjacent cells. In the end, we'll count how many unique root parents there
// are in the DSU, which represents distinct regions in the grid. This approach
// is efficient for n up to 30 (since there will be at most n*n*4 parts), and
// both the time and space complexity are O(n^2) with almost constant-time
// union/find.

// Necessary includes for vectors and string
#include <string>
#include <vector>

using std::string;
using std::vector;

// Union-Find (Disjoint Set Union) implementation
class DSU {
private:
  vector<int> parent;

public:
  // Construct DSU to handle 'n' items labeled 0...n-1
  DSU(int n) {
    parent.resize(n);
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }
  // Find operation (with path compression)
  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }
  // Union operation (joins the sets containing x and y)
  void unite(int x, int y) { parent[find(x)] = find(y); }
  // Count unique sets (returns the number of components)
  int countRoots() {
    int n = parent.size();
    int count = 0;
    for (int i = 0; i < n; ++i)
      if (parent[i] == i)
        ++count;
    return count;
  }
};

class Solution {
public:
  // Main function that receives an n x n grid of slashes and blank spaces
  int regionsBySlashes(vector<string> &grid) {
    int n = grid.size();
    // Each cell is divided into 4 triangles:
    //   0 - top,  1 - right,  2 - bottom,  3 - left
    // To uniquely identify each triangle, we assign an index for each
    // mini-triangle in the DSU: (row * n + col) * 4 + k   where k = [0,3]
    DSU dsu(n * n * 4);

    // For every cell in the grid
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        int idx = (row * n + col) * 4;
        char c = grid[row][col];
        // Internal union of triangles in this cell
        if (c == ' ') {
          // Empty square: all four triangles are part of the same region
          dsu.unite(idx + 0, idx + 1);
          dsu.unite(idx + 1, idx + 2);
          dsu.unite(idx + 2, idx + 3);
        } else if (c == '/') {
          // Slash: 0-3 and 1-2 are connected (separate regions)
          dsu.unite(idx + 0, idx + 3);
          dsu.unite(idx + 1, idx + 2);
        } else if (c == '\\') {
          // Backslash: 0-1 and 2-3 are connected (different split)
          dsu.unite(idx + 0, idx + 1);
          dsu.unite(idx + 2, idx + 3);
        }
        // Across neighboring cells, connect triangles
        // Connect bottom triangle of current cell to top triangle of cell below
        if (row + 1 < n) {
          int neighbor = ((row + 1) * n + col) * 4;
          dsu.unite(idx + 2, neighbor + 0);
        }
        // Connect right triangle of current cell to left triangle of cell to
        // the right
        if (col + 1 < n) {
          int neighbor = (row * n + (col + 1)) * 4;
          dsu.unite(idx + 1, neighbor + 3);
        }
      }
    }
    // The number of regions is the count of unique root triangles
    return dsu.countRoots();
  }
};
// @lc code=end
