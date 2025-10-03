/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// Brief, Digested Understanding:
//
// The problem is about scheduling a list of CPU tasks (each represented by a
// capital letter 'A'-'Z') so that the same task is separated by at least 'n'
// intervals (the cooling period). Each interval can either execute a task or be
// idle. The goal is to determine the minimum total number of intervals
// (including idle times) required to finish all tasks, given the cooling-off
// period 'n' between identical tasks.
//
// High-Level Summary:
//
// This solution simulates the scheduling process using a max-heap (priority
// queue) to always pick the task with the highest remaining count. In each
// cycle of length n+1 (to respect the cooldown), we pick up to n+1 different
// tasks to execute, decrementing their counts. If a task still has remaining
// occurrences, it is pushed back into the heap for future cycles. If there are
// fewer than n+1 tasks available, idle intervals are added. The process
// continues until all tasks are completed. The time complexity is O(N log K),
// where N is the number of tasks and K is the number of unique task types (at
// most 26), and the space complexity is O(K).

#include <algorithm> // For std::max
#include <queue>     // For std::priority_queue
#include <vector>    // For std::vector

using std::priority_queue;
using std::vector;

class Solution {
private:
  // Helper function to count the frequency of each task.
  // Returns a vector of size 26, where each index corresponds to a letter
  // 'A'-'Z'.
  vector<int> getTaskFrequencies(const vector<char> &tasks) {
    vector<int> frequencies(26, 0); // There are 26 uppercase English letters.
    for (char task : tasks) {
      frequencies[task -
                  'A']++; // Increment the count for the corresponding task.
    }
    return frequencies;
  }

  // Helper function to initialize the max-heap (priority queue) with task
  // frequencies. Only non-zero frequencies are pushed into the heap.
  priority_queue<int> buildMaxHeap(const vector<int> &frequencies) {
    priority_queue<int> maxHeap;
    for (int freq : frequencies) {
      if (freq > 0) {
        maxHeap.push(freq); // Push the frequency of each task into the heap.
      }
    }
    return maxHeap;
  }

public:
  // Main function to compute the least number of intervals needed to finish all
  // tasks.
  int leastInterval(vector<char> &tasks, int n) {
    // Step 1: Count the frequency of each task.
    vector<int> taskFrequencies = getTaskFrequencies(tasks);

    // Step 2: Build a max-heap (priority queue) to always pick the task with
    // the highest remaining count.
    priority_queue<int> maxHeap = buildMaxHeap(taskFrequencies);

    int totalIntervals = 0; // This will store the total time (intervals) needed
                            // to finish all tasks.

    // Step 3: Simulate the scheduling process.
    // Continue until all tasks are completed (i.e., the heap is empty).
    while (!maxHeap.empty()) {
      int cycleLength =
          n +
          1; // Each cycle can have up to n+1 tasks (to respect the cooldown).
      vector<int> tasksToRequeue; // Store tasks that still have remaining
                                  // occurrences after this cycle.

      // Step 3a: Try to execute up to cycleLength tasks in this cycle.
      for (int i = 0; i < cycleLength; ++i) {
        if (!maxHeap.empty()) {
          int currentTaskCount = maxHeap.top();
          maxHeap.pop();
          // Execute the task (decrement its count).
          if (currentTaskCount > 1) {
            // If the task still has remaining occurrences, add it to the list
            // to requeue.
            tasksToRequeue.push_back(currentTaskCount - 1);
          }
          totalIntervals++; // One interval is used for this task.
        } else {
          // If there are no tasks left to execute in this cycle, but the heap
          // is not empty, we need to add idle time (unless all tasks are done).
          // We'll add idle time after the cycle if needed.
          if (maxHeap.empty() && tasksToRequeue.empty()) {
            // All tasks are done, so we break early and do not add idle time.
            break;
          }
          totalIntervals++; // This interval is idle.
        }
      }

      // Step 3b: Push any remaining tasks back into the heap for the next
      // cycle.
      for (int remainingCount : tasksToRequeue) {
        maxHeap.push(remainingCount);
      }
      // If the heap is empty, all tasks are done, and we do not need to add
      // further idle time. Otherwise, the next cycle will continue.
    }

    return totalIntervals;
  }
};
// @lc code=end
