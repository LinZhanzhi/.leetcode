/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// Brief Problem Understanding:
// ----
// We need a data structure that allows us to add words and later search for
// words, where the search query may include '.' as a wildcard character that
// matches any single letter. The main challenge is efficiently supporting the
// wildcard search.

// High-Level Solution Summary:
// ----
// We'll use a Trie (prefix tree) to store all added words. For searching, we
// perform a depth-first search (DFS) in the Trie, branching whenever we
// encounter a '.' in the search word. This approach efficiently supports both
// exact and wildcard searches.
// - addWord: Insert the word into the Trie character by character.
// - search: Use DFS to handle '.' wildcards, checking all possible paths when a
// '.' is encountered. Time Complexity:
//   - addWord: O(L), where L is the length of the word.
//   - search: O(26^d * L), where d is the number of '.' in the search word (at
//   most 2), and L is the word length.
// Space Complexity: O(N * M), where N is the number of words and M is the
// average word length.

#include <string>  // For std::string
using std::string; // Bring string into scope

// @lc code=start
class WordDictionary {
private:
  // TrieNode represents each node in the Trie.
  struct TrieNode {
    TrieNode *children[26]; // Pointers to child nodes for each letter.
    bool isEnd;             // True if a word ends at this node.

    TrieNode() : isEnd(false) {
      // Initialize all children to nullptr.
      for (int i = 0; i < 26; ++i)
        children[i] = nullptr;
    }
  };

  TrieNode *root; // Root node of the Trie.

  // Helper function for search to handle '.' wildcards using DFS.
  bool dfsSearch(const string &word, int index, TrieNode *node) {
    // If we've reached the end of the search word, check if this node marks the
    // end of a word.
    if (index == word.size())
      return node->isEnd;

    char c = word[index];
    if (c == '.') {
      // If the current character is '.', try all possible children.
      for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
          // Recursively search the rest of the word from this child.
          if (dfsSearch(word, index + 1, node->children[i]))
            return true;
        }
      }
      // If none of the paths matched, return false.
      return false;
    } else {
      // If the character is a letter, go to the corresponding child.
      int idx = c - 'a';
      if (!node->children[idx])
        return false; // No such path.
      return dfsSearch(word, index + 1, node->children[idx]);
    }
  }

public:
  // Constructor: Initialize the Trie with an empty root node.
  WordDictionary() { root = new TrieNode(); }

  // Adds a word to the data structure.
  void addWord(string word) {
    TrieNode *node = root;
    for (char c : word) {
      int idx = c - 'a'; // Map character to index 0-25.
      if (!node->children[idx]) {
        node->children[idx] = new TrieNode();
      }
      node = node->children[idx];
    }
    node->isEnd = true; // Mark the end of the word.
  }

  // Returns true if any word in the data structure matches the search word.
  // The search word may contain '.' as a wildcard.
  bool search(string word) { return dfsSearch(word, 0, root); }
};

/**
 * Example usage:
 * -----
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);           // Adds 'word' to the data structure.
 * bool param_2 = obj->search(word); // Returns true if 'word' (with possible
 * '.') matches any added word.
 *
 * Edge Cases:
 * -----
 * - Searching for a word with only '.' will match any word of that length.
 * - If a word is a prefix of another, both can coexist.
 * - The implementation assumes all input consists of lowercase English letters
 * and '.' only.
 */
// @lc code=end
