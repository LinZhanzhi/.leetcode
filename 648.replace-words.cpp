/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// Brief Digested Understanding:
// ----
// This problem is about efficiently replacing words in a sentence with their
// shortest possible "root" from a given dictionary. Each word in the sentence
// should be checked: if it starts with any root from the dictionary, it should
// be replaced by the shortest such root. If no root matches, the word remains
// unchanged. The main challenge is to do this efficiently for potentially large
// sentences and dictionaries.

// High-Level Summary:
// ----
// We'll use a Trie (prefix tree) to store all the roots from the dictionary.
// For each word in the sentence, we'll traverse the Trie to find the shortest
// root that matches the prefix of the word. If found, we replace the word with
// that root; otherwise, we keep the word as is. We'll split the sentence into
// words, process each, and then join them back together. The Trie allows for
// fast prefix lookups (O(L) per word, where L is the word length). Time
// complexity: O(N * L + S), where N is the number of words in the sentence, L
// is the average word/root length, and S is the total number of characters in
// the sentence. Space complexity: O(T), where T is the total number of
// characters in all roots (for the Trie).

#include <sstream> // For splitting and joining the sentence
#include <string>
#include <vector>

using std::string;
using std::vector;

// Helper TrieNode class to represent each node in the Trie
class TrieNode {
public:
  // Each node can have up to 26 children (for each lowercase letter)
  TrieNode *children[26];
  // Flag to indicate if this node marks the end of a root word
  bool isEnd;

  // Constructor initializes all children to nullptr and isEnd to false
  TrieNode() : isEnd(false) {
    for (int i = 0; i < 26; ++i)
      children[i] = nullptr;
  }
};

// Helper Trie class to encapsulate Trie operations
class Trie {
private:
  TrieNode *root;

public:
  // Constructor initializes the root node
  Trie() { root = new TrieNode(); }

  // Inserts a root word into the Trie
  void insert(const string &word) {
    TrieNode *node = root;
    for (char c : word) {
      int idx = c - 'a'; // Map character to index 0-25
      if (!node->children[idx]) {
        node->children[idx] = new TrieNode();
      }
      node = node->children[idx];
    }
    node->isEnd = true; // Mark the end of a root word
  }

  // Finds the shortest root in the Trie that is a prefix of the given word
  // Returns the root if found, otherwise returns an empty string
  string findShortestRoot(const string &word) {
    TrieNode *node = root;
    string prefix;
    for (char c : word) {
      int idx = c - 'a';
      if (!node->children[idx]) {
        // No further path in Trie, so no root matches
        return "";
      }
      node = node->children[idx];
      prefix += c;
      if (node->isEnd) {
        // Found a root that is a prefix of the word
        return prefix;
      }
    }
    // No root found that matches the prefix
    return "";
  }
};

// Main solution class
class Solution {
public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    // Step 1: Build the Trie from the dictionary of roots
    Trie trie;
    for (const string &root : dictionary) {
      trie.insert(root);
    }

    // Step 2: Split the sentence into words
    std::istringstream iss(sentence);
    string word;
    vector<string> resultWords;

    // Step 3: For each word, replace with the shortest root if possible
    while (iss >> word) {
      string root = trie.findShortestRoot(word);
      if (!root.empty()) {
        // If a root is found, use it
        resultWords.push_back(root);
      } else {
        // Otherwise, keep the original word
        resultWords.push_back(word);
      }
    }

    // Step 4: Join the processed words back into a sentence
    // Use ostringstream for efficient string concatenation
    std::ostringstream oss;
    for (size_t i = 0; i < resultWords.size(); ++i) {
      if (i > 0)
        oss << " ";
      oss << resultWords[i];
    }
    return oss.str();
  }
};
// @lc code=end
