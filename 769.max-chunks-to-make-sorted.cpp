/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about dividing a permutation of the numbers 0 to n-1 into
 * as many contiguous "chunks" as possible so that, if you sort each chunk
 * independently and concatenate all results, you get the fully sorted
 * permutation (sorted in increasing order from 0 up to n-1).
 *
 * The core insight is: pick the "split points" such that the numbers on
 * the left do not "overshadow" numbers that would need to come before them
 * in the sorted list. Each chunk must be such that after sorting all chunks
 * individually and putting them back together, the global order is preserved.
 *
 * For a valid chunk ending at index i, all numbers up to that point must be
 * less than or equal to i (since it's a permutation from 0 to n-1).
 *
 * --
 *
 * High-Level Summary:
 * ----
 * We solve this by iterating through the array and tracking the maximum
 * value seen so far at each index. If, at any index i, the maximum value
 * encountered up to i is exactly i, then the subarray [0..i] is a valid
 * chunk that can be sorted independently (because all the elements up to i
 * are within [0, i]). We repeat this for the whole array and count the
 * number of such splits.
 *
 * Algorithm Steps:
 *   - Walk through the array, updating a running maximum.
 *   - When the running maximum equals the current index, increment the chunk
 * count.
 *   - Return the total number of chunks found.
 *
 * Patterns: Greedy algorithm, prefix maximums.
 * Data Structures: Simple integer variables.
 *
 * Time Complexity: O(n), where n is the array length (one pass).
 * Space Complexity: O(1), using only a few variables.
 */

// We need to include the vector header for using 'vector'
#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to find the largest number of chunks to sort the array as
  // required
  int maxChunksToSorted(vector<int> &arr) {
    // Helper function tracks running max and counts chunks
    return countChunksUsingPrefixMax(arr);
  }

private:
  // Helper function which counts valid chunk endings using prefix maximum
  // tracking
  int countChunksUsingPrefixMax(const vector<int> &arr) {
    int chunks = 0;  // Stores the total number of valid chunks
    int currMax = 0; // Tracks the current prefix maximum

    // Traverse the array to decide chunk bounds.
    for (int i = 0; i < arr.size(); ++i) {
      currMax = std::max(currMax, arr[i]);
      // If the current prefix max is equal to the current index,
      // it means all numbers in [0..i] are within 0..i, possibly not in order,
      // so they can be sorted independently without affecting the overall
      // sequence.
      if (currMax == i) {
        ++chunks; // Split a chunk here
      }
      // Else, wait for the prefix max to "catch up" to the index.
    }
    // The result is the number of valid chunks found
    return chunks;
  }
};
/*
 * Sample Input/Output Walkthrough:
 * ---------------------------------
 * Let's apply the algorithm step-by-step to the sample input:
 *
 *   Input: arr = [1,0,2,3,4]
 *
 * We'll use two variables:
 *   - currMax: the running maximum value (initially 0)
 *   - chunks: the count of chunks detected so far (initially 0)
 *
 * Step-by-step trace:
 *
 * i = 0:
 *   - arr[0] = 1
 *   - currMax = max(0, 1) = 1
 *   - Is currMax == i? 1 == 0 → No
 *   - Chunks = 0
 *
 * i = 1:
 *   - arr[1] = 0
 *   - currMax = max(1, 0) = 1
 *   - Is currMax == i? 1 == 1 → Yes
 *   - Increment Chunks: Chunks = 1 (We can end a chunk at index 1: arr[0..1] =
 * [1,0])
 *
 * i = 2:
 *   - arr[2] = 2
 *   - currMax = max(1, 2) = 2
 *   - Is currMax == i? 2 == 2 → Yes
 *   - Increment Chunks: Chunks = 2 (Chunk at index 2: arr[2] = [2])
 *
 * i = 3:
 *   - arr[3] = 3
 *   - currMax = max(2, 3) = 3
 *   - Is currMax == i? 3 == 3 → Yes
 *   - Increment Chunks: Chunks = 3 (Chunk at index 3: arr[3] = [3])
 *
 * i = 4:
 *   - arr[4] = 4
 *   - currMax = max(3, 4) = 4
 *   - Is currMax == i? 4 == 4 → Yes
 *   - Increment Chunks: Chunks = 4 (Chunk at index 4: arr[4] = [4])
 *
 * Final Result:
 *   - We determine there are 4 chunks: [1,0] | [2] | [3] | [4]
 *
 * After sorting each chunk and concatenating them, we recover the sorted array.
 */
// @lc code=end
