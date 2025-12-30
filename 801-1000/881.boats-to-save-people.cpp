/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

/**
 * Brief Digested Understanding:
 * ----
 * At its core, this problem is about efficiently grouping people (represented
 * by their weights) into the minimum number of boats, such that no boat carries
 * more weight than the specified limit and no more than two people are in each
 * boat. The key challenge is to minimize leftover space (and thus minimize the
 * number of boats) by pairing people wisely, especially pairing lighter and
 * heavier people together when possible.
 *
 * High-Level Summary:
 * ----
 * We'll solve this problem with a greedy, two-pointer approach. The main idea
 * is to sort the array of weights and then attempt to pair the lightest person
 * (at the left pointer) with the heaviest person (at the right pointer). If
 * their total weight is within the limit, they share a boat; otherwise, the
 * heavier person goes alone. We repeat this process until all people are
 * assigned to boats. Sorting takes O(n log n) time, and the two-pointer sweep
 * is O(n), so the total time complexity is O(n log n). Space is O(1) additional
 * (excluding the sort), as we only use pointers and counters.
 */

#include <algorithm> // Include for std::sort
#include <vector>    // Include for using std::vector

using std::vector; // Import vector for convenience

// @lc code=start
class Solution {
public:
  // Main function to compute the minimum number of boats
  int numRescueBoats(vector<int> &people, int limit) {
    // First, sort the array so we can efficiently pair lightest and heaviest
    std::sort(people.begin(), people.end()); // O(n log n) sorting

    // Helper function: Implements the greedy pairing logic with two pointers
    return minimumBoatsTwoPointer(people, limit);
  }

private:
  /**
   * Helper function that uses two-pointer technique to pair people into boats.
   *
   * @param people Sorted vector of weights
   * @param limit  Weight limit per boat
   * @return The minimum number of boats needed
   */
  int minimumBoatsTwoPointer(const vector<int> &people, int limit) {
    int left = 0; // Points to the lightest unassigned person
    int right = static_cast<int>(people.size()) -
                1; // Points to the heaviest unassigned person
    int boats = 0; // Counts the number of boats used

    // Process people from both ends until all are assigned boats
    while (left <= right) {
      // If the lightest and heaviest persons can share a boat, pair them
      if (people[left] + people[right] <= limit) {
        // Explanation:
        // Pairing the lightest and heaviest possible maximizes efficiency
        // and frees up capacity for the remaining people.
        left++; // Move to the next lightest person
      }
      // Whether they are paired or not, the heaviest always boards now
      // (alone, if pairing wasn't possible).
      right--; // Move to the next heaviest person
      boats++; // One more boat used (either for one or two people)
    }

    return boats;
  }
};
// @lc code=end
