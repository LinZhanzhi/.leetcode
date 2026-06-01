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
        original nodes are labeled from 0 to n -1
        as a node can be reached by either a red edge or a blue edge, we can create two nodes for each original node, one for red and one for blue
        if original node label is i . its red node will be labeled as 2*i and blue node will be labeled as 2*i + 1
        and we enforce the rule tha t we can only go from a red node to a blue node and from a blue node to a red node when we build the adjacent list

        so red edge from node i to node j is from blue node of node i to red node of node j , which is from 2*i + 1 to 2*j
        and blue edge from node i to node j is from red node of node i to blue node of node j , which is from 2*i to 2*j + 1
        and we use bfs starting from the red node and blue node of the original node 0 to find the shortest path to all other nodes
        */
        vector<vector<int>> adj(2 * n);
        for (auto &edge : redEdges)
        {
            adj[2 * edge[0] + 1].push_back(2 * edge[1]);
        }
        for (auto &edge : blueEdges)
        {
            adj[2 * edge[0]].push_back(2 * edge[1] + 1);
        }
        vector<int> dist(2 * n, -1);
        queue<int> q;
        dist[0] = 0; // distance to red node of original node 0 is 0
        dist[1] = 0; // distance to blue node of original node 0 is 0
        q.push(0); // start bfs from red node of original node 0
        q.push(1); // start bfs from blue node of original node 0
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node])
            {
                if (dist[neighbor] == -1)
                {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i)
        {
            int redDist = dist[2 * i];
            int blueDist = dist[2 * i + 1];
            if (redDist != -1 && blueDist != -1)
            {
                result[i] = min(redDist, blueDist);
            }
            else if (redDist != -1)
            {
                result[i] = redDist;
            }
            else if (blueDist != -1)
            {
                result[i] = blueDist;
            }
        }
        return result;
    }
};