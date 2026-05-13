/*
You are given an integer array nums.

An element nums[i] is considered valid if it satisfies at least one of the following conditions:

It is strictly greater than every element to its left.
It is strictly greater than every element to its right.
The first and last elements are always valid.

Return an array of all valid elements in the same order as they appear in nums.



Example 1:

Input: nums = [1,2,4,2,3,2]

Output: [1,2,4,3,2]

Explanation:

nums[0] and nums[5] are always valid.
nums[1] and nums[2] are strictly greater than every element to their left.
nums[4] is strictly greater than every element to its right.
Thus, the answer is [1, 2, 4, 3, 2].
Example 2:

Input: nums = [5,5,5,5]

Output: [5,5]

Explanation:

The first and last elements are always valid.
No other elements are strictly greater than all elements to their left or to their right.
Thus, the answer is [5, 5].
Example 3:

Input: nums = [1]

Output: [1]

Explanation:

Since there is only one element, it is always valid. Thus, the answer is [1].



Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
class Solution
{
public:
    vector<int> findValidElements(vector<int> &nums)
    {
        // if only one element, return it
        if (nums.size() == 1)
            return nums;
        // if only two elements, return both
        if (nums.size() == 2)
            return nums;
        // get the maximum element of the vector, and its index
        int max = *max_element(nums.begin(), nums.end());
        int maxIndex = distance(nums.begin(), max_element(nums.begin(), nums.end()));
        // for elements in nums[1, maxIndex), if they are greater than the maximum element to their left, add them to the result vector
        vector<int> result;
        for (int i = 1; i <= min(maxIndex, (int)nums.size() - 2); i++)
        {
            if (nums[i] > *max_element(nums.begin(), nums.begin() + i))
                result.push_back(nums[i]);
        }
        // for elements in nums[maxIndex + 1, nums.size() - 1), if they are greater than the maximum element to their right, add them to the result vector
        for (int i = maxIndex + 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > *max_element(nums.begin() + i + 1, nums.end()))
                result.push_back(nums[i]);
        }
        // add the first and last elements to the result vector
        result.insert(result.begin(), nums[0]);
        result.push_back(nums[nums.size() - 1]);
        return result;
    }
};