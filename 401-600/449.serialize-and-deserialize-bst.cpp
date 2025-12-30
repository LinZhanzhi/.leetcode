/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to convert a Binary Search Tree (BST) into a compact string
 * (serialization) and then reconstruct the exact same BST from that string
 * (deserialization). Serialization should be as compact as possible, and the
 * process must preserve the BST structure. The BST property (left < root <
 * right) can be leveraged to make the encoding and decoding efficient.
 *
 * High-Level Summary:
 * ----
 * We use preorder traversal (root, left, right) to serialize the BST into a
 * string of node values, separated by spaces. For deserialization, we
 * reconstruct the BST by reading the values in preorder, and for each value, we
 * use the BST property to determine the correct placement in the tree. This
 * approach is compact (no null markers needed) and efficient.
 *
 * - Serialization: O(N) time and O(N) space, where N is the number of nodes.
 * - Deserialization: O(N) time and O(N) space, using value bounds to
 * reconstruct the BST.
 */

#include <limits>
#include <sstream>
#include <string>
#include <vector>

using std::numeric_limits;
using std::string;
using std::stringstream;
using std::vector;

// Helper function to split a string by spaces into a vector of integers.
vector<int> splitToInts(const string &data) {
  vector<int> result;
  stringstream ss(data);
  string token;
  while (getline(ss, token, ' ')) {
    if (!token.empty()) {
      result.push_back(std::stoi(token));
    }
  }
  return result;
}

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    // Use preorder traversal to serialize the BST.
    vector<int> vals;
    preorder(root, vals);
    // Convert the vector of values to a space-separated string.
    return join(vals, ' ');
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    // Convert the string back to a vector of integers.
    vector<int> vals = splitToInts(data);
    int idx =
        0; // Index to track the current position in vals during recursion.
    // Use value bounds to reconstruct the BST efficiently.
    return buildBST(vals, idx, numeric_limits<int>::min(),
                    numeric_limits<int>::max());
  }

private:
  // Helper function: Preorder traversal to collect node values.
  void preorder(TreeNode *node, vector<int> &vals) {
    if (!node)
      return;
    vals.push_back(node->val);   // Visit root.
    preorder(node->left, vals);  // Visit left subtree.
    preorder(node->right, vals); // Visit right subtree.
  }

  // Helper function: Join vector of ints into a string with a given delimiter.
  string join(const vector<int> &vals, char delim) {
    if (vals.empty())
      return "";
    stringstream ss;
    for (size_t i = 0; i < vals.size(); ++i) {
      if (i > 0)
        ss << delim;
      ss << vals[i];
    }
    return ss.str();
  }

  // Helper function: Recursively build BST from preorder values using value
  // bounds.
  TreeNode *buildBST(const vector<int> &vals, int &idx, int lower, int upper) {
    // If all values are used or the current value is out of bounds, return
    // nullptr.
    if (idx >= vals.size() || vals[idx] < lower || vals[idx] > upper) {
      return nullptr;
    }
    int val = vals[idx++];
    // Create the current node.
    TreeNode *node = new TreeNode(val);
    // All values for the left subtree must be < val.
    node->left = buildBST(vals, idx, lower, val - 1);
    // All values for the right subtree must be > val.
    node->right = buildBST(vals, idx, val + 1, upper);
    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
