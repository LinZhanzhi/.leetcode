---
applyTo: "**"
---
Instructions:

- When generating or editing a solution for a LeetCode problem, do NOT remove or change any existing formatting, header comment, or footer comment in the file. These comments provide metadata needed by extensions to submit or grade the code and must remain untouched.
- Generate the solution code immediately below the existing comments and formatting, where appropriate.
- Before the code, always output the following two educational explanation sections, in this order:
  1. **Brief Digested Understanding:**
    - Summarize the core concept of the LeetCode problem in your own words. Focus on what the problem is really asking, the main action or transformation, and any key constraints. Avoid just paraphrasing the official problem statement. Imagine you're teaching a beginner: what is this problem *actually* about at its core?
  2. **High-Level Summary:**
    - Summarize how you'll approach and solve the problem at a bird's-eye view: what's the main algorithm, what patterns or data structures are involved, and what assumptions you rely on? Also, mention the expected time and space complexity. The goal is to give the reader a sense of the big picture and algorithmic tradeoffs before seeing details.
  **Note:** Since these explanation sections might be long, Cursor should break the lines to keep the output readable for users.
- After these two sections, output the solution code.
- Within the code, add *detailed, educational inline comments* explaining each step, variable, and function. Each comment should clarify not just what the code does, but why it is done that way, including algorithm choices, optimizations, edge-case handling, and implementation decisions.
- Ensure all comments and explanations are sufficiently detailed for a beginner to learn both the algorithm and the solution logic.
- If the code is in a specific language (e.g., Python, Java, C++), make explanations suitable for someone new to that language.
- The generated solution code must be **modularized**: break the solution into clear helper functions for simple building blocks, so that the main function highlights only the critical algorithmic parts. Avoid monolithic code that works but is difficult to read or trace. Helper functions should encapsulate repetitive or low-level operations, leaving the main flow concise and human-readable.
- Never modify, remove, or overwrite any comment blocks or formatting at the top or bottom of the file.
- Do not output the raw LeetCode problem description. Focus on clear understanding and teaching.
-
- refer to this preferable example file.
/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

/*
 * High-Level Summary:
 * -------------------
 * This implementation provides a Trie (also known as a prefix tree), which is a
 * tree-like data structure used to efficiently store and retrieve keys in a
 * dataset of strings. Each node in the Trie represents a single character of a
 * word. The main operations supported are:
 *   - insert(word): Add a word to the Trie.
 *   - search(word): Check if a word exists in the Trie.
 *   - startsWith(prefix): Check if any word in the Trie starts with the given
 * prefix.
 *
 * Assumptions:
 *   - All input words consist of lowercase English letters ('a' to 'z') only.
 *   - The Trie is case-sensitive and does not handle uppercase or
 * non-alphabetic characters.
 *
 * Algorithm Choice:
 *   - We use an array of 26 pointers for each node to represent the 26
 * lowercase English letters.
 *   - This allows O(1) access to each child node, making operations fast.
 *   - The Trie is implemented as a class with a nested TrieNode struct for
 * clarity and encapsulation.
 *
 * Time Complexity:
 *   - insert(word): O(L), where L is the length of the word.
 *   - search(word): O(L), where L is the length of the word.
 *   - startsWith(prefix): O(P), where P is the length of the prefix.
 *
 * Space Complexity:
 *   - O(N * M), where N is the number of words inserted and M is the average
 * length of the words, since each unique prefix creates new nodes.
 */

#include <string> // Include the string library to use std::string for word and prefix arguments.
using std::string; // Bring std::string into the current namespace for
                   // convenience.

// @lc code=start
class Trie {
private:
  // The TrieNode struct represents each node in the Trie.
  // Each node contains:
  //   - An array of 26 pointers to its children (one for each lowercase
  //   letter).
  //   - A boolean flag isEnd to indicate if a word ends at this node.
  struct TrieNode {
    TrieNode *
        children[26]; // Array to store pointers to child nodes for each letter.
    bool isEnd;       // True if a word ends at this node.

    // Constructor initializes all children to nullptr and isEnd to false.
    TrieNode() : isEnd(false) {
      // Initialize all child pointers to nullptr to indicate no children yet.
      for (int i = 0; i < 26; ++i)
        children[i] = nullptr;
    }
  };

  TrieNode *
      root; // The root node of the Trie. It does not hold any character itself.

public:
  // Constructor: Initializes the Trie with an empty root node.
  Trie() { root = new TrieNode(); }

  // Inserts a word into the Trie.
  // This function creates new nodes as needed for each character in the word.
  void insert(string word) {
    TrieNode *node = root; // Start from the root node.
    // Iterate through each character in the word.
    for (char c : word) {
      int idx = c - 'a'; // Map character 'a'-'z' to index 0-25.
      // If the child node for this character does not exist, create it.
      if (!node->children[idx]) {
        node->children[idx] = new TrieNode();
      }
      // Move to the child node corresponding to the current character.
      node = node->children[idx];
    }
    // After inserting all characters, mark the end node as a word ending.
    node->isEnd = true;
    // This ensures that search() can distinguish between a prefix and a
    // complete word.
  }

  // Searches for a complete word in the Trie.
  // Returns true if the word exists, false otherwise.
  bool search(string word) {
    TrieNode *node = root; // Start from the root node.
    // Traverse the Trie following the path of the word.
    for (char c : word) {
      int idx = c - 'a'; // Map character to index.
      // If the path breaks (child does not exist), the word is not in the Trie.
      if (!node->children[idx])
        return false;
      node = node->children[idx];
    }
    // After traversing all characters, check if this node marks the end of a
    // word. This is important because a prefix may exist, but not the full
    // word.
    return node->isEnd;
  }

  // Checks if there is any word in the Trie that starts with the given prefix.
  // Returns true if such a prefix exists, false otherwise.
  bool startsWith(string prefix) {
    TrieNode *node = root; // Start from the root node.
    // Traverse the Trie following the path of the prefix.
    for (char c : prefix) {
      int idx = c - 'a'; // Map character to index.
      // If the path breaks, no word with this prefix exists in the Trie.
      if (!node->children[idx])
        return false;
      node = node->children[idx];
    }
    // If we successfully traverse the prefix, it means at least one word with
    // this prefix exists.
    return true;
  }
};

/**
 * Example usage:
 * --------------
 * Trie* obj = new Trie();
 * obj->insert(word);           // Inserts 'word' into the Trie.
 * bool param_2 = obj->search(word);      // Returns true if 'word' exists in
 * the Trie. bool param_3 = obj->startsWith(prefix); // Returns true if any word
 * starts with 'prefix'.
 *
 * Edge Cases:
 * -----------
 * - Inserting or searching for an empty string will mark or check the root
 * node's isEnd flag.
 * - The implementation assumes all input consists of lowercase English letters
 * only.
 * - If a word is a prefix of another word (e.g., "app" and "apple"), both can
 * coexist in the Trie.
 */
// @lc code=end
