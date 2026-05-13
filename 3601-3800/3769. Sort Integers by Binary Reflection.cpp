/*
You are given an integer array nums.

The binary reflection of a positive integer is defined as the number obtained by reversing the order of its binary digits (ignoring any leading zeros) and interpreting the resulting binary number as a decimal.

Sort the array in ascending order based on the binary reflection of each element. If two different numbers have the same binary reflection, the smaller original number should appear first.

Return the resulting sorted array.



Example 1:

Input: nums = [4,5,4]

Output: [4,4,5]

Explanation:

Binary reflections are:

4 -> (binary) 100 -> (reversed) 001 -> 1
5 -> (binary) 101 -> (reversed) 101 -> 5
4 -> (binary) 100 -> (reversed) 001 -> 1
Sorting by the reflected values gives [4, 4, 5].
Example 2:

Input: nums = [3,6,5,8]

Output: [8,3,6,5]

Explanation:

Binary reflections are:

3 -> (binary) 11 -> (reversed) 11 -> 3
6 -> (binary) 110 -> (reversed) 011 -> 3
5 -> (binary) 101 -> (reversed) 101 -> 5
8 -> (binary) 1000 -> (reversed) 0001 -> 1
Sorting by the reflected values gives [8, 3, 6, 5].
Note that 3 and 6 have the same reflection, so we arrange them in increasing order of original value.


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 109
*/
class Solution
{
public:
    // method to calculate the binary reflection of a number
    int binaryReflection(int num)
    {
        int reflection = 0;
        while (num > 0)
        {
            reflection = (reflection << 1) | (num & 1);
            num >>= 1;
        }
        return reflection;
    }
    vector<int> sortByReflection(vector<int> &nums)
    {
        vector<pair<int, int>> reflections;
        for (int num : nums)
        {
            int reflection = binaryReflection(num);
            reflections.emplace_back(reflection, num);
        }
        sort(reflections.begin(), reflections.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first == b.first)
                 {
                     return a.second < b.second; // Sort by original number if reflections are equal
                 }
                 return a.first < b.first; // Sort by reflection
             });
        vector<int> sortedNums;
        for (const auto &p : reflections)
        {
            sortedNums.push_back(p.second);
        }
        return sortedNums;
    }
};