/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.



Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> oddIndex;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 1)
            {
                oddIndex.push_back(i);
            }
        }
        int m = oddIndex.size();
        if (m < k)
        {
            return 0;
        }
        int ans = 0;

        for (int i = 0; i <= m - k; i++)
        {
            int leftCount = (i == 0) ? oddIndex[i] + 1 : oddIndex[i] - oddIndex[i - 1];
            int rightCount = (i + k - 1 == m - 1) ? n - oddIndex[i + k - 1] : oddIndex[i + k] - oddIndex[i + k - 1];
            ans += leftCount * rightCount;
        }
        return ans;
    }
};