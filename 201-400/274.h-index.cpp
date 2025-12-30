/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The h-index is a metric that measures both the productivity and citation
 * impact of a researcher's publications. For a given list of citation counts
 * (one per paper), the h-index is the largest number h such that the researcher
 * has at least h papers with at least h citations each. In other words, we want
 * to find the maximum h where there are h or more papers with at least h
 * citations.
 *
 * High-Level Summary:
 * ----
 * The most straightforward way to compute the h-index is to sort the citations
 * in descending order. Then, we iterate through the sorted list and look for
 * the largest index (plus one, since indices are 0-based) where the citation
 * count is at least as large as the index+1. This approach is efficient and
 * easy to understand.
 *
 * Algorithm:
 *   1. Sort the citations array in descending order.
 *   2. Iterate through the sorted array, and for each position i, check if
 * citations[i] >= i+1.
 *   3. The largest i+1 that satisfies this condition is the h-index.
 *
 * Time Complexity: O(n log n) due to sorting, where n is the number of papers.
 * Space Complexity: O(1) if sorting in-place, otherwise O(n) if a copy is made.
 */

#include <algorithm> // Include algorithm for std::sort
#include <vector>    // Include vector for using std::vector

using std::vector; // Bring std::vector into the current namespace

// @lc code=start
class Solution {
public:
  int hIndex(vector<int> &citations) {
    // Sort the citations in descending order so that the most cited papers come
    // first
    std::sort(citations.begin(), citations.end(), std::greater<int>());
    // Initialize h to 0; this will store the maximum h-index found
    int h = 0;
    // Iterate through the sorted citations
    for (int i = 0; i < citations.size(); ++i) {
      // For each paper, check if it has at least (i+1) citations
      // (i+1) because indices are 0-based, but h-index is 1-based
      if (citations[i] >= i + 1) {
        // If so, update h to (i+1)
        h = i + 1;
      } else {
        // If not, we can't increase h any further, so break out of the loop
        break;
      }
    }
    // Return the computed h-index
    return h;
  }
};
// @lc code=end
