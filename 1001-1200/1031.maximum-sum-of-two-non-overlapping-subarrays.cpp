/*
 * Brief Digested Understanding:
 * -----------------------------
 * The problem asks for the maximum sum of two non-overlapping subarrays with lengths `firstLen` and `secondLen`.
 * The order of the subarrays doesn't matter (firstLen can be before secondLen or vice versa).
 * We need to find the optimal starting positions for these two subarrays such that they don't overlap and their combined sum is maximized.
 *
 * High-Level Summary:
 * -------------------
 * This solution uses a "Suffix Maximum" approach with O(N) time and O(N) space.
 * 1. **Subarray Sums**: We first precompute the sums of all possible subarrays of length `firstLen` and store them in `firstFrom`. Similarly, we compute sums for `secondLen` in `secondFrom`.
 *    - `firstFrom[i]` stores the sum of the subarray of length `firstLen` starting at index `i`.
 * 2. **Suffix Maximums**: We then compute suffix maximum arrays for both `firstFrom` and `secondFrom`.
 *    - `maxFirstFrom[i]` stores the maximum value in `firstFrom` from index `i` to the end. This tells us "what is the best subarray of length `firstLen` starting at or after index `i`?".
 *    - Similarly for `maxSecondFrom`.
 * 3. **Iterate and Combine**: We iterate through all possible start indices for the *first* appearing subarray in the pair.
 *    - **Case 1 (First before Second)**: If the subarray of length `firstLen` starts at `i`, the subarray of length `secondLen` must start at or after `i + firstLen`. The best such second subarray has sum `maxSecondFrom[i + firstLen]`.
 *    - **Case 2 (Second before First)**: If the subarray of length `secondLen` starts at `i`, the subarray of length `firstLen` must start at or after `i + secondLen`. The best such first subarray has sum `maxFirstFrom[i + secondLen]`.
 * 4. **Result**: We track the maximum sum found across all valid positions `i`.
 *
 * Time Complexity: O(N) - We iterate through the array a constant number of times.
 * Space Complexity: O(N) - We use auxiliary arrays to store sums and suffix maximums.
 */

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();

        // 1. Calculate subarray sums starting at each index
        // firstFrom[i] = sum of subarray of length firstLen starting at i
        vector<int> firstFrom(n - firstLen + 1);
        int currentSum = 0;
        for (int i = 0; i < firstLen; ++i) currentSum += nums[i];
        firstFrom[0] = currentSum;
        for (int i = 1; i < firstFrom.size(); ++i) {
            currentSum = currentSum - nums[i - 1] + nums[i + firstLen - 1];
            firstFrom[i] = currentSum;
        }

        // secondFrom[i] = sum of subarray of length secondLen starting at i
        vector<int> secondFrom(n - secondLen + 1);
        currentSum = 0;
        for (int i = 0; i < secondLen; ++i) currentSum += nums[i];
        secondFrom[0] = currentSum;
        for (int i = 1; i < secondFrom.size(); ++i) {
            currentSum = currentSum - nums[i - 1] + nums[i + secondLen - 1];
            secondFrom[i] = currentSum;
        }

        // 2. Calculate Suffix Maximums
        // maxFirstFrom[i] = max(firstFrom[j]) for j >= i
        vector<int> maxFirstFrom(firstFrom.size());
        maxFirstFrom.back() = firstFrom.back();
        for (int i = firstFrom.size() - 2; i >= 0; --i) {
            maxFirstFrom[i] = max(firstFrom[i], maxFirstFrom[i + 1]);
        }

        // maxSecondFrom[i] = max(secondFrom[j]) for j >= i
        vector<int> maxSecondFrom(secondFrom.size());
        maxSecondFrom.back() = secondFrom.back();
        for (int i = secondFrom.size() - 2; i >= 0; --i) {
            maxSecondFrom[i] = max(secondFrom[i], maxSecondFrom[i + 1]);
        }

        int ans = 0;

        // 3. Iterate and find the max sum
        // Case 1: First subarray (starts at i) comes before Second subarray
        // The second subarray must start at or after i + firstLen
        // Valid i range: i + firstLen < secondFrom.size() (meaning i + firstLen is a valid index in secondFrom/maxSecondFrom)
        // Actually, simpler: i + firstLen <= n - secondLen
        for (int i = 0; i <= n - firstLen - secondLen; ++i) {
            ans = max(ans, firstFrom[i] + maxSecondFrom[i + firstLen]);
        }

        // Case 2: Second subarray (starts at i) comes before First subarray
        // The first subarray must start at or after i + secondLen
        for (int i = 0; i <= n - secondLen - firstLen; ++i) {
            ans = max(ans, secondFrom[i] + maxFirstFrom[i + secondLen]);
        }

        return ans;
    }
};