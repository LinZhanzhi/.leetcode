/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

/*
 * High-Level Summary:
 * -------------------
 * Problem: Given a total number of courses and a list of prerequisite pairs,
 * determine if it is possible to finish all courses. Each course is labeled
 * from 0 to numCourses - 1. Each prerequisite is a pair [a, b] meaning to take
 * course 'a', you must first take course 'b'.
 *
 * Approach:
 * ---------
 * This solution models the problem as a directed graph, where each course is a
 * node and each prerequisite is a directed edge. The goal is to check if the
 * graph contains a cycle. If there is a cycle, it is impossible to finish all
 * courses because some courses depend on each other in a loop. The algorithm
 * uses Kahn's algorithm for topological sorting, which is an efficient way to
 * detect cycles in a directed graph. The main idea is to repeatedly remove
 * nodes with no incoming edges (in-degree 0) and reduce the in-degree of their
 * neighbors. If we can remove all nodes in this way, the graph is acyclic and
 * all courses can be finished. Otherwise, if some nodes remain (i.e., a cycle
 * exists), it is not possible to finish all courses.
 *
 * Assumptions:
 *  - numCourses >= 0
 *  - prerequisites may be empty (in which case all courses can be finished)
 *  - There may be duplicate or self-loop prerequisites, but the algorithm
 * handles them correctly.
 *
 * Time Complexity: O(N + P), where N is the number of courses and P is the
 * number of prerequisite pairs. Space Complexity: O(N + P), for the adjacency
 * list and in-degree array.
 */

#include <queue> // For using the queue data structure in BFS
#include <vector> // For using vector to represent adjacency list and in-degree array

using namespace std;

// @lc code=start
class Solution {
public:
  // Main function to determine if all courses can be finished
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // Step 1: Build the adjacency list to represent the graph.
    // Each index represents a course, and adj[i] contains all courses that
    // depend on course i. For example, if adj[1] = {0, 2}, then courses 0 and 2
    // both require course 1 as a prerequisite.
    vector<vector<int>> adj(numCourses);

    // Step 2: Build the in-degree array.
    // indegree[i] stores the number of prerequisites (incoming edges) for
    // course i. This helps us quickly find courses that have no prerequisites
    // and can be taken immediately.
    vector<int> indegree(numCourses, 0);

    // Step 3: Populate the adjacency list and in-degree array using the
    // prerequisites. Each prerequisite pair is [a, b], meaning to take course
    // 'a', you must first take course 'b'. So, we add an edge from b to a.
    for (const auto &pre : prerequisites) {
      // Add course 'a' to the list of courses that depend on 'b'
      adj[pre[1]].push_back(pre[0]);
      // Increment the in-degree of course 'a' since it has one more
      // prerequisite
      indegree[pre[0]]++;
    }

    // Step 4: Initialize a queue to perform BFS (Kahn's algorithm).
    // The queue will store all courses that currently have no prerequisites
    // (in-degree 0).
    queue<int> q;

    // Step 5: Add all courses with in-degree 0 to the queue.
    // These are the courses that can be taken immediately, as they do not
    // depend on any other course.
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    // Step 6: Initialize a counter to keep track of how many courses have been
    // "taken" (i.e., processed).
    int count = 0;

    // Step 7: Process the queue.
    // At each step, remove a course from the queue, and for each course that
    // depends on it, decrement its in-degree (since one of its prerequisites
    // has now been "taken"). If any dependent course's in-degree becomes 0, add
    // it to the queue.
    while (!q.empty()) {
      // Get the next course with no remaining prerequisites
      int course = q.front();
      q.pop();

      // Increment the count of courses that have been processed
      count++;

      // For each course that depends on the current course
      for (int next : adj[course]) {
        // Decrement the in-degree of the dependent course
        indegree[next]--;
        // If the dependent course now has no prerequisites, add it to the queue
        if (indegree[next] == 0) {
          q.push(next);
        }
      }
    }

    // Step 8: After processing, check if all courses have been "taken".
    // If count == numCourses, it means we were able to process all courses
    // without encountering a cycle. If count < numCourses, it means there is a
    // cycle, and some courses could not be taken.
    return count == numCourses;
  }
};
// @lc code=end
