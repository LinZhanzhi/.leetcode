/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */

// Brief Digested Understanding:
// ----
// We have several rabbits, each answering how many other rabbits there are with
// the same color as themselves. Each answer[i] means: "there are exactly
// answer[i] other rabbits of my color" (including themselves, that's
// answer[i]+1 per group of same color). Some rabbits may give the same answer
// and belong to the same color group—they might be counted together if
// possible. The goal is to find the minimum total number of rabbits in the
// forest that would allow for all these answers, considering there may be
// unseen rabbits not in the answers.

// High-Level Summary:
// ----
// We'll count how many times each answer appears using a hash map. For each
// unique answer y, the rabbits with answer y can be grouped in clusters of y+1
// (since that's the size of a color group). For each answer y, we have to round
// up the number of such responses to the nearest multiple of y+1 because any
// leftover rabbits would still need a full group. For example, if 5 rabbits say
// "2" (so group size = 3), we'd need two groups (since 5/3 = 1.66..., round up
// to 2), making 6 rabbits in total for these answers. We'll modularize our code
// with helper functions for counting, calculating groups, and summing up total
// rabbits. Time complexity: O(N), where N is answers.size(), since we process
// each answer once and then once per unique answer in the map. Space: O(N) for
// hash map.

// Solution code:
#include <cmath>         // For std::ceil
#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::ceil;
using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to calculate minimum number of rabbits in the forest
  int numRabbits(vector<int> &answers) {
    // Helper function to build count of each distinct answer in the input
    unordered_map<int, int> answerCount = countAnswers(answers);

    int totalRabbits = 0; // Running total for minimum rabbits required

    // Process each answer type to calculate required rabbits
    for (const auto &entry : answerCount) {
      int answer = entry.first; // The answer y (group size = y+1)
      int count = entry.second; // Number of rabbits giving this answer

      // Compute the group size (y+1): this many rabbits can have this color
      // together
      int groupSize = answer + 1;

      // Determine how many such groups are needed for the given count
      // Each group can have up to groupSize rabbits
      int groups = ceilDiv(count, groupSize);

      // Increment total by groups * groupSize (since we must "fill" groups,
      // possibly with invisible rabbits)
      totalRabbits += groups * groupSize;
    }

    return totalRabbits; // Return the minimum rabbits required
  }

private:
  // Helper function to count how many times each answer appears
  unordered_map<int, int> countAnswers(const vector<int> &answers) {
    unordered_map<int, int> countMap;
    for (int answer : answers) {
      countMap[answer]++; // Increment count for this answer value
    }
    return countMap;
  }

  // Helper function: Calculates ceil(value / divisor) for integers, avoiding
  // floating point
  int ceilDiv(int value, int divisor) {
    // This formula ensures proper rounding up for integer division
    return (value + divisor - 1) / divisor;
  }
};
// @lc code=end
