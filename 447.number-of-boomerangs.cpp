/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a set of unique points on a 2D plane. A "boomerang" is a tuple
 * of three points (i, j, k) such that the distance from i to j is equal to the
 * distance from i to k, and the order of the tuple matters (so (i, j, k) is
 * different from (i, k, j)). The task is to count all such possible boomerang
 * tuples among the given points.
 *
 * High-Level Summary:
 * ----
 * For each point i, we count how many other points are at each possible
 * distance from i. For each distance d, if there are m points at that distance
 * from i, then there are m * (m - 1) possible ordered pairs (j, k) (with j ≠ k)
 * that form boomerangs with i as the anchor. We sum this for all distances and
 * all anchor points. The solution uses a hash map to count distances
 * efficiently for each anchor point. The time complexity is O(n^2), where n is
 * the number of points, since we compare every pair of points.
 */

#include <unordered_map> // For std::unordered_map to count distances
#include <vector>        // For std::vector to store points

using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to count the number of boomerangs in the given set of points
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int totalBoomerangs = 0; // This will store the final count of boomerangs

    // Iterate through each point, treating it as the anchor point 'i'
    for (int i = 0; i < points.size(); ++i) {
      // This map will count how many points are at each squared distance from
      // point i
      unordered_map<int, int> distanceCount;

      // Compare point i with every other point j
      for (int j = 0; j < points.size(); ++j) {
        if (i == j)
          continue; // Skip if the points are the same

        // Compute the squared Euclidean distance between points i and j
        int dist = squaredDistance(points[i], points[j]);

        // Increment the count of points at this distance from i
        distanceCount[dist]++;
      }

      // For each group of points at the same distance from i,
      // count the number of boomerang tuples (i, j, k)
      for (const auto &entry : distanceCount) {
        int count = entry.second;
        // For each pair (j, k) with the same distance, order matters,
        // so there are count * (count - 1) boomerangs for this group
        totalBoomerangs += count * (count - 1);
      }
    }

    return totalBoomerangs;
  }

private:
  // Helper function to compute the squared Euclidean distance between two
  // points Using squared distance avoids floating point operations and is
  // sufficient for comparison
  int squaredDistance(const vector<int> &a, const vector<int> &b) {
    int dx = a[0] - b[0];     // Difference in x-coordinates
    int dy = a[1] - b[1];     // Difference in y-coordinates
    return dx * dx + dy * dy; // Return the sum of squares
  }
};
// @lc code=end
