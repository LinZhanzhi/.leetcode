/*
Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:

Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.



Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.
Example 2:

Input: nums = [9,6,1,6,2]
Output: 4


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
*/
class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        // two possible zigzag patterns, we can calculate the moves for both patterns and return the minimum of the two.
        int n = nums.size();
        int moves1 = 0; // for pattern 1: even-indexed elements are greater than adjacent elements
        int moves2 = 0; // for pattern 2: odd-indexed elements are greater than adjacent elements

        // calculate moves for pattern 1
        //  for each odd index, we need to decrease it to be less than its adjacent elements.
        for (int i = 1; i < n; i += 2)
        {
            int left = nums[i - 1];
            int right = (i + 1 < n) ? nums[i + 1] : INT_MAX; // if there is no right adjacent element, we can consider it as infinity.
            int target = min(left, right) - 1;               // we need to decrease nums[i] to be less than both left and right, so the target value is min(left, right) - 1.
            if (nums[i] > target)
            {
                moves1 += nums[i] - target; // the moves needed to decrease nums[i] to target is nums[i] - target.
            }
        }

        // calculate moves for pattern 2
        // for each even index, we need to decrease it to be less than its adjacent elements.
        for (int i = 0; i < n; i += 2)
        {
            int left = (i - 1 >= 0) ? nums[i - 1] : INT_MAX; // if there is no left adjacent element, we can consider it as infinity.
            int right = (i + 1 < n) ? nums[i + 1] : INT_MAX; // if there is no right adjacent element, we can consider it as infinity.
            int target = min(left, right) - 1;               // we need to decrease nums[i] to be less than both left and right, so the target value is min(left, right) - 1.
            if (nums[i] > target)
            {
                moves2 += nums[i] - target; // the moves needed to decrease nums[i] to target is nums[i] - target.
            }
        }

        return min(moves1, moves2);
    }
};