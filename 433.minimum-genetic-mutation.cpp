/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given two gene strings (startGene and endGene) and a list of valid
 * gene strings (bank). Each gene string is 8 characters long, using only 'A',
 * 'C', 'G', and 'T'. A mutation is a change of a single character in the gene
 * string, and every intermediate gene string must be present in the bank to be
 * considered valid. The goal is to find the minimum number of single-character
 * mutations needed to transform startGene into endGene, using only valid gene
 * strings from the bank. If it's not possible, return -1.
 *
 * High-Level Summary:
 * ----
 * The problem is a classic shortest-path search in an unweighted graph, where
 * each node is a gene string, and an edge exists between two nodes if they
 * differ by exactly one character and the target is in the bank. We use
 * Breadth-First Search (BFS) to explore all possible mutations level by level,
 * starting from startGene. At each step, we generate all possible valid
 * mutations (by changing one character at a time to 'A', 'C', 'G', or 'T'), and
 * if a mutation is in the bank and hasn't been visited, we add it to the BFS
 * queue. We keep track of the number of mutation steps taken. The BFS ensures
 * that the first time we reach endGene, it is with the minimum number of
 * mutations. Time Complexity: O(N * L * 4), where N is the number of genes in
 * the bank, L is the gene length (8), and 4 is the number of possible
 * characters. Space Complexity: O(N), for the visited set and the queue.
 */

#include <queue>         // For std::queue (BFS)
#include <string>        // For std::string
#include <unordered_set> // For std::unordered_set (fast lookup for bank and visited)
#include <vector>        // For std::vector

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
  // Function to find the minimum number of mutations from startGene to endGene
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    // Store all valid gene strings from the bank in an unordered_set for O(1)
    // lookup
    unordered_set<string> bankSet(bank.begin(), bank.end());
    // If the endGene is not in the bank, it's impossible to reach it
    if (bankSet.find(endGene) == bankSet.end()) {
      return -1;
    }

    // Characters allowed in a gene string
    const char genes[4] = {'A', 'C', 'G', 'T'};

    // Queue for BFS: each element is a pair (current gene string, number of
    // mutations so far)
    queue<std::pair<string, int>> q;
    // Set to keep track of visited gene strings to avoid revisiting
    unordered_set<string> visited;

    // Start BFS from the startGene with 0 mutations
    q.push({startGene, 0});
    visited.insert(startGene);

    // BFS loop
    while (!q.empty()) {
      auto [current, steps] = q.front();
      q.pop();

      // If we've reached the endGene, return the number of steps (mutations)
      if (current == endGene) {
        return steps;
      }

      // Try mutating each position in the current gene string
      for (int i = 0; i < 8; ++i) { // Each gene string has length 8
        char original = current[i]; // Save the original character
        // Try all possible gene characters at position i
        for (char g : genes) {
          if (g == original)
            continue;     // Skip if the character is the same
          current[i] = g; // Mutate the character

          // If the mutated gene is in the bank and not visited yet
          if (bankSet.find(current) != bankSet.end() &&
              visited.find(current) == visited.end()) {
            q.push({current,
                    steps + 1}); // Add to BFS queue with incremented step count
            visited.insert(current); // Mark as visited
          }
        }
        current[i] =
            original; // Restore the original character for the next iteration
      }
    }

    // If BFS completes without finding endGene, return -1 (not possible)
    return -1;
  }
};
// @lc code=end
