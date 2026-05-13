/*
You are given an integer array nums consisting only of 0, 1, and 2.

A pair of indices (i, j) is called valid if nums[i] == 1 and nums[j] == 2.

Return the minimum absolute difference between i and j among all valid pairs. If no valid pair exists, return -1.

The absolute difference between indices i and j is defined as abs(i - j).



Example 1:

Input: nums = [1,0,0,2,0,1]

Output: 2

Explanation:

The valid pairs are:

(0, 3) which has absolute difference of abs(0 - 3) = 3.
(5, 3) which has absolute difference of abs(5 - 3) = 2.
Thus, the answer is 2.

Example 2:

Input: nums = [1,0,1,0]

Output: -1

Explanation:

There are no valid pairs in the array, thus the answer is -1.



Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 2
*/
class Solution
{
public:
    int minAbsoluteDifference(vector<int> &nums)
    {
        // check all pairs, if it is (1,2) or (2,1), try to update min absolute difference
        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((nums[i] == 1 && nums[j] == 2) || (nums[i] == 2 && nums[j] == 1))
                {
                    minDiff = min(minDiff, abs(i - j));
                }
            }
        }
        return minDiff == INT_MAX ? -1 : minDiff;
    }
};