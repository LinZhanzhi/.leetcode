/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */

/*
 * Brief Digested Understanding:
 * ----
 * The problem is about building a data structure that maps string keys to
 * integer values, and allows you to quickly compute the sum of all values whose
 * keys start with a given prefix. If a key is inserted more than once, its
 * value is replaced (not added). The main challenge is efficiently summing
 * values for all keys sharing a prefix, especially as the number of keys grows.
 *
 * High-Level Summary:
 * ----
 * We'll use two main data structures:
 *   1. An unordered_map (hash map) to store the current value for each key,
 *      so we can update and override values efficiently.
 *   2. A Trie (prefix tree) where each node keeps track of the sum of all
 *      values for keys passing through that node. When inserting or updating a
 *      key, we compute the difference between the new and old value, and
 *      propagate this difference along the Trie path for that key. This allows
 *      sum(prefix) queries to be answered in O(P) time, where P is the prefix
 *      length.
 * Time Complexity:
 *   - insert: O(L), where L is the length of the key.
 *   - sum: O(P), where P is the length of the prefix.
 * Space Complexity:
 *   - O(N * M), where N is the number of unique keys and M is the average key
 *     length, due to the Trie structure.
 */

#include <string>        // For std::string
#include <unordered_map> // For std::unordered_map

using std::string;
using std::unordered_map;

// @lc code=start
class MapSum {
private:
  // TrieNode represents each node in the prefix tree.
  struct TrieNode {
    int sum; // The sum of all values for keys passing through this node.
    TrieNode *children[26]; // One child for each lowercase letter.

    TrieNode() : sum(0) {
      // Initialize all children to nullptr.
      for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
      }
    }
  };

  TrieNode *root;                    // The root of the Trie.
  unordered_map<string, int> keyMap; // Maps each key to its current value.

  // Helper function to insert or update a key in the Trie.
  // It propagates the value difference (delta) along the key's path.
  void insertToTrie(const string &key, int delta) {
    TrieNode *node = root;
    for (char c : key) {
      int idx = c - 'a'; // Map 'a'-'z' to 0-25.
      if (!node->children[idx]) {
        node->children[idx] = new TrieNode();
      }
      node = node->children[idx];
      node->sum += delta; // Update the sum at this node.
    }
  }

  // Helper function to traverse the Trie to the node representing the prefix.
  // Returns the node if found, or nullptr if the prefix does not exist.
  TrieNode *traversePrefix(const string &prefix) {
    TrieNode *node = root;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!node->children[idx]) {
        return nullptr; // Prefix path does not exist.
      }
      node = node->children[idx];
    }
    return node;
  }

public:
  // Constructor: Initializes the Trie root and the key-value map.
  MapSum() { root = new TrieNode(); }

  // Inserts a key-value pair into the map.
  // If the key already exists, its value is updated (not added).
  void insert(string key, int val) {
    int prev = 0;
    // Check if the key already exists and get its previous value.
    if (keyMap.find(key) != keyMap.end()) {
      prev = keyMap[key];
    }
    int delta = val - prev;   // Compute the change in value for this key.
    keyMap[key] = val;        // Update the key's value in the map.
    insertToTrie(key, delta); // Propagate the change in the Trie.
  }

  // Returns the sum of all values for keys starting with the given prefix.
  int sum(string prefix) {
    TrieNode *node = traversePrefix(prefix);
    if (!node) {
      return 0; // No keys with this prefix.
    }
    return node->sum; // Return the sum stored at the prefix node.
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
