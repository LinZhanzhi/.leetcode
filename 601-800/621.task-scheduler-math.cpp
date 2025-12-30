/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// Brief, Digested Understanding:
//
// This problem asks us to schedule a list of CPU tasks (each represented by a
// capital letter 'A'-'Z') so that the same task is separated by at least 'n'
// intervals (the cooling period). Each interval can either execute a task or be
// idle. The goal is to determine the minimum total number of intervals
// (including idle times) required to finish all tasks, given the cooling-off
// period 'n' between identical tasks.
//
// High-Level Summary:
//
// The main idea is that the most frequently occurring tasks will dictate the
// minimum possible schedule length. We first count the frequency of each task,
// then find the maximum frequency, and finally count how many tasks have this
// maximum frequency. Using these, we calculate the minimum required intervals
// using the formula: (max_freq - 1) * (n + 1) + number_of_tasks_with_max_freq.
// The answer is the maximum of this value and the total number of tasks (since
// if there are enough different tasks, no idles are needed). The time
// complexity is O(N), where N is the number of tasks, and the space complexity
// is O(1) because there are only 26 possible task types.

#include <algorithm> // For std::max
#include <vector>    // For std::vector

using std::vector;

class Solution {
private:
  // Helper function to count the frequency of each task.
  // Returns a vector of size 26, where each index corresponds to a letter
  // 'A'-'Z'.
  vector<int> countTaskFrequencies(const vector<char> &tasks) {
    vector<int> freq(26, 0); // Initialize frequency array for 26 letters.
    for (char task : tasks) {
      freq[task - 'A']++; // Increment the count for the corresponding task.
    }
    return freq;
  }

  // Helper function to find the maximum frequency among all tasks.
  int findMaxFrequency(const vector<int> &freq) {
    int maxFreq = 0;
    for (int f : freq) {
      if (f > maxFreq)
        maxFreq = f; // Update maxFreq if a higher frequency is found.
    }
    return maxFreq;
  }

  // Helper function to count how many tasks have the maximum frequency.
  int countMaxFrequencyTasks(const vector<int> &freq, int maxFreq) {
    int count = 0;
    for (int f : freq) {
      if (f == maxFreq)
        count++; // Increment count for each task with frequency equal to
                 // maxFreq.
    }
    return count;
  }

public:
  // Main function to compute the least number of intervals needed to finish all
  // tasks.
  int leastInterval(vector<char> &tasks, int n) {
    // Step 1: Count the frequency of each task.
    vector<int> freq = countTaskFrequencies(tasks);

    // Step 2: Find the maximum frequency among all tasks.
    int maxFreq = findMaxFrequency(freq);

    // Step 3: Count how many tasks have this maximum frequency.
    int maxFreqTasks = countMaxFrequencyTasks(freq, maxFreq);

    // Step 4: Calculate the minimum intervals needed using the formula:
    // (maxFreq - 1) * (n + 1) + maxFreqTasks
    // - (maxFreq - 1): Number of full "blocks" between the most frequent tasks.
    // - (n + 1): Each block has n idle slots + 1 task slot.
    // - maxFreqTasks: Add the last set of most frequent tasks.
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int minIntervals = partCount * partLength + maxFreqTasks;

    // Step 5: The answer is the maximum of minIntervals and the total number of
    // tasks.
    // - If there are enough tasks to fill all idle slots, no idles are needed.
    // - Otherwise, we need to add idle intervals.
    return std::max((int)tasks.size(), minIntervals);
  }
};
// @lc code=end
