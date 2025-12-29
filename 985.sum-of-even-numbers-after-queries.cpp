/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given an array
ums and a series of queries. Each query adds a value to a specific index in
ums.
 * After each update, we need to report the sum of all even numbers in the array.
 *
 * High-Level Summary:
 * -------------------
 * Instead of recalculating the sum of even numbers from scratch after each query (which would be O(N * Q)),
 * we can maintain the current sum of even numbers and update it incrementally in O(1) per query.
 *
 * Algorithm:
 * 1. Calculate the initial evenSum by iterating through
ums.
 * 2. For each query [val, index]:
 *    - Let oldVal be
ums[index].
 *    - If oldVal is even, subtract it from evenSum (removing its contribution).
 *    - Update
ums[index] by adding al.
 *    - Let
ewVal be the updated
ums[index].
 *    - If
ewVal is even, add it to evenSum (adding its new contribution).
 *    - Store evenSum in the result list.
 *
 * Time Complexity: O(N + Q), where N is the size of nums and Q is the number of queries.
 * Space Complexity: O(1) excluding the output array.
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        // Calculate initial sum of even numbers
        for (int x : nums) {
            if (x % 2 == 0) {
                evenSum += x;
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int val = q[0];
            int index = q[1];

            int oldVal = nums[index];

            // If the old value was even, remove it from the sum
            if (oldVal % 2 == 0) {
                evenSum -= oldVal;
            }

            // Update the value in the array
            nums[index] += val;
            int newVal = nums[index];

            // If the new value is even, add it to the sum
            if (newVal % 2 == 0) {
                evenSum += newVal;
            }

            ans.push_back(evenSum);
        }

        return ans;
    }
};
// @lc code=end
