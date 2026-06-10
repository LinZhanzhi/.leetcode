/*
On a 0-indexed 8 x 8 chessboard, there can be multiple black queens and one white king.

You are given a 2D integer array queens where queens[i] = [xQueeni, yQueeni] represents the position of the ith black queen on the chessboard. You are also given an integer array king of length 2 where king = [xKing, yKing] represents the position of the white king.

Return the coordinates of the black queens that can directly attack the king. You may return the answer in any order.



Example 1:


Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation: The diagram above shows the three queens that can directly attack the king and the three queens that cannot attack the king (i.e., marked with red dashes).
Example 2:


Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
Output: [[2,2],[3,4],[4,4]]
Explanation: The diagram above shows the three queens that can directly attack the king and the three queens that cannot attack the king (i.e., marked with red dashes).


Constraints:

1 <= queens.length < 64
queens[i].length == king.length == 2
0 <= xQueeni, yQueeni, xKing, yKing < 8
All the given positions are unique.
*/
class Solution
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        // a queen can attack the king if they are in the same row, column, or diagonal. We can check each of the 8 directions from the king's position and find the first queen in each direction that can attack the king.
        vector<vector<int>> ans;
        vector<vector<int>> board(8, vector<int>(8, 0));
        for (auto &q : queens)
            board[q[0]][q[1]] = 1;
        int x = king[0], y = king[1];
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                int x1 = x + i, y1 = y + j;
                while (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8)
                {
                    if (board[x1][y1] == 1)
                    {
                        ans.push_back({x1, y1});
                        break;
                    }
                    x1 += i;
                    y1 += j;
                }
            }
        }
        return ans;
    }
};