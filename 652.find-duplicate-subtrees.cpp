/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about finding all subtrees in a binary tree that are
 * structurally and value-wise identical to at least one other subtree in the
 * same tree. For each kind of duplicate subtree, we only need to return the
 * root node of one instance. The challenge is to efficiently detect and
 * identify these duplicate subtrees, considering both structure and node
 * values.
 *
 * High-Level Summary:
 * ----
 * The core idea is to uniquely encode (serialize) each subtree so that
 * identical subtrees have the same encoding. We use post-order traversal
 * (left, right, root) to serialize each subtree into a string that captures
 * both structure and values, including markers for null children. We use a
 * hash map to count how many times each serialization appears. When a
 * serialization appears for the second time, we add its root to the result.
 * The solution is modularized: the serialization logic is in a helper
 * function, and the main function manages the traversal and result
 * collection. Time complexity is O(N), where N is the number of nodes,
 * because each node is visited once and string operations are efficient due
 * to memoization. Space complexity is O(N) for the hash map and result
 * storage.
 */

#include <string>        // For std::string to represent serializations
#include <unordered_map> // For std::unordered_map to count serializations
#include <vector>        // For std::vector to store result nodes

using std::string;
using std::unordered_map;
using std::vector;

// The TreeNode struct is assumed to be defined as per the LeetCode template
// above.

class Solution {
public:
  // Main function to find all duplicate subtrees in the binary tree.
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    // Vector to store the root nodes of all duplicate subtrees found.
    vector<TreeNode *> result;
    // Hash map to map each subtree serialization to the number of times it has
    // been seen.
    unordered_map<string, int> subtreeCount;
    // Start the post-order traversal and serialization from the root.
    serializeSubtree(root, subtreeCount, result);
    return result;
  }

private:
  // Helper function to serialize a subtree rooted at 'node'.
  // Returns a string that uniquely represents the structure and values of the
  // subtree.
  string serializeSubtree(TreeNode *node,
                          unordered_map<string, int> &subtreeCount,
                          vector<TreeNode *> &result) {
    // Base case: If the node is null, represent it with a special marker (e.g.,
    // "#").
    if (!node) {
      return "#";
    }
    // Recursively serialize the left subtree.
    string leftSerial = serializeSubtree(node->left, subtreeCount, result);
    // Recursively serialize the right subtree.
    string rightSerial = serializeSubtree(node->right, subtreeCount, result);
    // Combine the current node's value and its left/right serializations into a
    // unique string. Commas are used to separate values to avoid ambiguity
    // (e.g., "11" vs. "1,1").
    // Although the serialization string is constructed as
    // "root value, left subtree, right subtree" (which matches the order of
    // preorder traversal in terms of string format), the actual traversal
    // performed by the code is post-order. This is because we first recursively
    // serialize the left and right subtrees (i.e., we visit left, then right,
    // then process the current node), and only after both recursive calls do we
    // combine the results with the current node's value. The string format
    // itself does not determine the traversal order—the order in which the
    // recursive calls are made does. So, this is post-order traversal.
    string serial =
        std::to_string(node->val) + "," + leftSerial + "," + rightSerial;
    // Increment the count for this serialization in the hash map.
    subtreeCount[serial]++;
    // If this is the second time we've seen this serialization, add the node to
    // the result. (We only add it once, when the count becomes 2.)
    if (subtreeCount[serial] == 2) {
      result.push_back(node);
    }
    // Return the serialization string to the parent call.
    return serial;
  }
};
// @lc code=end
