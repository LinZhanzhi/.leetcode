/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 */

// @lc code=start

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

/*
**Brief Digested Understanding:**
This problem simulates how prison cells (represented as a row of length 8, with
each cell either occupied or vacant) change state over a number of days given a
simple rule: A cell becomes occupied if both of its adjacent neighbors are in
the same state (both occupied or both vacant); otherwise, it becomes vacant.
The first and last cells in the row have only one neighbor, so always become
vacant each day. The goal is to determine the state of the cells after `n` days.
Efficient calculation is crucial, especially for large `n`, due to possible
cycling in the state changes.

**High-Level Summary:**
We brute-force simulate the cell state day-by-day, but to optimize for large
`n`, we detect cycles in the sequence of states. Since there are only 8 cells
and the first and last always become 0, there are only 2^6 = 64 possible
internal cell configurations. We keep a mapping from seen states (as tuples or a
compressed representation) to the day number when they first occur. When a
repeated state is seen, a cycle exists; we can skip full periods of the cycle to
speed up the countdown to day `n` and directly simulate only the remainder. The
algorithm uses O(1) space for states (since the worst case is 64) and runs in
O(cycle_length) time, which is very small compared to n for large n.

*/

class Solution {
public:
  // Public function to compute the state of prison cells after `n` days
  vector<int> prisonAfterNDays(vector<int> &cells, int n) {
    // Use a helper function to simulate one day’s cell transition
    // and another to compress cell state for fast lookup

    // Map for cycle detection: key is compressed cell state, value is remaining
    // n
    unordered_map<int, int> seen;

    int cycle = 0; // Will store cycle length if a cycle is detected
    bool hasCycle = false;

    // Work on a copy because we'll update cells
    vector<int> cur = cells;

    // While there are days left
    while (n > 0) {
      int state_key = compressCells(cur);
      // Cycle detection: if we've been in this state before, a cycle exists
      if (seen.count(state_key)) {
        // The length of the cycle is the difference between previous n and
        // current n (i.e., how many days ago we saw this state)
        int prev_n = seen[state_key];
        int cycle_len = prev_n - n;
        n %= cycle_len; // Fast forward by whole cycles
        hasCycle = true;
        // After reducing n, we continue the loop. If n == 0, we break.
      }
      // Store the current state and n value
      seen[state_key] = n;
      if (n >= 1) {
        // Simulate the next day's state
        cur = nextDay(cur);
        --n;
      }
    }
    return cur;
  }

private:
  // Helper to simulate a single day’s cell state transitions
  vector<int> nextDay(const vector<int> &cells) {
    vector<int> res(8, 0); // All start as vacant
    // First and last cell are always vacant (0) on the next day
    for (int i = 1; i < 7; ++i) {
      // If both neighbors have same occupancy state, cell becomes occupied
      res[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
    }
    return res;
  }

  // Helper to convert cell vector (length 8, each 0/1) into a single integer
  // for fast lookup. We ignore the first and last cell (always 0 after the
  // first day).
  int compressCells(const vector<int> &cells) {
    int code = 0;
    for (int i = 0; i < 8; ++i) {
      code <<= 1;
      code |= cells[i];
    }
    return code;
  }
};
// @lc code=end
