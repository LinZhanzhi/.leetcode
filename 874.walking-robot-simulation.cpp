/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// Brief Digested Understanding:
// -----
// In this problem, a robot starts at the origin on an infinite 2D grid and
// follows a list of movement commands (turns or moving forward). Grid cells
// may have obstacles, and if the robot encounters an obstacle in the path of
// any command, it halts before the obstacle but continues processing
// subsequent commands. Our task is to compute the largest squared Euclidean
// distance from the origin that the robot achieves throughout its journey (that
// is, at any position visited, compute x^2 + y^2, and return the maximum
// observed).

// High-Level Summary:
// -----
// We'll simulate the robot's path step by step. We keep track of its direction
// (north, east, south, west), position, and react to command types. To
// efficiently detect obstacles, we store them in a hash set for O(1) access.
// For each movement, we check if the next step would hit an obstacle. If not,
// we update the position and maximum distance; if so, we stop for that
// command. We'll modularize the logic: a function to encode and store the
// obstacles, helpers for moving the robot and turning, and use detailed
// comments to explain decisions. Time complexity: O(len(commands) +
// len(obstacles)), since each command and obstacle is processed only once.
// Space complexity: O(len(obstacles)), for the obstacle set.

// Necessary library includes (for vector and unordered_set)
#include <algorithm> // for std::max
#include <string>
#include <unordered_set>
#include <vector>

using std::max;
using std::string;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
  // Converts a coordinate pair (x, y) to a unique string key for set storage
  // C++ doesn't have a default hash for pair<int, int>, so string is used
  string coordKey(int x, int y) {
    // Returns a key formatted as "x,y" (e.g., "3,4")
    return std::to_string(x) + "," + std::to_string(y);
  }

  // Converts the obstacle list to an unordered_set for O(1) lookup
  unordered_set<string> buildObstacleSet(const vector<vector<int>> &obstacles) {
    unordered_set<string> obsSet;
    for (const vector<int> &obstacle : obstacles) {
      obsSet.insert(coordKey(obstacle[0], obstacle[1]));
    }
    return obsSet;
  }

  // Executes a movement step, updating current position if no obstacle
  bool canMove(int nx, int ny, const unordered_set<string> &obsSet) {
    // Returns true if (nx, ny) is not an obstacle, false otherwise
    return obsSet.find(coordKey(nx, ny)) == obsSet.end();
  }

  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
    // Directions:       N      E      S      W
    // Represented as    0      1      2      3
    // Each direction is (dx, dy)
    const int dx[4] = {0, 1, 0, -1}; // X increments for N, E, S, W
    const int dy[4] = {1, 0, -1, 0}; // Y increments for N, E, S, W

    int dir = 0;       // Start facing north (0)
    int x = 0, y = 0;  // Start at (0, 0)
    int maxDistSq = 0; // Track the maximum distance squared

    // Preprocess all obstacles into a set for fast lookup
    unordered_set<string> obstacleSet = buildObstacleSet(obstacles);

    // Process each command
    for (int cmd : commands) {
      if (cmd == -2) {
        // Turn left: (dir - 1 + 4) % 4 ensures wrap-around
        dir = (dir + 3) % 4;
      } else if (cmd == -1) {
        // Turn right: (dir + 1) % 4 cycles direction clockwise
        dir = (dir + 1) % 4;
      } else {
        // Move forward cmd steps, one step at a time
        for (int step = 0; step < cmd; ++step) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          // Check for obstacles at the next cell
          if (canMove(nx, ny, obstacleSet)) {
            // No obstacle, move to next cell
            x = nx;
            y = ny;
            // Update max distance squared
            maxDistSq = max(maxDistSq, x * x + y * y);
          } else {
            // Hit an obstacle, stop movement for this command
            break;
          }
        }
      }
    }
    // Return the farthest squared distance reached from the origin
    return maxDistSq;
  }
};
// @lc code=end
