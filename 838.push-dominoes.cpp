/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// Brief Digested Understanding:
// ----
// In this problem, imagine a row of dominoes, each of which may be untouched
// ('.'), pushed left ('L'), or pushed right ('R'). When a domino is pushed, it
// begins to fall in that direction and, in each succeeding second, causes its
// immediate neighbor in that direction to fall too (if still upright). If
// dominoes are pushed in both directions simultaneously onto an upright domino,
// it remains upright and does not fall due to equal and opposite "forces." The
// task is to simulate the dominoes falling until no more changes can happen —
// returning the final configuration as a string.

// High-Level Summary:
// ----
// The goal is to efficiently determine the effect of left ('L') and right ('R')
// pushes on every domino. We exploit the fact that dominoes are affected by the
// nearest 'L' to the right and the nearest 'R' to the left. Thus, for each
// domino, we calculate the "distance" to the most recent 'R' to its left (if
// any), and the "distance" to the most recent 'L' to its right (if any). We can
// do this in two passes: one left-to-right for 'R's and one right-to-left for
// 'L's, storing for each domino how many steps it is from a push in each
// direction. The final state of each domino depends on which direction's
// influence is closest or if they're equidistant (in which case, it remains
// upright). The solution runs in O(n) time and uses O(n) extra space for the
// force/distance tracking arrays.

#include <algorithm>
#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  string pushDominoes(string dominoes) {
    // Helper function to compute distances to closest right push 'R' for each
    // position
    vector<int> rightDistances = computeRightDistances(dominoes);
    // Helper function to compute distances to closest left push 'L' for each
    // position
    vector<int> leftDistances = computeLeftDistances(dominoes);
    // Construct the result based on which direction's influence is closer
    return computeFinalState(dominoes, leftDistances, rightDistances);
  }

private:
  // This helper calculates, for each domino, how far it is from the nearest 'R'
  // on the left. If there's no 'R' influence, the distance is set to a large
  // number.
  vector<int> computeRightDistances(const string &dominoes) {
    int n = dominoes.size();
    vector<int> rightDist(n, n + 1); // Use n+1 as "infinity" (unreachable)
    int lastR = -1;                  // Track the index of last seen 'R'
    for (int i = 0; i < n; ++i) {
      if (dominoes[i] == 'R') {
        lastR = i;        // Update the last seen 'R'
        rightDist[i] = 0; // Distance to itself is 0
      } else if (dominoes[i] == 'L') {
        // 'L' interrupts right-push influence
        lastR = -1;
        // No right influence past 'L'
      } else if (lastR != -1) {
        // If we're under the influence of a previous 'R'
        rightDist[i] = i - lastR;
      }
      // If no 'R' seen so far, rightDist[i] remains large (means no influence)
    }
    return rightDist;
  }

  // This helper calculates, for each domino, how far it is from the nearest 'L'
  // on the right. If there's no 'L' influence, the distance is set to a large
  // number.
  vector<int> computeLeftDistances(const string &dominoes) {
    int n = dominoes.size();
    vector<int> leftDist(n, n + 1); // Use n+1 as "infinity"
    int lastL = -1;                 // Track the index of last seen 'L'
    for (int i = n - 1; i >= 0; --i) {
      if (dominoes[i] == 'L') {
        lastL = i;       // Update the last seen 'L'
        leftDist[i] = 0; // Distance to itself is 0
      } else if (dominoes[i] == 'R') {
        // 'R' interrupts left-push influence
        lastL = -1;
      } else if (lastL != -1) {
        // If we're under the influence of a previous 'L'
        leftDist[i] = lastL - i;
      }
    }
    return leftDist;
  }

  // This helper decides the final fate of each domino based on distances to 'L'
  // and 'R'
  string computeFinalState(const string &dominoes, const vector<int> &leftDist,
                           const vector<int> &rightDist) {
    int n = dominoes.size();
    string result =
        dominoes; // Copy initial state to result that we will modify
    for (int i = 0; i < n; ++i) {
      // If current domino is already falling, leave it as is
      if (dominoes[i] == '.') {
        // Compare which direction's influence arrives sooner
        if (leftDist[i] == rightDist[i]) {
          // Equal force from both sides or no force: remains upright
          result[i] = '.';
        } else if (leftDist[i] < rightDist[i]) {
          // Left influence arrives first
          result[i] = 'L';
        } else if (rightDist[i] < leftDist[i]) {
          // Right influence arrives first
          result[i] = 'R';
        }
        // Otherwise, stays as '.'
      }
      // If already 'L' or 'R', we don't change it
    }
    return result;
  }
};
// @lc code=end
