/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We have a grid with fresh oranges (1), rotten oranges (2), and empty cells (0).
 * Rot spreads to adjacent fresh oranges every minute.
 * We need to find the time until all fresh oranges rot.
 * If some fresh oranges can never be reached, return -1.
 *
 * High-Level Summary:
 * -------------------
 * This is a classic Breadth-First Search (BFS) problem (Multi-source BFS).
 * 1. Initialize a queue with all initially rotten oranges (time = 0).
 * 2. Count the total number of fresh oranges.
 * 3. Perform BFS:
 *    - For each rotten orange at the current time step, infect its 4 neighbors.
 *    - If a neighbor is fresh, it becomes rotten, is added to the queue, and the fresh count decreases.
 *    - Increment time after processing each level (minute).
 * 4. If fresh count becomes 0, return the time.
 * 5. If the queue is empty and fresh count > 0, return -1 (impossible).
 *
 * Time Complexity: O(M * N) - Each cell is visited at most once.
 * Space Complexity: O(M * N) - Queue size in worst case.
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        // Step 1: Initialize queue and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If there are no fresh oranges initially, time is 0
        if (freshCount == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Step 2: BFS
        while (!q.empty()) {
            int size = q.size();
            bool rottedAny = false;

            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    // Check bounds and if fresh
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        // Rot the orange
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        freshCount--;
                        rottedAny = true;
                    }
                }
            }

            if (rottedAny) {
                minutes++;
            }
        }

        // Step 3: Check if any fresh oranges remain
        return freshCount == 0 ? minutes : -1;
    }
};
// @lc code=end
