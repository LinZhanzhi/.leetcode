/*
Two players play a turn based game on a binary tree. We are given the root of this binary tree, and the number of nodes n in the tree. n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x. The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player. In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn. If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player. If it is possible to choose such a y to ensure you win the game, return true. If it is not possible, return false.



Example 1:


Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
Output: true
Explanation: The second player can choose the node with value 2.
Example 2:

Input: root = [1,2,3], n = 3, x = 1
Output: false


Constraints:

The number of nodes in the tree is n.
1 <= x <= n <= 100
n is odd.
1 <= Node.val <= n
All the values of the tree are unique.
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
/*
what is the best strategy for the second player to win the game? -- given x and y are fixed.
if y is in the subtree of x, second player must first color parents of blue nodes, to gain more nodes.
why second player dont need to mind children of blue nodes ? because x is ancestor of y , and red node cannot spread to the subtree of y, so blue node can only spread to the subtree of y, and red node can only spread to the subtree of x, so they will never meet each other, so second player dont need to mind children of blue nodes.

if x is in the subtree of y , second player must first color nodes on the path from y to x, to gain more nodes, and to limit the spread of red nodes.

if x and y are not in the subtree of each other, both player must color parents of their colored nodes, to gain more nodes, and to limit the spread of the opponent's nodes.
*/
/*
what is the best strategy for the second player to win the game? -- given x is fixed, and y is not fixed.
if we want to place y in the subtree of x , then the most nodes we can get is the size of the bigger subtree of x, which is max(size of left subtree of x, size of right subtree of x).

if we want to place y as ancestor of x, then the most nodes we can get is n - size of subtree of x.

if we want to place y as non-ancestor and non-descendant of x, then to get the most nodes, we can place y as the child of the root node that doesn't contain x, then the most nodes we can get is uncertain but it is less than n - size of subtree of x because now first player can gain more nodes.

so to conclude, if x is not root of the tree, then second player should always place y as parent of x.
if x is root of the tree, then second player can place y as child of the root node, and the most nodes we can get is max(size of left subtree of x, size of right subtree of x).

*/
class Solution
{
public:
    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        TreeNode *xNode = findNode(root, x);
        // if y is in the subtree of x, then the most nodes we can get is the size of the bigger subtree of x
        int leftSize = getSize(xNode->left);
        int rightSize = getSize(xNode->right);
        int maxSubtreeSize = max(leftSize, rightSize);
        // if y is ancestor of x, then the most nodes we can get is n - size of subtree of x
        int parentSize = n - (leftSize + rightSize + 1);
        // take the best strategy and compare with n / 2, if we can get more than n / 2 nodes, then we can win the game
        return max(maxSubtreeSize, parentSize) > n / 2;
    }

private:
    TreeNode *findNode(TreeNode *root, int x)
    {
        if (!root)
            return nullptr;
        if (root->val == x)
            return root;
        TreeNode *left = findNode(root->left, x);
        if (left)
            return left;
        return findNode(root->right, x);
    }

    int getSize(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + getSize(root->left) + getSize(root->right);
    }
};