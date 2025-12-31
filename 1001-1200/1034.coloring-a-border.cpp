/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given a grid of colored squares and a starting square (row, col).
 * We need to identify the "connected component" of this starting square. A connected component consists of all adjacent squares (up, down, left, right) that have the same color as the starting square.
 * Within this component, we need to find the "border" squares.
 * A square is on the border if:
 *   1. It is on the edge of the grid.
 *   2. OR it is adjacent to a square that is NOT part of the component (i.e., has a different color).
 * Finally, we color ONLY these border squares with the new `color`.
 *
 * High-Level Summary:
 * -------------------
 * 1. **Traversal**: We use Depth First Search (DFS) (or BFS) to traverse the connected component starting from (row, col).
 * 2. **Visited Tracking**: We use a `visited` matrix to keep track of processed cells to avoid infinite loops and redundant processing.
 * 3. **Border Identification**: During the traversal, for each cell in the component, we check its 4 neighbors.
 *    - If a neighbor is out of bounds or has a different color, the current cell is a border cell.
 * 4. **Deferred Coloring**: We cannot color the cells immediately while traversing because changing a cell's color might affect the logic for its neighbors (we need to know the original color to determine connectivity).
 *    - Instead, we store the coordinates of all identified border cells in a list.
 *    - After the traversal is complete, we iterate through the list and update the grid with the new color.
 *
 * Time Complexity: O(m * n), where m is rows and n is columns. In the worst case, we visit every cell in the grid.
 * Space Complexity: O(m * n) for the `visited` array and the recursion stack (or queue).
 */

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        int originalColor = grid[row][col];

        // If the new color is the same as the original, no changes are needed visually,
        // but the logic would still result in the same grid. We can return early for optimization.
        if (originalColor == color) return grid;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> borders;

        dfs(grid, row, col, originalColor, visited, borders);

        // Apply the new color to the identified border cells.
        for (auto& p : borders) {
            grid[p.first][p.second] = color;
        }

        return grid;
    }

private:
    void dfs(vector<vector<int>>& grid, int r, int c, int originalColor, vector<vector<bool>>& visited, vector<pair<int, int>>& borders) {
        visited[r][c] = true;
        int m = grid.size();
        int n = grid[0].size();

        bool isBorder = false;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check if neighbor is out of bounds
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                isBorder = true;
            } else {
                // Check if neighbor is a different color
                if (grid[nr][nc] != originalColor) {
                    isBorder = true;
                } else if (!visited[nr][nc]) {
                    // Neighbor is same color and not visited, continue traversal
                    dfs(grid, nr, nc, originalColor, visited, borders);
                }
            }
        }

        if (isBorder) {
            borders.push_back({r, c});
        }
    }
};