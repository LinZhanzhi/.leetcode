/*
On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].

Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.



We may make the following moves:

'U' moves our position up one row, if the position exists on the board;
'D' moves our position down one row, if the position exists on the board;
'L' moves our position left one column, if the position exists on the board;
'R' moves our position right one column, if the position exists on the board;
'!' adds the character board[r][c] at our current position (r, c) to the answer.
(Here, the only positions that exist on the board are positions with letters on them.)

Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.



Example 1:

Input: target = "leet"
Output: "DDR!UURRR!!DDD!"
Example 2:

Input: target = "code"
Output: "RR!DDRR!UUL!R!"


Constraints:

1 <= target.length <= 100
target consists only of English lowercase letters.
*/
class Solution
{
public:
    string alphabetBoardPath(string target)
    {
        string ans;
        int r = 0, c = 0; // start at (0, 0)
        for (char ch : target)
        {
            int targetR = (ch - 'a') / 5; // target row
            int targetC = (ch - 'a') % 5; // target column

            // keep moving until we reach the target row and column
            while (r != targetR || c != targetC)
            {
                while (r > targetR && r > 0)
                {
                    ans += 'U';
                    r--;
                }
                while (r < targetR && ((r + 1 == 5 && c == 0) || (r + 1 < 5)))
                {
                    ans += 'D';
                    r++;
                }

                // Move horizontally
                while (c > targetC && c > 0)
                {
                    ans += 'L';
                    c--;
                }
                while (c < targetC && r != 5)
                {
                    ans += 'R';
                    c++;
                }
            }

            ans += '!'; // add the character at the current position
        }
        return ans;
    }
};