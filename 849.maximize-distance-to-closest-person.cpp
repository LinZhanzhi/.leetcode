/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 */

// Brief Digested Understanding:
// ----
// The core challenge here is to, given an array where 1 means "seat occupied"
// and 0 means "seat empty," determine the optimal empty seat for Alex such that
// his distance to the nearest person is as large as possible. "Distance" means
// the number of seats between Alex and the closest person (minimizing among all
// people). We are to find, across all empty seats, the *maximum* such minimal
// distance.
//
// The trick is: the best seat is either at a stretch of zeros at the ends (the
// beginning or the end of the array), or somewhere in the middle between two
// occupied seats, whichever produces the greatest minimal distance to a 1.

// High-Level Summary:
// ----
// Our approach will do a linear sweep of the seats array, identifying stretches
// of empty (zero-valued) seats. For gaps between two occupied seats, the
// optimal position is in the middle of the stretch, with minimal distance half
// the length of the gap (rounded down). For stretches of empty seats at the
// start or end, the distance extends up to the nearest occupied seat, so the
// minimal distance is simply the length of the stretch. We'll process the array
// in a single pass, tracking distances as we go. Time Complexity: O(n), as we
// scan the array once. Space Complexity: O(1), using only a few variables for
// tracking indices and distances.

#include <algorithm> // Include algorithm for std::max
#include <vector>    // Include vector for using std::vector

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the maximal minimal distance to the closest person
  int maxDistToClosest(vector<int> &seats) {
    // Find the length (number of seats)
    int n = seats.size();

    // Find the longest run of leading zeros (empty seats at the start)
    int leadingZeros = countLeadingZeros(seats, n);

    // Find the longest run of trailing zeros (empty seats at the end)
    int trailingZeros = countTrailingZeros(seats, n);

    // Find the largest distance in middle gaps (between two occupied seats)
    int maxMiddleGap = findMaxGap(seats, n);

    // The answer is the maximum among leading zeros, trailing zeros, and the
    // best middle gap (which must be halved) For middle gaps, since Alex should
    // sit in the middle, it's gap/2 (rounded down)
    return std::max({leadingZeros, trailingZeros, maxMiddleGap});
  }

private:
  // Helper to count the number of leading zeros at the start of the array
  int countLeadingZeros(const vector<int> &seats, int n) {
    int count = 0;
    // Iterate from the left and stop at the first occupied seat
    while (count < n && seats[count] == 0) {
      count++;
    }
    return count;
  }

  // Helper to count the number of trailing zeros at the end of the array
  int countTrailingZeros(const vector<int> &seats, int n) {
    int count = 0;
    // Iterate from the right and stop at the first occupied seat
    int i = n - 1;
    while (i >= 0 && seats[i] == 0) {
      count++;
      i--;
    }
    return count;
  }

  // Helper to find the maximal possible distance Alex can have in a gap between
  // two occupied seats
  int findMaxGap(const vector<int> &seats, int n) {
    int maxDist = 0;
    // We'll keep track of the last occupied seat's index as we iterate
    int lastOccupied = -1;

    for (int j = 0; j < n; ++j) {
      if (seats[j] == 1) { // When we find a person
        if (lastOccupied >= 0) {
          // Number of seats between lastOccupied and j (exclusive)
          int gap = j - lastOccupied - 1;
          // If there is a gap, the best spot is in the middle, so minimal
          // distance is gap/2 (rounded up/down) Since Alex must sit in a seat
          // (which is index-based), we take gap/2
          int dist = (gap + 1) / 2;
          if (dist > maxDist) {
            maxDist = dist;
          }
        }
        lastOccupied = j;
      }
    }
    return maxDist;
  }
};
// @lc code=end
