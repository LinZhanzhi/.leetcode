/*
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.



Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20


Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
*/
class Solution
{
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int maxVal = 0;
        for (int sign1 : {1, -1})
        {
            for (int sign2 : {1, -1})
            {
                int maxSum = INT_MIN;
                int minSum = INT_MAX;
                for (int i = 0; i < arr1.size(); ++i)
                {
                    int sum = sign1 * arr1[i] + sign2 * arr2[i] + i;
                    maxSum = max(maxSum, sum);
                    minSum = min(minSum, sum);
                }
                maxVal = max(maxVal, maxSum - minSum);
            }
        }
        return maxVal;
    }
};