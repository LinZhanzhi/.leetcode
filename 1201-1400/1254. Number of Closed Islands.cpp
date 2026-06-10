/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.



Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2


Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/
class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // only count closed island
                if (grid[i][j] == 0)
                {
                    res += dfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0; // if out of bound, it is not closed island
        if (grid[i][j] == 1)
            return 1; // if it is water, it is closed island
        grid[i][j] = 1;
        int up = dfs(grid, i - 1, j);
        int down = dfs(grid, i + 1, j);
        int left = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);
        return up & down & left & right;
    }
};