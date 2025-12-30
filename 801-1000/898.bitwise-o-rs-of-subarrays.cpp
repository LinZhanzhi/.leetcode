/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

// Brief Digested Understanding:
// ----
// The main goal is to find out, for all possible non-empty contiguous subarrays
// in the array 'arr', how many unique results you can get if you take the
// bitwise OR of every subarray. The bitwise OR operation combines all numbers
// in a subarray using the '|' (OR) operator. We need to consider every possible
// subarray, compute its OR, and count how many different (distinct) results
// appear, not how often they appear.

// High-Level Summary:
// ----
// To solve this efficiently (without checking all O(n^2) subarrays
// individually), we use sets to store the possible OR results ending at each
// position in the array. For each array element, we update a set with all ORs
// that can be reached by either extending previous subarrays or starting a new
// one. By merging these sets across positions, we get all possible unique OR
// outcomes. The main data structures involved are C++ STL unordered_set (for
// fast lookup and deduplication). The solution iterates over the input array
// once, with an inner loop of typically up to 32 iterations due to the nature
// of the bitwise OR operation (since the value can't grow infinitely). This
// results in an amortized O(n * 32) = O(n) time complexity for practical
// inputs. Space complexity is also O(n) in the worst case (if all subarrays
// have unique OR results).

#include <unordered_set> // For std::unordered_set to store unique ORs efficiently
#include <vector>        // For std::vector to represent the input array

using std::unordered_set;
using std::vector;

class Solution {
public:
  // Main function to return the count of distinct bitwise ORs of all non-empty
  // subarrays
  int subarrayBitwiseORs(vector<int> &arr) {
    // 'res' will store all unique OR values found from any subarray
    unordered_set<int> res;
    // 'cur' at each step stores the ORs of all subarrays ending at the current
    // index
    unordered_set<int> cur;

    // Helper function to efficiently update 'cur' with all ORs ending at index
    // 'i' Returns the set of all distinct OR values for subarrays ending with
    // arr[i]
    auto getOrsForCurrent = [&](int num, const unordered_set<int> &prev) {
      unordered_set<int> next;
      // For each OR-value in the previous set, calculate the new OR by
      // including arr[i]
      for (int x : prev) {
        // This evaluates extending each previous subarray by current element
        next.insert(x | num);
      }
      // Also, start a new subarray at current index (just arr[i])
      next.insert(num);
      return next;
    };

    // Iterate through each element in arr
    for (int num : arr) {
      // Calculate all OR values for subarrays ending at current position
      cur = getOrsForCurrent(num, cur);
      // Merge current OR values into cumulative result set
      res.insert(cur.begin(), cur.end());
    }
    // The total number of unique OR results is the answer
    return static_cast<int>(res.size());
  }
};
// @lc code=end
