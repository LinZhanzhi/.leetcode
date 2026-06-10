/*
Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.



Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.
Example 3:

Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).


Constraints:

1 <= nums.length <= 4 * 104
1 <= nums[i] <= 104
*/
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int sum = 0;
        vector<int> mod1, mod2;
        for (int num : nums)
        {
            sum += num;
            if (num % 3 == 1)
                mod1.push_back(num);
            else if (num % 3 == 2)
                mod2.push_back(num);
        }
        sort(mod1.begin(), mod1.end());
        sort(mod2.begin(), mod2.end());

        if (sum % 3 == 0)
            return sum;

        else if (sum % 3 == 1)
        {
            int option1 = sum - (mod1.empty() ? INT_MAX : mod1[0]);
            int option2 = sum - (mod2.size() < 2 ? INT_MAX : mod2[0] + mod2[1]);
            return max(option1, option2);
        }
        else
        {
            int option1 = sum - (mod2.empty() ? INT_MAX : mod2[0]);
            int option2 = sum - (mod1.size() < 2 ? INT_MAX : mod1[0] + mod1[1]);
            return max(option1, option2);
        }
    }
};