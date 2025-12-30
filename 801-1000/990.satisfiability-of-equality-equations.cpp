/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given a set of equations involving variables 'a'-'z'.
 * The equations are either equality ("a==b") or inequality ("a!=b").
 * We need to determine if there is a valid assignment of values to variables that satisfies all equations.
 *
 * High-Level Summary:
 * -------------------
 * This problem can be modeled using the Union-Find (Disjoint Set Union - DSU) data structure.
 * 1. Equality (==) implies that two variables belong to the same connected component (set).
 * 2. Inequality (!=) implies that two variables must belong to different connected components.
 *
 * Algorithm:
 * 1. Initialize a Union-Find structure for the 26 lowercase letters.
 * 2. First pass: Process all equality equations ("x==y"). Union the sets containing x and y.
 * 3. Second pass: Process all inequality equations ("x!=y"). Check if x and y are in the same set.
 *    - If ind(x) == find(y), it's a contradiction (they must be different but are forced to be equal). Return false.
 * 4. If no contradictions are found after checking all inequalities, return true.
 *
 * Time Complexity: O(N * alpha(26)), where N is the number of equations and alpha is the inverse Ackermann function (nearly constant).
 * Space Complexity: O(1) (fixed size array for 26 characters).
 */

#include <vector>
#include <string>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
private:
    // Union-Find parent array
    int parent[26];

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union function
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

public:
    bool equationsPossible(vector<string>& equations) {
        // Initialize parent array where each node is its own parent
        iota(parent, parent + 26, 0);

        // First pass: Process all "==" equations
        for (const string& eq : equations) {
            if (eq[1] == '=') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                unite(x, y);
            }
        }

        // Second pass: Process all "!=" equations
        for (const string& eq : equations) {
            if (eq[1] == '!') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                // If they are in the same set, it's a contradiction
                if (find(x) == find(y)) {
                    return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end
