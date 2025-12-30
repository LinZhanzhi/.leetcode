/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to find the length of the longest contiguous subarray where the comparison signs between adjacent elements flip.
 * That is, the subarray elements go up, down, up, down... or down, up, down, up...
 *
 * High-Level Summary:
 * -------------------
 * We can solve this in a single pass (O(N)) using dynamic programming or a state machine approach.
 * We maintain two variables:
 * - inc: The length of the longest turbulent subarray ending at the current index i with an increasing move (rr[i-1] < arr[i]).
 * - dec: The length of the longest turbulent subarray ending at the current index i with a decreasing move (rr[i-1] > arr[i]).
 *
 * At each step i:
 * - If rr[i] > arr[i-1] (UP): We can extend a subarray that ended with a DOWN move at i-1. So inc = dec + 1. dec resets to 1.
 * - If rr[i] < arr[i-1] (DOWN): We can extend a subarray that ended with an UP move at i-1. So dec = inc + 1. inc resets to 1.
 * - If rr[i] == arr[i-1] (EQUAL): Turbulence breaks. Both inc and dec reset to 1.
 *
 * We track the maximum of inc and dec throughout the iteration.
 *
 * Time Complexity: O(N) - Single pass.
 * Space Complexity: O(1) - Only a few variables used.
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int inc = 1; // Length of turbulent subarray ending at i with arr[i-1] < arr[i]
        int dec = 1; // Length of turbulent subarray ending at i with arr[i-1] > arr[i]
        int maxLen = 1;

        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]) {
                // Current step is UP. Previous must be DOWN.
                inc = dec + 1;
                dec = 1;
            } else if (arr[i] < arr[i-1]) {
                // Current step is DOWN. Previous must be UP.
                dec = inc + 1;
                inc = 1;
            } else {
                // Equality breaks turbulence.
                inc = 1;
                dec = 1;
            }
            maxLen = max(maxLen, max(inc, dec));
        }

        return maxLen;
    }
};
// @lc code=end
