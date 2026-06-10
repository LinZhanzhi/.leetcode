/*
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.



Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14.
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.
Step 5) 4 is even, divide by 2 and obtain 2.
Step 6) 2 is even, divide by 2 and obtain 1.
Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corresponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.
Example 3:

Input: s = "1"
Output: 0


Constraints:

1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'
*/
class Solution
{
public:
    int numSteps(string s)
    {
        int steps = 0;
        int carry = 0; // to handle the addition of 1 when the number is odd
        for (int i = s.size() - 1; i > 0; i--)
        {
            int bit = s[i] - '0' + carry;
            if (bit % 2 == 0)
            {
                // even, just divide by 2
                steps++;
                carry = bit  / 2 ; // no carry needed for even numbers
            }
            else
            {
                // odd, add 1 and then divide by 2
                steps += 2; // one step for adding 1 and one step for dividing by 2
                carry = 1; // we need to carry over the addition of 1 to the next bit
            }
        }
        // if there is a carry left after processing all bits, we need one more step to handle it
        if (carry == 1)
        {
            steps++;
        }
        return steps;
    }
};