/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start

#include <queue>
#include <unordered_set>
#include <vector>

using std::queue;
using std::unordered_set;
using std::vector;

class Solution {
public:
  /*
   * Brief Digested Understanding:
   * ----
   * This problem simulates a game of Snakes and Ladders played on a square
   * board whose labeling zigzags ("boustrophedon" order) from the bottom-left.
   * Each move is a die roll (1-6), potentially redirected by a snake or ladder.
   * Your task is to compute the fewest die rolls needed to reach the top-right
   * square, starting from square 1. If impossible, return -1.
   *
   * The challenge lies in properly translating square numbers to (row, col)
   * positions on the board, and in handling "single-jump" snake/ladder moves as
   * specified.
   *
   * High-Level Summary:
   * ----
   * We'll model the board as a graph, where each square can reach up to 6
   * following squares via possible dice rolls. We'll use Breadth-First Search
   * (BFS) starting at square 1 to find the shortest path to the final square.
   * At each move, for all dice outcomes (1-6), we check the resulting square.
   * If it's a snake or ladder (i.e., board[r][c] != -1), we "jump" to its
   * destination; this jump happens at most once per move (per the rules).
   *
   * Special care is needed to map between square labels and their board (row,
   * col) coordinates, accounting for zigzag pattern. We'll keep a 'visited'
   * array to prevent revisiting squares and thus avoid infinite loops.
   *
   * Time complexity: O(n^2) — every square is visited at most once.
   * Space complexity: O(n^2) — for the queue and visited set.
   */

  // Helper function: Converts a board square number into (row, col) indices
  // for the current board's boustrophedon (zigzag) style numbering.
  void getCoordinates(int square, int n, int &row, int &col) {
    // Square numbers range from 1 to n^2.
    // Calculate zero-based index for the square
    int quot = (square - 1) / n;
    int rem = (square - 1) % n;
    // Since numbering starts at the bottom row, row index is reversed.
    row = n - 1 - quot;
    // If the row from the bottom is even (zigzag), numbering is left-to-right.
    // If odd, it's right-to-left.
    if (quot % 2 == 0) {
      // left-to-right
      col = rem;
    } else {
      // right-to-left
      col = n - 1 - rem;
    }
  }

  // Main function: Solves the Snakes and Ladders problem using BFS
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    int target = n * n; // The goal is to reach the last square.
    vector<bool> visited(target + 1, false); // 1-based index for squares

    // BFS queue: Each element is (current_square_number, move_count)
    queue<std::pair<int, int>> q;
    q.push({1, 0});    // Start at square 1 with 0 moves.
    visited[1] = true; // Mark to avoid cycles

    while (!q.empty()) {
      int curr = q.front().first;   // Current square we're on
      int moves = q.front().second; // Moves taken so far
      q.pop();

      if (curr == target) {
        // We've reached the target square. Return the move count.
        return moves;
      }

      // Explore all die rolls from 1 to 6 (simulate moving from curr+1 to
      // curr+6)
      for (int die = 1; die <= 6; ++die) {
        int next = curr + die;
        if (next > target)
          break; // Don't go past the last square

        // Determine (row, col) for cell 'next'
        int r, c;
        getCoordinates(next, n, r, c);

        // If there is a snake or ladder at this position, go to its
        // destination. Per the problem, even if this destination points to
        // another snake/ladder, you only travel it once per move.
        if (board[r][c] != -1) {
          next = board[r][c];
        }

        // Only add 'next' to the queue if we have not visited it yet,
        // to avoid unnecessary revisiting and infinite loops.
        if (!visited[next]) {
          visited[next] = true;
          q.push({next, moves + 1});
        }
      }
    }
    // If we've exhausted all possibilities and haven't reached target, return
    // -1.
    return -1;
  }
};
// @lc code=end
