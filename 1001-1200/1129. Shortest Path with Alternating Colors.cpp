/*
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.



Example 1:

Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]
Example 2:

Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
Output: [0,1,-1]


Constraints:

1 <= n <= 100
0 <= redEdges.length, blueEdges.length <= 400
redEdges[i].length == blueEdges[j].length == 2
0 <= ai, bi, uj, vj < n
*/
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        /*
        explain solution here
        solution is to use breadth first search (BFS) to find the shortest path from node 0 to all other nodes while alternating edge colors.
        We will maintain two queues, one for red edges and one for blue edges, and we will also maintain a visited array to keep track of which nodes have been visited with which edge color.
        We will start from node 0 and add it to both queues with a distance of 0. Then we will alternate between the two queues, processing all nodes in one queue before moving to the other queue.
        For each node processed, we will add its neighbors to the appropriate queue based on the edge color and update their distances if they have not been visited with that edge color before.

        */
        vector<vector<int>> graph(n);
        for (const auto &edge : redEdges)
        {
            graph[edge[0]].push_back(edge[1] * 2); // Red edges are represented as even numbers
        }
        for (const auto &edge : blueEdges)
        {
            graph[edge[0]].push_back(edge[1] * 2 + 1); // Blue edges are represented as odd numbers
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false)); // visited[node][color]

        queue<pair<int, int>> q; // pair of (node, color)
        q.push({0, 1}); // Start with node 0 and red edge
        // q.push({0, 0}); // Start with node 0 and blue edge
        // visited[0][0] = true;
        visited[0][1] = true;
        answer[0] = 0;

        while (!q.empty())
        {
            auto [node, color] = q.front();
            q.pop();
            int nextColor = 1 - color; // Alternate color

            for (int neighbor : graph[node])
            {
                if ((neighbor % 2) == nextColor && !visited[neighbor / 2][nextColor])
                {
                    visited[neighbor / 2][nextColor] = true;
                    if (answer[neighbor / 2] == -1)
                    {
                        answer[neighbor / 2] = answer[node] + 1;
                    }
                    else
                    {
                        answer[neighbor / 2] = min(answer[neighbor / 2], answer[node] + 1);
                    }
                    q.push({neighbor / 2, nextColor});
                }
            }
        }

        return answer;
    }
};