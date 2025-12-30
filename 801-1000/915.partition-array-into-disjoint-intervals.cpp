/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// Brief Digested Understanding:
// ----
// The problem asks us to split an array into two contiguous parts—`left` and
// `right`—so that every element in `left` is less than or equal to every
// element in `right`. Both parts must have at least one element, and we want
// `left` to be as small as possible. We're to find and return the length of the
// `left` partition. The key is that only the boundary between left/right can
// move, but the property must always be satisfied for all elements.

// High-Level Summary:
// ----
// The core insight is to track, for every index, the largest value seen so far
// on the left (prefix max), and the smallest value seen to the right (suffix
// min). We look for the earliest index `i` where the maximum in `left` (ending
// at i) is ≤ the minimum in `right` (starting at i+1). To do this efficiently,
// we first build a suffix-mins array backwards, so for each cut-point, we can
// compare the prefix max (as we scan forward) with the next suffix min. This
// approach runs in O(N) time and uses O(N) space. It's possible to optimize to
// O(1) space with careful variable use, but the helper array is educational for
// clarity. The solution is modularized with helper functions to make each phase
// clear.

// @lc code=start

#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
  // The main function to determine the minimum partition position
  int partitionDisjoint(vector<int> &nums) {
    int n = nums.size();
    // Compute the suffix minimums so suffixMin[i] = min(nums[i..n-1])
    vector<int> suffixMin = buildSuffixMinArray(nums);

    // Now iterate, tracking the running maximum in the prefix (left part)
    int prefixMax = nums[0]; // left always includes at least nums[0]
    // Walk to the split position and find the minimal valid cut
    // split between i (left ends at i), i+1 (right starts)
    for (int i = 0; i < n - 1; ++i) {
      prefixMax = max(prefixMax, nums[i]);
      // Checking: if left's max is ≤ right's min, found partition
      if (prefixMax <= suffixMin[i + 1]) {
        // The left partition is nums[0..i], so length is i+1
        return i + 1;
      }
    }
    // According to problem, valid answer always exists, but return n for
    // completeness
    return n;
  }

private:
  // Helper function: for each index, store the minimum from that index to the
  // end
  vector<int> buildSuffixMinArray(const vector<int> &nums) {
    int n = nums.size();
    vector<int> suffixMin(n);
    // Start from the end: the min of last element is itself
    suffixMin[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      // Each suffix min is the smaller of current and min ahead
      suffixMin[i] = min(nums[i], suffixMin[i + 1]);
    }
    return suffixMin;
  }
};
// @lc code=end
