/*
Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not necessarily a number from arr.



Example 1:

Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
Example 2:

Input: arr = [2,3,5], target = 10
Output: 5
Example 3:

Input: arr = [60864,25176,27249,21296,20204], target = 56803
Output: 11361


Constraints:

1 <= arr.length <= 104
1 <= arr[i], target <= 105
*/
class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        int left = 0, right = *max_element(arr.begin(), arr.end());
        int minAbsDiff = INT_MAX, bestValue = 0;
        // sort
        sort(arr.begin(), arr.end());
        // calculate prefix sum array to optimize the time complexity of calculating the sum of the mutated array
        vector<long> prefixSum(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); ++i)
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long sum = 0;
            // for (int num : arr)
            //     sum += min(num, mid);
            // this sum can be accelerated by sorting the array and using binary search to find the first element greater than mid
            // and then calculate the sum of the elements before that and add mid * (number of elements after that)
            int idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
            // sum += accumulate(arr.begin(), arr.begin() + idx, 0);
            // accumulate can be replaced by a prefix sum array to further optimize the time complexity
            sum += prefixSum[idx];
            sum += (long)(arr.size() - idx) * mid;
            int absDiff = abs(sum - target);
            if (absDiff < minAbsDiff || (absDiff == minAbsDiff && mid < bestValue))
            {
                minAbsDiff = absDiff;
                bestValue = mid;
            }
            if (sum < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return bestValue;
    }
};