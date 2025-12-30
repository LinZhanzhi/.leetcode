/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find the largest possible value that can be obtained
 * by XOR-ing any two numbers in a given array. XOR (exclusive OR) compares
 * each bit of two numbers and outputs 1 if the bits are different, and 0 if
 * they are the same. Our goal is to select two numbers from the array such
 * that their XOR is maximized.
 *
 * High-Level Summary:
 * ----
 * We use a Trie (prefix tree) to efficiently store the binary representations
 * of all numbers in the array. Each node in the Trie represents a bit (0 or 1).
 * For each number, we insert its bits into the Trie. Then, for each number,
 * we try to find another number in the Trie that, when XOR-ed with it, gives
 * the largest possible result. This is done by always trying to take the
 * opposite bit at each position (to maximize the XOR at that bit). The time
 * complexity is O(32 * n), where n is the number of elements (since each
 * number has up to 32 bits), and the space complexity is O(32 * n) for the
 * Trie.
 */

#include <algorithm> // For std::max
#include <vector>    // For std::vector to store the input array

using std::vector;

// @lc code=start
class Solution {
public:
  // Define the Trie data structure for storing binary representations
  class Trie {
  public:
    // Each node can have a left (0) and right (1) child
    struct Node {
      Node *left;  // Represents bit 0
      Node *right; // Represents bit 1
      Node() : left(nullptr), right(nullptr) {}
    };

    Node *root;

    Trie() { root = new Node(); }

    // Insert a number into the Trie, bit by bit from the highest (30) to lowest
    // (0)
    void insert(int val) {
      Node *curr = root;
      // We use 31 bits (from 30 down to 0) to cover all possible positive
      // integers
      for (int bitIndex = 30; bitIndex >= 0; --bitIndex) {
        int mask = 1 << bitIndex;       // Mask to extract the current bit
        int bit = (val & mask) ? 1 : 0; // Get the bit at bitIndex
        if (bit == 0) {
          // If the bit is 0, go left; create node if needed
          if (!curr->left)
            curr->left = new Node();
          curr = curr->left;
        } else {
          // If the bit is 1, go right; create node if needed
          if (!curr->right)
            curr->right = new Node();
          curr = curr->right;
        }
      }
    }

    // For a given number, find the number in the Trie that gives the maximum
    // XOR
    int query(int val) {
      Node *curr = root;
      int ans = 0;
      for (int bitIndex = 30; bitIndex >= 0; --bitIndex) {
        int mask = 1 << bitIndex;
        int bit = (val & mask) ? 1 : 0;
        // To maximize XOR, try to go the opposite direction if possible
        if (bit == 0) {
          // If current bit is 0, try to go right (1) for a 1 in XOR
          if (curr->right) {
            curr = curr->right;
            ans |= mask; // Set this bit in the answer
          } else {
            curr = curr->left; // Otherwise, go left (0)
          }
        } else {
          // If current bit is 1, try to go left (0) for a 1 in XOR
          if (curr->left) {
            curr = curr->left;
          } else {
            curr = curr->right; // Otherwise, go right (1)
            ans |= mask;        // Set this bit in the answer
          }
        }
      }
      return ans;
    }
  };

  // Main function to find the maximum XOR of any two numbers in the array
  int findMaximumXOR(vector<int> &nums) {
    Trie trie;
    // Insert all numbers into the Trie
    for (int val : nums) {
      trie.insert(val);
    }

    int maxResult = 0;
    // For each number, find the number in the Trie that gives the maximum XOR
    for (int a : nums) {
      // The best possible XOR for a is with the number that has the most
      // opposite bits
      int b =
          trie.query(a); // ~a flips all bits, so we try to maximize difference
      maxResult = std::max(maxResult, a ^ b);
    }
    return maxResult;
  }
};
/*
 * Example Walkthrough:
 * ----
 * Let's use the input: nums = [3, 10, 5, 25, 2, 8]
 *
 * We insert all numbers into the Trie, storing their binary representations.
 * For each number, we traverse the Trie, always trying to take the opposite bit
 * at each position to maximize the XOR. For example, for 5 (binary 000...0101),
 * we try to go right (1) if the current bit is 0, and left (0) if the current
 * bit is 1. The maximum XOR found in this example is 28 (from 5 ^ 25 = 28).
 *
 * This approach efficiently finds the maximum XOR by leveraging the Trie
 * structure to search for the best possible counterpart for each number.
 */
// @lc code=end
