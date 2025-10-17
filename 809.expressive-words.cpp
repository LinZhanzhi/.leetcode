/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start

#include <string> // Include required header for std::string
#include <vector> // Include required header for std::vector

using std::string;
using std::vector;

/**
 * Brief Digested Understanding:
 * ---
 * This problem is about matching a "target" string (s), which could have
 * repeated letters ("stretched" groups), against a list of words. A word
 * matches if, by only **extending** groups of repeating characters in the word
 * (not squeezing or shrinking), you can get the target string. But you can only
 * extend a group if the group in the target is at least 3 characters (so
 * "heeellooo" lets you grow an "e" group, but not an "l" group that's only two
 * in a row). You need to check for each word if it's "stretchy," meaning, it
 * can be extended (some letters repeated more) to become exactly s, following
 * these rules.
 *
 * High-Level Summary:
 * ---
 * We'll break both s and each candidate word into "groups" of letters (letter &
 * count in a row: "heeellooo" -> [('h',1),('e',3),('l',2),('o',3)]).
 * For each word, if its grouping pattern matches s (same letters, same group
 * order), and for every group:
 *   - the group's size in s is equal to the word, or
 *   - the group's size in s is >= 3 and at least as big as in word
 * (so the target group can be an extension of the word's group),
 * then the word is "stretchy."
 * We modularize code with a helper to extract groups, and a helper to check if
 * a word is stretchy. The main function loops through words, counting matches.
 * Expected time complexity: O(N*K), where N = number of words, K = length of s.
 * Space is O(K) for group arrays per comparison.
 */

// Helper struct to store a group (character and count)
struct Group {
  char ch; // The character
  int cnt; // How many times it repeats consecutively

  Group(char c, int n) : ch(c), cnt(n) {}
};

class Solution {
public:
  // The main function counting expressive (stretchy) words
  int expressiveWords(string s, vector<string> &words) {
    // Extract groups of characters from string s
    vector<Group> sGroups = getGroups(s);

    int count = 0; // To count how many words are stretchy

    // Try each word in the given list
    for (const string &word : words) {
      // If word is stretchy compared to s, increase the count
      if (isStretchy(word, sGroups)) {
        count++;
      }
    }
    return count;
  }

private:
  // Helper to decompose string into groups of chars and their consecutive
  // counts
  vector<Group> getGroups(const string &str) {
    vector<Group> groups;
    int n = str.size();
    int i = 0;

    // Loop over each character in the string
    while (i < n) {
      char c = str[i];
      int j = i + 1;

      // Count how many times current character repeats consecutively
      while (j < n && str[j] == c) {
        j++;
      }
      int count = j - i;             // The size of the current group
      groups.emplace_back(c, count); // Store the group (char, count)

      i = j; // Move to next group start
    }

    return groups;
  }

  // Helper to check if 'word' can be "stretched" to match s (using s's groups)
  bool isStretchy(const string &word, const vector<Group> &sGroups) {
    // Decompose the word into its own groups
    vector<Group> wGroups = getGroups(word);

    // If the number of groups don't match, it's not possible (different
    // pattern)
    if (wGroups.size() != sGroups.size()) {
      return false;
    }

    // For each group, check if stretching is possible
    for (size_t i = 0; i < sGroups.size(); ++i) {
      // The two characters must be the same
      if (wGroups[i].ch != sGroups[i].ch) {
        return false;
      }
      int wCount = wGroups[i].cnt;
      int sCount = sGroups[i].cnt;

      if (sCount < wCount) {
        // Cannot "shrink" the group, can only stretch
        return false;
      }

      if (sCount != wCount && sCount < 3) {
        // Only allowed to stretch if the group in s has at least 3 letters
        return false;
      }
      // Otherwise, valid: either counts equal,
      // or s's group is longer and at least 3
    }

    // All groups matched stretchily
    return true;
  }
};

// @lc code=end
