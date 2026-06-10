/*
Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

Return the two integers in any order.



Example 1:

Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
Example 2:

Input: num = 123
Output: [5,25]
Example 3:

Input: num = 999
Output: [40,25]


Constraints:

1 <= num <= 10^9
*/
class Solution
{
public:
    vector<int> closestDivisors(int num)
    {
        auto findClosestDivisors = [](int n) -> vector<int>
        {
            int sqrtN = sqrt(n);
            for (int i = sqrtN; i > 0; --i)
            {
                if (n % i == 0)
                {
                    return {i, n / i};
                }
            }
            return {};
        };

        vector<int> div1 = findClosestDivisors(num + 1);
        vector<int> div2 = findClosestDivisors(num + 2);

        return abs(div1[0] - div1[1]) < abs(div2[0] - div2[1]) ? div1 : div2;
    }
};