/**
 * Given an integer n, find the digit that occurs least frequently in its decimal representation. If multiple digits have the same frequency, choose the smallest digit.

Return the chosen digit as an integer.

The frequency of a digit x is the number of times it appears in the decimal representation of n.


Example 1:

Input: n = 1553322

Output: 1

Explanation:

The least frequent digit in n is 1, which appears only once. All other digits appear twice.

Example 2:

Input: n = 723344511

Output: 2

Explanation:

The least frequent digits in n are 7, 2, and 5; each appears only once.



Constraints:

1 <= n <= 2^31​​​​​​​ - 1
 */
class Solution
{
public:
    int getLeastFrequentDigit(int n)
    {
        vector<int> freq(10, 0);
        while (n > 0)
        {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }
        int minFreq = INT_MAX;
        int result = -1;
        for (int i = 0; i < 10; i++)
        {
            if (freq[i] > 0 && freq[i] < minFreq)
            {
                minFreq = freq[i];
                result = i;
            }
        }
        return result;
    }
};