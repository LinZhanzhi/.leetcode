/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.



Example 1:


Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
Example 2:


Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)


Constraints:

The number of nodes in the tree is in the range [2, 5 * 104].
1 <= Node.val <= 104
*/
class Solution
{
public:
    int maxProduct(TreeNode *root)
    {
        // get sum of whole tree
        // get sum of each subtree
        // get max product
        long long sum = 0, maxProd = 0;
        const int mod = 1e9 + 7;
        function<long long(TreeNode *)> dfs = [&](TreeNode *node) -> long long
        {
            if (!node)
                return 0;
            long long leftSum = dfs(node->left);
            long long rightSum = dfs(node->right);
            long long totalSum = leftSum + rightSum + node->val;
            maxProd = max(maxProd, totalSum * (sum - totalSum));
            return totalSum;
        };
        sum = dfs(root);
        dfs(root);
        return maxProd % mod;
    }
};