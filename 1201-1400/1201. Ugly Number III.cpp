/*
An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.



Example 1:

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.


Constraints:

1 <= n, a, b, c <= 109
1 <= a * b * c <= 1018
It is guaranteed that the result will be in range [1, 2 * 109].
*/
class Solution
{
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        // we can use binary search to find the nth ugly number
        // we can define a function that counts how many ugly numbers are less than or equal to a given number x
        // then we can use binary search to find the smallest number x such that the count of ugly numbers less than or equal to x is at least n
        auto count = [&](long long x)
        {
            // the count of ugly numbers less than or equal to x can be calculated using the inclusion-exclusion principle
            return x / a + x / b + x / c - x / lcm(a, b) - x / lcm(b, c) - x / lcm(a, c) + x / lcm(a, lcm(b, c));
        };
        long long left = 1, right = 2 * 1000000000;
        long long ans = 0;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (count(mid) < n)
            {
                left = mid + 1;
            }
            else
            {
                ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }
private:
    long long gcd(long long a, long long b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(b, a % b);
    }
    long long lcm(long long a, long long b)
    {
        return a / gcd(a, b) * b;
    }
};