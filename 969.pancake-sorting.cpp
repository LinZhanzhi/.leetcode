/*
 * @lc app=leetcode id=969 lang=cpp
 *
 * [969] Pancake Sorting
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to sort an array of integers (permutation of 1 to n) using only "pancake flips".
 * A pancake flip at index k reverses the sub-array from index 0 to k-1.
 * We need to return the sequence of k-values (1-based indices) that sorts the array.
 * The number of flips should be within 10 * n.
 *
 * High-Level Summary:
 * -------------------
 * We can sort the array by iteratively placing the largest unsorted element into its correct position.
 * For the current largest element x (initially n, then n-1, ...):
 * 1. Find the index i of x.
 * 2. If x is not already at the correct position (end of the unsorted portion):
 *    a. Flip at i + 1 to bring x to the front (index 0).
 *    b. Flip at current_size to move x from the front to its correct position at the end.
 * 3. Decrease the size of the unsorted portion and repeat.
 *
 * This approach uses at most 2 flips per element, so total flips <= 2 * n, which satisfies the 10 * n constraint.
 *
 * Time Complexity: O(N^2) - In each iteration, we find the max element (O(N)) and perform flips (O(N)). We do this N times.
 * Space Complexity: O(1) - We modify the array in-place (excluding the result vector).
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();

        // Iterate from the largest value down to 1
        for (int value = n; value > 0; --value) {
            // Find the index of the current value
            int index = -1;
            for (int i = 0; i < n; ++i) {
                if (arr[i] == value) {
                    index = i;
                    break;
                }
            }

            // If the value is already in the correct position (index == value - 1), skip
            if (index == value - 1) {
                continue;
            }

            // Step 1: Bring the value to the front (index 0) if it's not already there
            if (index != 0) {
                // Flip the sub-array arr[0...index]
                // The k value is index + 1 (1-based)
                result.push_back(index + 1);
                reverse(arr.begin(), arr.begin() + index + 1);
            }

            // Step 2: Move the value from the front to its correct position (value - 1)
            // Flip the sub-array arr[0...value-1]
            // The k value is value (1-based, since value corresponds to the size of the prefix ending at value-1)
            result.push_back(value);
            reverse(arr.begin(), arr.begin() + value);
        }

        return result;
    }
};
// @lc code=end
