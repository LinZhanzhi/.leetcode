/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The h-index is a measure of a researcher's impact: it is the largest number h
 * such that the researcher has at least h papers with at least h citations
 * each. In this problem, we are given a sorted (ascending) array of citation
 * counts for each paper. Our goal is to efficiently find the h-index using this
 * sorted property.
 *
 * Let's use an example to clarify:
 *   Input: citations = [0, 1, 3, 5, 6]
 *   - There are 5 papers.
 *   - For h = 3: There are 3 papers with at least 3 citations (3, 5, 6).
 *   - For h = 4: There are only 2 papers with at least 4 citations (5, 6).
 *   - So the h-index is 3.
 * The sorted order allows us to use binary search to quickly find the largest h
 * that satisfies the condition.
 */

/*
 * High-Level Summary:
 * ----
 * We use binary search to find the h-index in O(log n) time.
 * At each step, we pick a middle index mid. The number of papers with at least
 * citations[mid] citations is (n - mid), since the array is sorted in ascending
 * order. If citations[mid] >= (n - mid), it means we could have an h-index of
 * at least (n - mid), so we try to find a higher h-index by searching the left
 * half. Otherwise, we search the right half for a possible higher citations
 * value.
 *
 * Example Walkthrough (citations = [0, 1, 3, 5, 6]):
 *   n = 5
 *   1. left = 0, right = 4
 *   2. mid = 2, citations[2] = 3, papers_with_at_least_citations_mid = 5 - 2 =
 * 3
 *      - 3 >= 3, so result = 3, search left half (right = 1)
 *   3. mid = 0, citations[0] = 0, papers_with_at_least_citations_mid = 5 - 0 =
 * 5
 *      - 0 < 5, search right half (left = 1)
 *   4. mid = 1, citations[1] = 1, papers_with_at_least_citations_mid = 5 - 1 =
 * 4
 *      - 1 < 4, search right half (left = 2)
 *   5. left > right, stop. The answer is result = 3.
 *
 * Time Complexity: O(log n), where n is the number of papers.
 * Space Complexity: O(1), as we use only a few variables for binary search.
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring vector into the current namespace

// @lc code=start
class Solution {
public:
  int hIndex(vector<int> &citations) {
    // Number of papers
    int n = citations.size();
    // Binary search boundaries: left is the start, right is the end of the
    // array
    int left = 0, right = n - 1;
    // The result variable will store the h-index found
    int result = 0;

    // Perform binary search
    while (left <= right) {
      // Find the middle index
      int mid = left + (right - left) / 2;
      // The number of papers with at least citations[mid] citations is (n -
      // mid)
      int papers_with_at_least_citations_mid = n - mid;

      // If citations[mid] is greater than or equal to the number of such
      // papers, it means we could have an h-index of at least (n - mid)
      if (citations[mid] >= papers_with_at_least_citations_mid) {
        // Update result to this possible h-index
        result = papers_with_at_least_citations_mid;
        // Try to find a higher h-index by searching the left half
        right = mid - 1;
      } else {
        // Otherwise, search the right half for a possible higher citations
        // value
        left = mid + 1;
      }
    }
    // Return the highest h-index found
    return result;
  }
};
// @lc code=end
