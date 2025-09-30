/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the smallest possible radius for all heaters such
 * that every house is within the warm range of at least one heater. Both houses
 * and heaters are placed on a 1D line, and the radius is the same for all
 * heaters. For each house, we need to ensure there is at least one heater
 * within the chosen radius.
 *
 * High-Level Summary:
 * ----
 * The solution sorts both the houses and heaters arrays. For each house, we
 * find the closest heater (using binary search for efficiency), and compute the
 * distance to that heater. The minimum radius required is the maximum of these
 * minimum distances across all houses. This ensures every house is covered. The
 * approach leverages binary search for fast nearest-heater lookup, resulting in
 * O(N log M) time complexity, where N is the number of houses and M is the
 * number of heaters. Space complexity is O(1) extra (excluding input storage).
 */

#include <algorithm> // Include algorithm for sort and lower_bound
#include <cstdlib>   // Include cstdlib for abs()
#include <vector>    // Include vector for dynamic arrays

using std::vector;

class Solution {
public:
  // Main function to find the minimum radius needed for all heaters to cover
  // all houses
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    // Sort both houses and heaters to enable efficient searching
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());

    int minRadius =
        0; // This will store the answer: the minimum required radius

    // Iterate through each house to find the closest heater
    for (int house : houses) {
      // Find the minimum distance from this house to any heater
      int dist = findClosestHeaterDistance(house, heaters);
      // The required radius must be at least as large as the largest minimum
      // distance
      minRadius = std::max(minRadius, dist);
    }
    return minRadius;
  }

private:
  // Helper function to find the minimum distance from a house to the nearest
  // heater
  int findClosestHeaterDistance(int house, const vector<int> &heaters) {
    // Use binary search to find the first heater not less than the house's
    // position
    auto it = std::lower_bound(heaters.begin(), heaters.end(), house);

    // If the house is before all heaters, the closest is the first heater
    if (it == heaters.begin()) {
      return std::abs(*it - house);
    }
    // If the house is after all heaters, the closest is the last heater
    if (it == heaters.end()) {
      return std::abs(*(heaters.end() - 1) - house);
    }
    // Otherwise, the closest heater is either the one just before or just after
    // the house
    int dist1 =
        std::abs(*it - house); // Distance to the heater at or after the house
    int dist2 = std::abs(*(it - 1) -
                         house); // Distance to the heater just before the house
    return std::min(dist1, dist2);
  }
};
// @lc code=end
