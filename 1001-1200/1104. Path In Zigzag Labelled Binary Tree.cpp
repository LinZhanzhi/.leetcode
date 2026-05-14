/*
In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.



Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.



Example 1:

Input: label = 14
Output: [1,3,4,14]
Example 2:

Input: label = 26
Output: [1,2,6,10,26]


Constraints:

1 <= label <= 10^6
*/
class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        // do this repetitively until we reach the root.
        // 1. add current label to the result
        // 2. get true label of current node
        // 3. get true label of its parent
        // 4. get label of the parent
        // 5. repeat until we reach the root
        // when this end, we get the labels from the node to the root, we just need to reverse it to get the path from root to the node.
        vector<int> res;
        while (label > 0)
        {
            res.push_back(label);
            int trueLabel = getTrueLabel(label);
            int parentTrueLabel = trueLabel / 2;
            label = getLabel(parentTrueLabel);
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    // get level of a label. root is level 1, its children are level 2, and so on.
    // root m's label range is [2^(m-1), 2^m - 1]
    int getLevel(int label)
    {
        int level = 0, n = label;
        while (n > 0)
        {
            n /= 2;
            level++;
        }
        return level;
    }
    // define true label of a node in zigzag tree.
    // for odd level, true label is the same as label
    // for even level, true label is the mirror of label in the level.
    int getTrueLabel(int label)
    {
        int level = getLevel(label);
        if (level % 2 == 1)
            return label;
        int levelStart = pow(2, level - 1), levelEnd = pow(2, level) - 1;
        return levelStart + levelEnd - label;
    }
    // get label from true label.
    // for odd level, label is the same as true label
    // for even level, label is the mirror of true label in the level.
    int getLabel(int trueLabel)
    {
        int level = getLevel(trueLabel);
        if (level % 2 == 1)
            return trueLabel;
        int levelStart = pow(2, level - 1), levelEnd = pow(2, level) - 1;
        return levelStart + levelEnd - trueLabel;
    }
};