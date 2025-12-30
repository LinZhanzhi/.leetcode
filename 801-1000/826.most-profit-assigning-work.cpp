/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start

#include <algorithm> // For std::sort and std::max
#include <vector>    // For std::vector to handle dynamic arrays

using std::vector;

//
// Brief Digested Understanding:
//
// This problem is about assigning jobs to workers in a way that maximizes
// overall profit. Each job has a difficulty and a profit, and each worker has
// an ability indicating the highest difficulty job they can do. Each worker can
// do at most one job, but any number of workers can do the same job. If a
// worker can't do a job (too difficult), their profit is zero. The goal is to
// maximize the sum of profits acquired by all workers.
//
/*
    - Each worker chooses the most profitable job they can do (i.e., that
   doesn't exceed their ability).
    - The solution must efficiently pick, for each worker, the best profit
   available to them—this is a classic sort-and-sweep assignment pattern.
*/

//
// High-Level Summary:
//
// To solve this problem, we:
//
// 1. Pair up all jobs into (difficulty, profit), and sort them by difficulty so
// we can process them in order.
// 2. Sort the workers by their ability.
// 3. Sweep through both lists using a two-pointer technique: As we increase
// workers' abilities, we keep track of the
//    maximum profit possible for any job up to the worker's ability. For every
//    worker, assign them this best-possible profit. This avoids re-checking
//    every job for every worker, leading to O(N log N + M log M) time
//    complexity, where N=jobs and M=workers.
// 4. Resulting space complexity is O(N + M) for storage of the sorted input and
// helper structures.
//
// The main algorithmic pattern is "greedy sweep with pre-processing", and uses
// sorting plus cumulation.
//
class Solution {
public:
  // Helper function to bundle and sort jobs by difficulty
  vector<std::pair<int, int>>
  sortJobsByDifficulty(const vector<int> &difficulty,
                       const vector<int> &profit) {
    vector<std::pair<int, int>> jobs;
    for (size_t i = 0; i < difficulty.size(); ++i) {
      jobs.emplace_back(difficulty[i], profit[i]);
    }
    // Sort jobs in increasing order of difficulty.
    std::sort(jobs.begin(), jobs.end());
    return jobs;
  }

  // Helper function to sort workers by their ability for efficient processing
  vector<int> sortWorkers(const vector<int> &worker) {
    vector<int> sorted_worker = worker;
    std::sort(sorted_worker.begin(), sorted_worker.end());
    return sorted_worker;
  }

  // Main function to compute maximum total profit by assigning jobs greedily
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    // Step 1: Bundle and sort jobs by (difficulty, profit)
    vector<std::pair<int, int>> jobs = sortJobsByDifficulty(difficulty, profit);

    // Step 2: Sort workers by their ability
    vector<int> workers = sortWorkers(worker);

    int totalProfit = 0;     // Final total profit
    int jobIndex = 0;        // Index in the jobs array
    int bestProfitSoFar = 0; // Max profit available up to current difficulty

    // Step 3: For each worker, assign the best available job they can perform
    for (int ability : workers) {
      // While jobs exist that the worker can do (difficulty <= ability), move
      // forward
      while (jobIndex < jobs.size() && jobs[jobIndex].first <= ability) {
        // Keep track of the highest profit up to this job's difficulty
        bestProfitSoFar = std::max(bestProfitSoFar, jobs[jobIndex].second);
        ++jobIndex;
      }
      // Assign this best profit (might be zero if no job is suitable)
      totalProfit += bestProfitSoFar;
    }
    return totalProfit;
  }
};
// @lc code=end
