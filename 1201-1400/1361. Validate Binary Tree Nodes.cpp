/*
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.



Example 1:


Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:


Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:


Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false


Constraints:

n == leftChild.length == rightChild.length
1 <= n <= 104
-1 <= leftChild[i], rightChild[i] <= n - 1
*/
class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        // just build the graph using adjacency list and check if there is only one root and no cycles
        // adjacency list
        vector<vector<int>> graph(n);
        // edge counter
        int edgeCount = 0;
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (leftChild[i] != -1)
            {
                graph[i].push_back(leftChild[i]);
                inDegree[leftChild[i]]++;
                edgeCount++;
            }
            if (rightChild[i] != -1)
            {
                graph[i].push_back(rightChild[i]);
                inDegree[rightChild[i]]++;
                edgeCount++;
            }
        }
        // edge count should be n - 1 for a valid binary tree
        if (edgeCount != n - 1)
        {
            return false;
        }

        // check if there is only one root
        int rootCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                rootCount++;
            }
        }
        if (rootCount != 1)
        {
            return false;
        }

        // check for cycles using DFS
        vector<bool> visited(n, false);
        vector<bool> onPath(n, false);
        function<bool(int)> dfs = [&](int node)
        {
            visited[node] = true;
            onPath[node] = true;
            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    if (!dfs(neighbor))
                        return false;
                }
                else if (onPath[neighbor])
                {
                    return false;
                }
            }
            onPath[node] = false;
            return true;
        };

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (!dfs(i))
                    return false;
            }
        }

        return true;
    }
};