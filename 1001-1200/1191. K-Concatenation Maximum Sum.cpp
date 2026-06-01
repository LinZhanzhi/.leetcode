/*
Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.

As the answer can be very large, return the answer modulo 10^9 + 7.



Example 1:

Input: arr = [1,2], k = 3
Output: 9
Example 2:

Input: arr = [1,-2,1], k = 5
Output: 2
Example 3:

Input: arr = [-1,-2], k = 7
Output: 0


Constraints:

1 <= arr.length <= 105
1 <= k <= 105
-104 <= arr[i] <= 104
*/
/*
Hint 1
How to solve the problem for k=1 ?
Hint 2
Use Kadane's algorithm for k=1.
Hint 3
What are the possible cases for the answer ?
Hint 4
The answer is the maximum between, the answer for k=1, the sum of the whole array multiplied by k, or the maximum suffix sum plus the maximum prefix sum plus (k-2) multiplied by the whole array sum for k > 1.
*/
class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        const int MOD = 1e9 + 7;
        long long maxSum = 0, currentSum = 0, totalSum = 0;
        for (int num : arr)
        {
            currentSum = max((long long)num, currentSum + num);
            maxSum = max(maxSum, currentSum);
            totalSum += num;
        }
        if (k == 1)
        {
            return maxSum % MOD;
        }
        long long prefixMax = 0, suffixMax = 0, prefixSum = 0, suffixSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            prefixSum += arr[i];
            prefixMax = max(prefixMax, prefixSum);
            suffixSum += arr[arr.size() - 1 - i];
            suffixMax = max(suffixMax, suffixSum);
        }
        if (totalSum > 0)
        {
            return max(maxSum, prefixMax + suffixMax + (k - 2) * totalSum) % MOD;
        }
        else
        {
            return max(maxSum, prefixMax + suffixMax) % MOD;
        }
    }
};