/*
 * Brief Digested Understanding:
 * The problem asks us to count the number of land cells (1s) that are completely enclosed by water (0s) and cannot reach the boundary of the grid. In other words, we need to find land masses that are isolated from the edge of the grid.
 *
 * High-Level Summary:
 * We can solve this by identifying all land cells that *can* reach the boundary and marking them as "safe" (or turning them into water).
 * 1. Iterate through all cells on the four borders of the grid.
 * 2. If a border cell is land (1), perform a traversal (DFS) to visit all connected land cells.
 * 3. During the traversal, mark visited land cells as 0 (effectively sinking them) because they are not enclaves.
 * 4. After processing all boundaries, any 1s remaining in the grid are true enclaves. Iterate through the grid to count them.
 *
 * Time Complexity: O(m * n), where m is rows and n is cols. We visit each cell at most a constant number of times.
 * Space Complexity: O(m * n) for the recursion stack in the worst case (if the entire grid is land).
 */
#include <vector>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Traverse the boundaries.
        // If we find a land cell ('1') on the boundary, it means this land
        // and all connected land cells can "walk off" the boundary.
        // We start a DFS from these cells to "sink" them (turn them to 0).

        // Check first and last row
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) dfs(grid, i, 0, m, n);
            if (grid[i][n - 1] == 1) dfs(grid, i, n - 1, m, n);
        }

        // Check first and last column
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) dfs(grid, 0, j, m, n);
            if (grid[m - 1][j] == 1) dfs(grid, m - 1, j, m, n);
        }

        // Step 2: Count the remaining land cells.
        // Since we've removed all land connected to the boundary,
        // any '1' left is an enclave.
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    // Depth First Search to visit and mark connected land cells.
    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        // Base cases for recursion:
        // 1. Out of bounds
        // 2. Current cell is water (0) - already visited or originally water
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return;
        }

        // Mark the current cell as visited by turning it into water (0).
        // This prevents revisiting and effectively removes it from the count of enclaves.
        grid[r][c] = 0;

        // Recursively visit all 4 adjacent neighbors (up, down, left, right)
        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c + 1, m, n);
        dfs(grid, r, c - 1, m, n);
    }
};