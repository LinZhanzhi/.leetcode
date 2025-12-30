/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given two sorted arrays and need to find the k pairs (one element from
 * each array) whose sums are the smallest among all possible pairs. Each pair
 * is simply (nums1[i], nums2[j]). The challenge is to efficiently find the k
 * smallest-sum pairs without generating all possible pairs, which would be too
 * slow for large arrays.
 *
 * High-Level Summary:
 * ----
 * The solution uses a min-heap (priority queue) to efficiently track the next
 * smallest sum pair. We start by pairing the smallest element of nums1 with the
 * smallest element of nums2, and incrementally explore the next possible pairs
 * by advancing indices in nums2 for each nums1 element. We only push new pairs
 * into the heap if they haven't been considered yet, and we stop after finding
 * k pairs. This approach leverages the sorted property of the arrays and
 * ensures we always process the next smallest sum.
 *
 * Time Complexity: O(k log k) (since at most k heap operations are performed,
 * each O(log k)) Space Complexity: O(k) (for the heap and result storage)
 */

#include <queue>  // For std::priority_queue
#include <tuple>  // For std::tuple
#include <vector> // For std::vector

using std::make_tuple;
using std::priority_queue;
using std::tuple;
using std::vector;

// @lc code=start
class Solution {
public:
  // Function to find k pairs with the smallest sums
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    // Result vector to store the answer pairs
    vector<vector<int>> result;

    // Edge case: if either array is empty, there are no pairs to form
    if (nums1.empty() || nums2.empty() || k == 0) {
      return result;
    }

    // Min-heap to store tuples of (sum, index in nums1, index in nums2)
    // The heap is ordered by the sum (smallest sum at the top)
    // We use greater<> to make it a min-heap
    using T = tuple<int, int, int>; // (sum, i, j)
    auto cmp = [](const T &a, const T &b) {
      return std::get<0>(a) > std::get<0>(b);
    };
    priority_queue<T, vector<T>, decltype(cmp)> minHeap(cmp);

    // We only need to consider at most the first k elements from nums1,
    // because there can't be more than k pairs with the smallest sums
    int n1 = nums1.size();
    int n2 = nums2.size();
    for (int i = 0; i < n1 && i < k; ++i) {
      // Each heap entry is (sum, index in nums1, index in nums2)
      // Start by pairing nums1[i] with nums2[0]
      minHeap.emplace(nums1[i] + nums2[0], i, 0);
    }

    // Extract the smallest sum pairs from the heap up to k times
    while (k-- > 0 && !minHeap.empty()) {
      // Get the current smallest sum pair
      auto [sum, i, j] = minHeap.top();
      minHeap.pop();

      // Add the corresponding pair to the result
      result.push_back({nums1[i], nums2[j]});

      // If there is a next element in nums2 for the current nums1[i],
      // push the new pair (nums1[i], nums2[j+1]) into the heap
      if (j + 1 < n2) {
        minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
      }
    }

    // Return the list of k pairs with the smallest sums
    return result;
  }
};
// @lc code=end
