/*
You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.



Example 1:


Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
Example 2:


Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6
*/
class Solution
{
public:
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x == m - 1 && y == n - 1)
                return true;
            for (auto &[dx, dy] : getNext(grid[x][y]))
            {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                    continue;
                if (isConnected(grid[x][y], grid[nx][ny], dx, dy))
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

private:
    vector<pair<int, int>> getNext(int street)
    {
        switch (street)
        {
        case 1:
            return {{0, -1}, {0, 1}};
        case 2:
            return {{-1, 0}, {1, 0}};
        case 3:
            return {{0, -1}, {1, 0}};
        case 4:
            return {{0, 1}, {1, 0}};
        case 5:
            return {{0, -1}, {-1, 0}};
        case 6:
            return {{0, 1}, {-1, 0}};
        default:
            return {};
        }
    }

    bool isConnected(int street1, int street2, int dx, int dy)
    {
        if (dx == 0 && dy == -1)
            return street2 == 1 || street2 == 4 || street2 == 6;
        if (dx == 0 && dy == 1)
            return street2 == 1 || street2 == 3 || street2 == 5;
        if (dx == -1 && dy == 0)
            return street2 == 2 || street2 == 3 || street2 == 4;
        if (dx == 1 && dy == 0)
            return street2 == 2 || street2 == 5 || street2 == 6;
        return false;
    }
};