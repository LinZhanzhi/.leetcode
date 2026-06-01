/*
Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.



Example 1:

Input: piles = [2,7,9,4,4]

Output: 10

Explanation:

If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:

Input: piles = [1,2,3,4,5,100]

Output: 104



Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104
*/
class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp[i][M] represents the maximum number of stones the current player can get starting from the i-th pile with M.

        // we can calculate the suffix sum of piles to get the total number of stones from the i-th pile to the end, which is useful for calculating dp[i][M].
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // we can fill the dp table from the end to the beginning, because dp[i][M] depends on dp[j][max(M, j - i)] for j > i.
        for (int i = n - 1; i >= 0; i--)
        {
            for (int M = 1; M <= n; M++)
            {
                // we can take X piles where 1 <= X <= 2M, so we need to iterate through all possible X.
                for (int X = 1; X <= 2 * M && i + X <= n; X++)
                {
                    // if we take X piles, then the opponent can get dp[i + X][max(M, X)], so we need to subtract that from the total stones to get our stones.
                    dp[i][M] = max(dp[i][M], suffixSum[i] - dp[i + X][max(M, X)]);
                }
            }
        }

        return dp[0][1]; // the answer is the maximum number of stones Alice can get starting from the first pile with M = 1.
    }
};