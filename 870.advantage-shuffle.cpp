/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// Brief Digested Understanding:
// -----
// In this problem, you are given two arrays of equal length. Your task is to
// rearrange the first array (nums1) to maximize the number of positions i such
// that nums1[i] is greater than nums2[i]. The result must be a permutation of
// nums1, but you are allowed to rearrange it however you want to maximize this
// "advantage" count.

// High-Level Summary:
// -----
// We'll use a greedy algorithm. First, sort nums1 in ascending order. For
// nums2, we'll sort its indices by value (recording where each element
// originally was). Then, using two pointers, for each nums2 value (from
// smallest to largest), we assign the smallest possible nums1 value that is
// strictly greater than the current nums2 value. If we can't beat it (nums1
// element is less or equal), we assign the smallest available nums1 value (this
// "sacrifice" is forced, so we use our weakest left-overs). This ensures the
// maximal number of advantageous positions. The overall time complexity is O(n
// log n), dominated by the sorting. Space complexity is O(n): we store index
// mappings, sorting buffers, and the answer array.

#include <algorithm>
#include <queue> // For priority_queue (min heap)
#include <utility>
#include <vector>

using std::pair;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function: returns a permuted version of nums1 that maximizes advantage
  // over nums2
  vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    // Helper function creates a sorted index array for nums2
    auto getSortedIndices = [](const vector<int> &arr) -> vector<int> {
      // Each entry is (index, value)
      vector<pair<int, int>> indexed;
      for (int i = 0; i < arr.size(); ++i) {
        indexed.emplace_back(i, arr[i]);
      }
      // Sort by value, keeping original indices
      std::sort(indexed.begin(), indexed.end(),
                [](auto &a, auto &b) { return a.second < b.second; });
      // Result vector holds only indices
      vector<int> sortedIndices;
      for (auto &p : indexed) {
        sortedIndices.push_back(p.first);
      }
      return sortedIndices;
    };

    // Sort nums1 in ascending order so we always choose the smallest possible
    // element to win
    vector<int> sorted_nums1(nums1);
    std::sort(sorted_nums1.begin(), sorted_nums1.end());

    // Get the indices that would sort nums2, so we map back to the original
    // order later
    vector<int> sorted_indices = getSortedIndices(nums2);

    // Prepare answer array (same length as input)
    vector<int> answer(nums1.size());

    // Use two pointers: left for smallest unbeaten, right for "strongest"
    // (sacrificial)
    int left = 0; // Pointer into sorted_nums1 (smallest unused)
    int right =
        (int)nums1.size() - 1; // Pointer into sorted_nums1 (largest unused)

    /*
     * Educational explanation:
     * ----
     * Rather than scanning for a winner each time, we use a classic greedy and
     * heap approach.
     * - The basic idea is to process nums2 in order of increasing value
     * (smallest to largest).
     * - We move through sorted_nums1 with a pointer while nums1 values are less
     * than or equal to the current nums2 value. We push each such unused nums1
     * value into a min heap; these are our potential "sacrifices" (since they
     * can't win against this or any bigger nums2).
     * - When we meet a nums1 value greater than the current nums2, we assign it
     * as the winner.
     * - If all the remaining nums2 values are too big to be beaten by any
     * remaining nums1, we have no choice but to lose, so we simply "sacrifice"
     * (pop the heap) for these nums2.
     *
     * This method ensures that we maximize our win count efficiently, with O(n
     * log n) time due to sorting and heap operations.
     */

    // We'll assign to answer as we find wins and losses.
    int n = nums1.size();
    // This heap will store nums1 elements that we cannot use to win, for later
    // sacrifices.
    // Define a min heap using priority_queue. By using greater<int>, we make a
    // min
    // heap.
    using MinHeap =
        std::priority_queue<int, std::vector<int>, std::greater<int>>;
    MinHeap min_heap;
    // Pointer to position in sorted_nums1.
    int p = 0;

    // For every nums2 element, taken in order of strength (using the previously
    // determined sorted_indices)
    for (int i = 0; i < n; ++i) {
      int idx = sorted_indices[i]; // The index of this nums2 element in
                                   // original array
      int val = nums2[idx];        // The value of nums2 at that index

      // Advance pointer p through sorted_nums1 while values are <= current
      // nums2's value Push these values to the heap as "sacrifices" (they can't
      // be used to win here or later)
      while (p < n && sorted_nums1[p] <= val) {
        min_heap.push(sorted_nums1[p]);
        ++p;
      }

      // If pointer p is still valid, sorted_nums1[p] > val: we can beat
      // nums2[idx]
      if (p < n) {
        answer[idx] = sorted_nums1[p]; // Assign win to answer
        ++p;                           // Move to next available in sorted_nums1
      } else {
        // Out of strong enough numbers for the rest of nums2: must lose,
        // sacrifice our weakest remaining nums1 (which we've been putting in
        // the heap) Heap must not be empty, but as we inserted all "failures"
        // above, it will not be.
        answer[idx] = min_heap.top();
        min_heap.pop();
      }
    }

    // Explanation of the greedy choice:
    // - When we can win, we use the minimal winning value (so stronger ones can
    // win tougher battles later).
    // - When we can't win (nums1[left] <= val), we have to lose,
    //   so we "sacrifice" our largest available (which has no hope of winning
    //   later).

    return answer;
  }
};
// @lc code=end
