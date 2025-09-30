/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 */

// Brief, Digested Understanding:
//
// The problem asks us to find the subtree sum(s) that appear most frequently in
// a given binary tree. A subtree sum is the sum of all node values in the
// subtree rooted at a particular node (including the node itself). We need to
// compute the subtree sum for every node, count how often each sum occurs, and
// return all sums that have the highest frequency.
//
// High-Level Summary:
//
// The solution uses a post-order traversal (left, right, root) to compute the
// subtree sum for each node recursively. As we compute each sum, we record its
// frequency in a hash map (unordered_map). After traversing the entire tree, we
// find the maximum frequency and collect all sums that occur with this
// frequency. The time complexity is O(N), where N is the number of nodes, since
// each node is visited once. The space complexity is O(N) for storing the
// frequency map and the result vector.

#include <algorithm>     // For std::max.
#include <unordered_map> // For std::unordered_map to count frequencies.
#include <vector>        // For std::vector to store the result.

using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to find the most frequent subtree sum(s).
  vector<int> findFrequentTreeSum(TreeNode *root) {
    // Edge case: if the tree is empty, return an empty vector.
    if (!root)
      return {};

    // Map to store the frequency of each subtree sum.
    unordered_map<int, int> sumFreq;
    // Variable to keep track of the maximum frequency seen so far.
    int maxFreq = 0;

    // Helper function to compute subtree sums recursively.
    computeSubtreeSums(root, sumFreq, maxFreq);

    // Collect all sums that have the maximum frequency.
    vector<int> result;
    for (const auto &entry : sumFreq) {
      if (entry.second == maxFreq) {
        result.push_back(entry.first);
      }
    }
    return result;
  }

private:
  // Helper function to compute the subtree sum for a given node.
  // It updates the frequency map and the maximum frequency.
  int computeSubtreeSums(TreeNode *node, unordered_map<int, int> &sumFreq,
                         int &maxFreq) {
    // Base case: if the node is null, its sum is 0.
    if (!node)
      return 0;

    // Recursively compute the sum of the left subtree.
    int leftSum = computeSubtreeSums(node->left, sumFreq, maxFreq);
    // Recursively compute the sum of the right subtree.
    int rightSum = computeSubtreeSums(node->right, sumFreq, maxFreq);

    // The subtree sum for this node is its value plus left and right sums.
    int currSum = node->val + leftSum + rightSum;

    // Update the frequency of this sum in the map.
    int freq = ++sumFreq[currSum];

    // Update the maximum frequency if needed.
    if (freq > maxFreq) {
      maxFreq = freq;
    }

    // Return the current subtree sum to the parent call.
    return currSum;
  }
};
// @lc code=end
