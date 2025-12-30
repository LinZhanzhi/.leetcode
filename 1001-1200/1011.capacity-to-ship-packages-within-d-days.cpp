/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to find the minimum ship capacity such that we can ship all packages
 * in the given order within \days\ days.
 * The capacity determines how much weight we can carry per day.
 * If the capacity is high, we need fewer days. If low, we need more days.
 * This monotonic relationship suggests Binary Search on the answer (the capacity).
 *
 * High-Level Summary:
 * -------------------
 * 1. Define the search space for the capacity:
 *    - Lower bound (\left\): The maximum weight of a single package (we must be able to carry the heaviest item).
 *    - Upper bound (\
ight\): The sum of all weights (we can carry everything in 1 day).
 * 2. Perform Binary Search:
 *    - Pick a \mid\ capacity.
 *    - Check if it's possible to ship within \days\ using \mid\ capacity.
 *      - Simulate the process: greedily pack as much as possible into each day.
 *    - If possible, try a smaller capacity (\
ight = mid\).
 *    - If not possible, we need a larger capacity (\left = mid + 1\).
 * 3. The \left\ pointer will converge to the minimum feasible capacity.
 *
 * Time Complexity: O(N * log(S)), where N is the number of packages and S is the sum of weights.
 *   - The range of binary search is roughly S.
 *   - The check function takes O(N).
 * Space Complexity: O(1).
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0;
        int totalWeight = 0;

        for (int w : weights) {
            maxWeight = max(maxWeight, w);
            totalWeight += w;
        }

        int left = maxWeight;
        int right = totalWeight;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canShip(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    // Helper function to check if a given capacity is sufficient
    bool canShip(const vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                daysNeeded++;
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return daysNeeded <= days;
    }
};
// @lc code=end
