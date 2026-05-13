/**
 * You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.



Example 1:

Input: nums = [1,3,5,4,2,6]

Output: true

Explanation:

Pick p = 2, q = 4:

nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
nums[4...5] = [2, 6] is strictly increasing (2 < 6).
Example 2:

Input: nums = [2,1,3]

Output: false

Explanation:

There is no way to pick p and q to form the required three segments.



Constraints:

3 <= n <= 100
-1000 <= nums[i] <= 1000
 */
class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int n = nums.size();
        // if nums[1] <= nums[0], then we cannot find a valid p, so return false
        if (nums[1] <= nums[0])
        {
            return false;
        }
        // scan first strictly increasing segment, and find the first index p such that nums[p] <= nums[p - 1]
        int p = 1;
        while (p < n && nums[p] > nums[p - 1])
        {
            ++p;
        }
        // if p == n, then we cannot find a valid q, so return false
        if (p == n)
        {
            return false;
        }
        // scan strictly decreasing segment, and find the first index q such that nums[q] >= nums[q - 1]
        int q = p;
        while (q < n && nums[q] < nums[q - 1])
        {
            ++q;
        }
        // if q == n, then we cannot find a valid r, so return false
        if (q == n)
        {
            return false;
        }
        // scan last strictly increasing segment
        for (int i = q; i < n; ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};