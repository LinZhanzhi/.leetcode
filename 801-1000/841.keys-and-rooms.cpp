/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// Brief Digested Understanding:
// -----
// In this problem, we are given a list of rooms, each containing keys to other
// rooms. Starting from room 0 (which is always unlocked), you must explore: can
// you eventually visit every room using only the keys you find as you go? The
// core challenge is traversing this "room-key" structure to decide if all rooms
// become accessible from room 0. It's about reachability, like walking through
// a network where each connection is given by the available keys in each room.

// High-Level Summary:
// -----
// To solve this, we'll use a traversal algorithm (like Depth-First Search, DFS)
// to simulate visiting rooms, starting from room 0. We'll track which rooms
// we've visited using a boolean array. Each time we enter a room, we grab all
// its keys and attempt to visit all unvisited rooms unlocked by those keys. At
// the end, if all rooms have been visited, the answer is true; otherwise, it's
// false. We'll modularize with helper functions for traversal clarity. Time
// complexity is O(N + M), where N = number of rooms and M = total number of
// keys. Space complexity is O(N) for the visited array and call stack (if using
// recursion), or queue if using BFS.

// @lc code=start
#include <vector>  // For vector type
using std::vector; // So we can just write 'vector'

// The main solution class for the problem.
class Solution {
public:
  // Public function to check if all rooms can be visited starting from room 0
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();           // Number of rooms
    vector<bool> visited(n, false); // Track whether each room has been visited

    // Start recursive DFS traversal from room 0
    dfs(0, rooms, visited);

    // After traversal, check if there are any unvisited rooms
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) { // If any room wasn't visited, return false
        return false;
      }
    }
    // All rooms were visited
    return true;
  }

private:
  // Helper function to perform Depth-First Search traversal
  void dfs(int room, const vector<vector<int>> &rooms, vector<bool> &visited) {
    // If we've already visited this room, we don't need to visit again
    if (visited[room]) {
      return;
    }
    // Mark this room as visited because we just entered it
    visited[room] = true;

    // Loop over all keys found in the current room
    for (int key : rooms[room]) {
      // For each key, try to visit that room recursively
      dfs(key, rooms, visited);
    }
  }
};
// @lc code=end
