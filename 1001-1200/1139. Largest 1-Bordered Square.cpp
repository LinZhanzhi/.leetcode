/*
Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.



Example 1:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:

Input: grid = [[1,1,0,0]]
Output: 1


Constraints:

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1
*/
class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> right(m, vector<int>(n, 0)); // right[i][j] represents the number of consecutive 1s to the right of (i, j) including (i, j)
        vector<vector<int>> down(m, vector<int>(n, 0));  // down[i][j] represents the number of consecutive 1s downward from (i, j) including (i, j)

        // fill the right and down arrays
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                {
                    right[i][j] = (j + 1 < n) ? right[i][j + 1] + 1 : 1;
                    down[i][j] = (i + 1 < m) ? down[i + 1][j] + 1 : 1;
                }
            }
        }

        int maxSide = 0;
        // iterate through each cell to find the largest 1-bordered square
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int small = min(right[i][j], down[i][j]);
                while (small > maxSide)
                {
                    if (down[i][j + small - 1] >= small && right[i + small - 1][j] >= small)
                    {
                        maxSide = small;
                        break; // we found a larger square, no need to check smaller squares
                    }
                    small--;
                }
            }
        }

        return maxSide * maxSide; // return the area of the largest 1-bordered square
    }
};