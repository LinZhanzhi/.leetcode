/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a list of people, each described by their height and the number
 * of people in front of them who are at least as tall as themselves. Our goal
 * is to reconstruct the original queue order that matches these constraints for
 * every person. The challenge is to arrange everyone so that, for each person,
 * the number of taller or equally tall people before them in the queue matches
 * their given value.
 */

/*
 * High-Level Summary:
 * ----
 * The solution sorts the people by descending height (so taller people are
 * placed first), and for people of the same height, by ascending number of
 * people in front (k-value). Then, it inserts each person into the queue at the
 * index equal to their k-value. This works because when we insert taller people
 * first, the k-value directly tells us where to place them, and inserting
 * shorter people later does not affect the relative order of taller people.
 *
 * Time Complexity: O(n^2) in the worst case (due to vector insertions), where n
 * is the number of people. Space Complexity: O(n) for the output queue.
 */

#include <algorithm> // Include algorithm for std::sort
#include <vector>    // Include vector for using std::vector

using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    // Sort people by descending height.
    // If two people have the same height, sort by ascending k-value.
    std::sort(people.begin(), people.end(),
              [](const vector<int> &a, const vector<int> &b) {
                // If heights are different, sort by descending height
                if (a[0] != b[0])
                  return a[0] > b[0];
                // If heights are the same, sort by ascending k-value
                return a[1] < b[1];
              });

    vector<vector<int>> queue; // This will store the reconstructed queue

    // Insert each person into the queue at the index equal to their k-value
    for (const auto &person : people) {
      // person[1] is the number of people in front who are at least as tall
      // Insert at position person[1]
      queue.insert(queue.begin() + person[1], person);
      // This works because all taller (or equally tall) people are already
      // placed, so inserting at index k ensures the correct number of taller
      // people in front.
    }

    return queue; // Return the reconstructed queue
  }
};
/*
 * Example Walkthrough:
 * ----
 * Let's use the input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
 *
 * Step 1: Sort the people by descending height, and for equal heights, by
 * ascending k-value.
 *   - Before sorting: [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
 *   - After sorting:  [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
 *     (Explanation: 7 > 6 > 5 > 4, and for 7s, 0 < 1; for 5s, 0 < 2)
 *
 * Step 2: Insert each person into the queue at the index equal to their
 * k-value.
 *   - Start with an empty queue: []
 *
 *   1. Insert [7,0] at index 0:
 *      queue: [[7,0]]
 *
 *   2. Insert [7,1] at index 1:
 *      queue: [[7,0],[7,1]]
 *
 *   3. Insert [6,1] at index 1:
 *      queue: [[7,0],[6,1],[7,1]]
 *      (Insert at index 1 pushes [7,1] to the right)
 *
 *   4. Insert [5,0] at index 0:
 *      queue: [[5,0],[7,0],[6,1],[7,1]]
 *
 *   5. Insert [5,2] at index 2:
 *      queue: [[5,0],[7,0],[5,2],[6,1],[7,1]]
 *
 *   6. Insert [4,4] at index 4:
 *      queue: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
 *
 * Final reconstructed queue:
 *   [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
 *
 * Each insertion step maintains the invariant that for each person, there are
 * exactly k people in front of them who are at least as tall.
 */
// @lc code=end
