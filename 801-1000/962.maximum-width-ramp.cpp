/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * The problem asks us to find the widest "ramp" in an array of integers.
 * A ramp is defined by two indices, `i` and `j`, where `i` comes before `j` (i < j)
 * and the value at `i` is less than or equal to the value at `j` (nums[i] <= nums[j]).
 * The "width" is simply the distance between these indices (`j - i`).
 * We want to maximize this distance. Essentially, for every number, we want to find
 * the furthest number to its right that is greater than or equal to it.
 *
 * High-Level Summary:
 * -------------------
 * To solve this efficiently (better than O(N^2)), we can use a Monotonic Stack approach.
 *
 * 1. **First Pass (Build Stack):** We iterate through the array from left to right and store indices
 *    in a stack. We only push an index `i` if `nums[i]` is strictly smaller than the value at the
 *    index currently at the top of the stack. This creates a stack of indices representing a
 *    strictly decreasing subsequence of values starting from index 0.
 *    Why? Because if `nums[k] >= nums[i]` where `k > i`, `i` is always a better candidate for the
 *    start of a ramp than `k` (since `i` is further to the left, maximizing width). So we only care
 *    about potential start points that are smaller than anything seen before them.
 *
 * 2. **Second Pass (Calculate Width):** We iterate through the array backwards (from right to left).
 *    For each index `j`, we check the top of the stack. If `nums[j]` is greater than or equal to
 *    the value corresponding to the index at the top of the stack (`nums[stack.top()]`), it means
 *    we found a valid ramp `(stack.top(), j)`.
 *    Since we want the maximum width, and we are iterating `j` from the largest possible index,
 *    once we match a start index from the stack, we can pop it. We don't need to check that start
 *    index again because any future `j` (which will be smaller) would result in a smaller width
 *    for that same start index.
 *
 * Time Complexity: O(N)
 *   - One pass to build the stack.
 *   - One pass backwards to pop from the stack. Each element is pushed and popped at most once.
 *
 * Space Complexity: O(N)
 *   - To store the stack of indices.
 */

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // Helper function to build the decreasing monotonic stack.
        // This stack will store potential 'start' indices (i) for our ramps.
        stack<int> s = buildDecreasingStack(nums);

        // Calculate the maximum width using the stack and a reverse pass.
        return calculateMaxWidth(nums, s);
    }

private:
    // Builds a stack of indices such that nums[stack[k]] > nums[stack[k+1]].
    // We only push an index if the value is smaller than the current top,
    // because we want the earliest possible 'i' for any given value range.
    stack<int> buildDecreasingStack(const vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // If stack is empty or current number is smaller than the number at stack top index
            if (s.empty() || nums[i] < nums[s.top()]) {
                s.push(i);
            }
        }
        return s;
    }

    // Iterates backwards to find the widest ramp for the candidate start indices in the stack.
    int calculateMaxWidth(const vector<int>& nums, stack<int>& s) {
        int maxWidth = 0;
        int n = nums.size();

        // Traverse from the end of the array to the beginning.
        // This 'j' represents the end of the ramp.
        for (int j = n - 1; j >= 0; --j) {
            // While the stack is not empty and the current number at 'j'
            // is greater than or equal to the number at the index on top of the stack...
            while (!s.empty() && nums[j] >= nums[s.top()]) {
                // We found a valid ramp (s.top(), j).
                // Calculate width: j - s.top()
                maxWidth = max(maxWidth, j - s.top());

                // Pop the index from the stack.
                // Why? Because we are iterating 'j' downwards. Any future 'j' will be smaller.
                // Since we've already found a valid 'j' for this specific start index s.top(),
                // this current 'j' gives the maximum possible width for this s.top().
                // We don't need to consider this start index ever again.
                s.pop();
            }
        }
        return maxWidth;
    }
};
// @lc code=end