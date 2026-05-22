/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.



Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44


Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
*/
class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        /*
        explain solution here
        solution is to use dynamic programming to solve the problem.
        We will create two 2D arrays, dp and maxLeaf, where dp[i][j] will store the minimum cost of the tree formed by the subarray arr[i...j], and maxLeaf[i][j] will store the maximum leaf value in the subarray arr[i...j].
        We will fill these arrays in a bottom-up manner.
        For each length of the subarray, we will iterate through all possible starting indices and calculate the cost of the tree formed by the subarray.
        The cost will be the sum of the cost of the left and right subtrees plus the product of the maximum leaf values in the left and right subtrees.

        */
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> maxLeaf(n, vector<int>(n, 0));

        // Initialize the maxLeaf array for single elements
        for (int i = 0; i < n; i++)
        {
            maxLeaf[i][i] = arr[i];
        }

        // Fill the dp and maxLeaf arrays for subarrays of length greater than 1
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                // Calculate the cost of the tree formed by the subarray arr[i...j] by trying all possible splits
                for (int k = i; k < j; k++)
                {
                    int cost = dp[i][k] + dp[k + 1][j] + maxLeaf[i][k] * maxLeaf[k + 1][j];
                    dp[i][j] = min(dp[i][j], cost);
                    maxLeaf[i][j] = max(maxLeaf[i][j], max(maxLeaf[i][k], maxLeaf[k + 1][j]));
                }
            }
        }

        // The answer will be in dp[0][n - 1], which represents the minimum cost of the tree formed by the entire array.
        return dp[0][n - 1];
    }
};