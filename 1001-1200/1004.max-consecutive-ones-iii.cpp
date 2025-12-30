/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * The problem asks for the maximum length of a contiguous subarray of 1s we can achieve
 * if we are allowed to flip at most \k\ 0s to 1s.
 * This is mathematically equivalent to finding the longest contiguous subarray that contains
 * at most \k\ zeros.
 *
 * High-Level Summary:
 * -------------------
 * We use a sliding window approach (two pointers, \left\ and \
ight\).
 * 1. Expand the window by moving \
ight\ forward.
 * 2. If we encounter a 0, increment a counter of zeros.
 * 3. If the zero count exceeds \k\, the window is invalid. We shrink the window from the \left\
 *    until the zero count is back to \k\ or less.
 * 4. At each step, update the maximum length found so far (\
ight - left + 1\).
 *
 * Time Complexity: O(N), where N is the number of elements in \
ums\. Each element is visited at most twice (once by right, once by left).
 * Space Complexity: O(1), as we only use a few integer variables.
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int zerosCount = 0;
        int maxLen = 0;
        int n = nums.size();

        // Iterate with the right pointer to expand the window
        for (right = 0; right < n; ++right) {
            // If the current element is 0, increment the zero counter
            if (nums[right] == 0) {
                zerosCount++;
            }

            // If zeros exceed k, shrink the window from the left
            while (zerosCount > k) {
                if (nums[left] == 0) {
                    zerosCount--;
                }
                left++;
            }

            // Update the maximum length of the valid window
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
// @lc code=end
