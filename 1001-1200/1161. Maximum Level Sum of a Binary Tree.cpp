/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.



Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2


Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
*/
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
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {

        if (!root)
        {
            return 0; // if the tree is empty, we can return 0 as there are no levels.
        }

        int maxSum = root->val; // initialize maxSum with the value of the root node, as the minimum level sum is at least the value of the root node.
        int maxLevel = 1;       // initialize maxLevel with 1, as the minimum level is 1.
        int currentLevel = 1;   // initialize currentLevel with 1, as we start from the root node.

        queue<TreeNode *> q; // we can use a queue to perform a level order traversal of the tree.
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size(); // get the number of nodes at the current level.
            int levelSum = 0;         // initialize levelSum for the current level.

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                levelSum += node->val; // add the value of the current node to levelSum.

                if (node->left)
                {
                    q.push(node->left); // add left child to the queue if it exists.
                }
                if (node->right)
                {
                    q.push(node->right); // add right child to the queue if it exists.
                }
            }

            if (levelSum > maxSum)
            {
                maxSum = levelSum;     // update maxSum if we found a larger sum at this level.
                maxLevel = currentLevel; // update maxLevel to the current level.
            }

            currentLevel++; // move to the next level.
        }

        return maxLevel; // return the level with the maximum sum.
    }
};