/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.



Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
Example 2:

Input: stones = [31,26,33,21,40]
Output: 5


Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 100
*/
/*
Explain solution:
The problem can be reduced to finding two subsets of the stones that have the smallest possible difference in their sums.
This is because when we smash two stones together, we are essentially trying to balance the two subsets to minimize the remaining stone's weight.
To solve this, we can use a dynamic programming approach similar to the subset sum problem. We want to find the largest sum of a subset of stones that is less than or equal to half of the total sum of all stones.
This is because if we can find a subset that sums up to half of the total, the other subset will also sum up to half, resulting in a difference of zero.

The steps to solve the problem are as follows:
1. Calculate the total sum of all stones.
2. Set a target as half of the total sum.
3. Use a boolean dynamic programming array `dp` where `dp[j]` indicates whether a subset of stones can sum up to `j`.
4. Initialize `dp[0]` to true, since a sum of zero can always be achieved with an empty subset.
5. Iterate through each stone and update the `dp` array in reverse order to avoid overwriting results that we still need to check.
6. After processing all stones, find the largest `j` such that `dp[j]` is true, which means we can achieve that sum with a subset of stones.
7. The answer will be the total sum minus twice that largest `j`, which gives us the smallest possible weight of the left stone.
*/
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (int stone : stones)
        {
            sum += stone;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int stone : stones)
        {
            for (int j = target; j - stone >= 0; j--)
            {
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        for (int i = target; i >= 0; i--)
        {
            if (dp[i])
            {
                return sum - 2 * i;
            }
        }

        return 0;
    }
};