/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
/*
 * Problem Understanding:
 *
 * Imagine you want to take several courses, but some courses require you to
 * finish others first (these are prerequisites). The task is to find an order
 * in which you can take all the courses, so that you never take a course before
 * its prerequisites. If it's impossible (for example, if there is a cycle of
 * prerequisites), you should return an empty list.
 *
 * In other words: Given a number of courses and a list of prerequisite pairs,
 * return a valid order to take all courses, or an empty list if not possible.
 */

/*
 * High-Level Solution Summary:
 *
 * This problem is a classic example of "topological sorting" on a directed
 * graph. Each course is a node, and each prerequisite relationship is a
 * directed edge. We use Kahn's algorithm (BFS-based topological sort) to find a
 * valid order:
 *   - Build a graph and track the number of prerequisites (indegree) for each
 * course.
 *   - Start with courses that have no prerequisites.
 *   - Repeatedly take such courses, updating the prerequisites of dependent
 * courses.
 *   - If we can take all courses, return the order; otherwise, return an empty
 * list.
 *
 * Assumptions:
 *   - numCourses is the total number of courses, labeled from 0 to
 * numCourses-1.
 *   - prerequisites is a list of pairs [a, b], meaning to take course a you
 * must first take course b.
 *
 * Time Complexity: O(N + P), where N is the number of courses and P is the
 * number of prerequisite pairs. Space Complexity: O(N + P), for the graph and
 * auxiliary data structures.
 */

#include <queue>  // For using std::queue in BFS
#include <vector> // For using std::vector to store lists and results

using namespace std;

// The Solution class encapsulates the method to find a valid course order.
class Solution {
public:
  // Main function to find a valid order to take all courses.
  // numCourses: total number of courses (labeled 0 to numCourses-1)
  // prerequisites: list of prerequisite pairs [a, b] (to take a, must first
  // take b)
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    // Step 1: Build the graph and indegree array.
    // graph[i] will contain all courses that depend on course i.
    vector<vector<int>> graph(
        numCourses); // Adjacency list representation of the graph
    // indegree[i] will count how many prerequisites course i has.
    vector<int> indegree(numCourses, 0); // Initialize all indegrees to 0

    // Fill the graph and indegree array based on prerequisites.
    for (const auto &pre : prerequisites) {
      int course = pre[0];             // The course to be taken
      int prereq = pre[1];             // The prerequisite course
      graph[prereq].push_back(course); // Add an edge from prereq to course
      indegree[course]++;              // Increment indegree for course
    }

    // Step 2: Initialize the queue with courses having no prerequisites.
    queue<int> q; // Queue for BFS
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        // If a course has no prerequisites, it can be taken immediately.
        q.push(i);
      }
    }

    // Step 3: Process courses in BFS order, building the result.
    vector<int> order; // Stores the valid order of courses
    while (!q.empty()) {
      int curr =
          q.front(); // Get the next course with no remaining prerequisites
      q.pop();
      order.push_back(curr); // Add it to the result order

      // For each course that depends on the current course:
      for (int next : graph[curr]) {
        indegree[next]--; // Remove the prerequisite (current course is now
                          // taken)
        if (indegree[next] == 0) {
          // If this course now has no prerequisites, add it to the queue
          q.push(next);
        }
      }
    }

    // Step 4: Check if we were able to take all courses.
    if (order.size() == numCourses) {
      // All courses can be taken; return the valid order.
      return order;
    }
    // If not all courses are in the order, there must be a cycle (impossible to
    // finish all).
    return {};
  }
};
// @lc code=end
