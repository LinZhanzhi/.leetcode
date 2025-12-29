/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to count the number of contiguous subarrays where the sum of elements is divisible by k.
 *
 * High-Level Summary:
 * -------------------
 * A brute-force approach checking all subarrays would be O(N^2), which is too slow for N=30,000.
 * We can use the Prefix Sum technique combined with a Hash Map (or an array since k is small).
 *
 * Key Insight:
 * Let P[i] be the prefix sum from index 0 to i.
 * The sum of a subarray from i to j is sum(i, j) = P[j] - P[i-1].
 * We want (P[j] - P[i-1]) % k == 0.
 * This implies P[j] % k == P[i-1] % k.
 *
 * So, if two prefix sums have the same remainder modulo k, the subarray between them is divisible by k.
 *
 * Algorithm:
 * 1. Initialize a frequency array (or map) count of size k to store the frequency of each remainder.
 *    Initialize count[0] = 1 to handle subarrays starting from index 0 (conceptually P[-1] = 0).
 * 2. Iterate through the array, maintaining a running prefixSum.
 * 3. Calculate
emainder = prefixSum % k.
 *    - Note: In C++, the % operator can return negative values for negative numbers.
 *    - We need to normalize the remainder to be in [0, k-1]:
emainder = (remainder % k + k) % k.
 * 4. Add count[remainder] to our total answer. This adds the number of times this remainder has been seen before, forming valid subarrays ending at the current position.
 * 5. Increment count[remainder].
 *
 * Time Complexity: O(N) - Single pass through the array.
 * Space Complexity: O(K) - To store the frequency of remainders.
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Frequency array to store counts of remainders.
        // Since remainders are in [0, k-1], a vector of size k is sufficient and faster than a map.
        vector<int> remainderCounts(k, 0);

        // Initialize remainder 0 with count 1.
        // This represents a prefix sum of 0 before the array starts.
        remainderCounts[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            // Calculate remainder
            int remainder = prefixSum % k;

            // Handle negative remainders to ensure they are in [0, k-1]
            if (remainder < 0) {
                remainder += k;
            }

            // If we have seen this remainder before, it means there are subarrays
            // ending here that are divisible by k.
            count += remainderCounts[remainder];

            // Increment the count for this remainder
            remainderCounts[remainder]++;
        }

        return count;
    }
};
// @lc code=end
