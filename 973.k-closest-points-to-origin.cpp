/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given a list of (x, y) points on a 2D plane.
 * We need to find the k points that are closest to the origin (0, 0).
 * Distance is Euclidean, but since we only need to compare distances, we can compare squared distances (x^2 + y^2) to avoid expensive square root operations.
 * The order of the returned points does not matter.
 *
 * High-Level Summary:
 * -------------------
 * There are several ways to solve this:
 * 1. **Sorting**: Sort all points based on their squared distance from the origin and take the first k. Time: O(N log N).
 * 2. **Max-Heap**: Maintain a max-heap of size k. Iterate through points. If a point is closer than the farthest point in the heap (top), pop the top and push the new point. Time: O(N log k).
 * 3. **Quick Select (Hoare's Selection Algorithm)**: Similar to Quick Sort, we can partition the array such that the k smallest elements are on the left. This is O(N) on average.
 *
 * Given the constraints (N <= 10^4) and typical interview expectations, O(N log k) or O(N) is preferred.
 * The Quick Select approach (using std::nth_element) is the most efficient on average (O(N)) and is provided in the C++ standard library.
 *
 * Algorithm Choice:
 *   - We will use std::nth_element. This function rearranges elements such that the element at the k-th position is the one that would be in that position in a sorted sequence. All elements before it are less than or equal to it.
 *   - After
th_element, the first k elements of the vector are the k closest points (not necessarily sorted among themselves).
 *
 * Time Complexity: O(N) on average.
 * Space Complexity: O(1) extra space (modifying input vector in-place) or O(N) if we consider the input storage.
 */

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Use nth_element to partially sort the array.
        // It ensures that the element at index k (0-indexed, so actually the (k+1)-th element if we consider size,
        // but here we want the first k elements, so we partition around the iterator at points.begin() + k).
        // Wait, if we want k elements, the range is [0, k-1]. The element at index k is the (k+1)-th.
        // nth_element(begin, nth, end) places the element that would be at kth in sorted order at that position.
        // All elements before kth are <= elements at kth.
        // So if we use points.begin() + k, the first k elements (indices 0 to k-1) will be the smallest k.

        nth_element(points.begin(), points.begin() + k, points.end(),
            [](const vector<int>& a, const vector<int>& b) {
                // Compare squared distances
                long long distA = (long long)a[0] * a[0] + (long long)a[1] * a[1];
                long long distB = (long long)b[0] * b[0] + (long long)b[1] * b[1];
                return distA < distB;
            });

        // The first k elements are now the k closest points.
        // We can resize the vector to keep only the first k, or construct a new one.
        // Resizing is efficient.
        points.resize(k);

        return points;
    }
};
// @lc code=end
