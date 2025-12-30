/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 */

// @lc code=start

#include <algorithm>
#include <set>
#include <string>
#include <vector>

using std::set;
using std::string;
using std::vector;

/*
 * Brief Digested Understanding:
 * ---
 * In this problem, we are given a list of strings of equal length. Two strings
 * are considered "special-equivalent" if, by repeatedly swapping characters
 * among even-indexed positions or among odd-indexed positions within the same
 * string, one string can be transformed into the other. The challenge is to
 * determine how many *unique groups* of such special-equivalent strings exist
 * within the input list, where each group consists of strings all mutually
 * special-equivalent. At its core, the problem is about classifying strings
 * based on the multiset of their characters at even and odd indices,
 * independent of the order.
 *
 * High-Level Summary:
 * ---
 * The key observation is that for two strings to be special-equivalent, the
 * sorted multiset (bag) of characters at even indices must match, and likewise
 * for odd indices. Thus, for each string, we create a canonical signature by
 * sorting its even and odd indexed characters separately and concatenating the
 * results. All strings with the same signature belong to the same
 * special-equivalent group. We collect unique signatures using a set, and the
 * answer is simply the size of this set.
 *
 * Algorithm steps:
 * 1. For each word, extract even and odd indexed characters.
 * 2. Sort each collection (even and odd), then form a unique key (signature).
 * 3. Insert these signatures into a set to count unique groups.
 * 4. Return the total number of unique signatures.
 *
 * Time complexity: O(N * L log L), where N = number of words, L = word length
 * (since we sort characters for each word). Space complexity is O(N * L) for
 * the set and temporary storage.
 */

class Solution {
public:
  int numSpecialEquivGroups(vector<string> &words) {
    // Helper function to generate a canonical signature for a word.
    // Two words will have the same signature if (and only if) they are
    // special-equivalent.
    auto getSignature = [](const string &word) -> string {
      string even_chars,
          odd_chars; // Containers for even and odd indexed characters
      // Separate the characters by their index parity
      for (int i = 0; i < word.size(); ++i) {
        // Characters at even indices go to even_chars, at odd to odd_chars
        if (i % 2 == 0)
          even_chars.push_back(word[i]);
        else
          odd_chars.push_back(word[i]);
      }
      // Sort both even and odd indexed characters; this makes the signature
      // unique
      std::sort(even_chars.begin(), even_chars.end());
      std::sort(odd_chars.begin(), odd_chars.end());
      // Concatenate the sorted even and odd strings to form the final signature
      return even_chars + "#" +
             odd_chars; // '#' acts as a separator to prevent collision
    };

    set<string> signatures; // This set keeps all unique special-equivalent
                            // group signatures

    for (const string &word : words) {
      // Generate signature for each word and insert into set
      string sig = getSignature(word);
      signatures.insert(sig); // Insert will automatically ignore duplicates
    }

    // The number of unique signatures equals the number of special-equivalent
    // groups
    return signatures.size();
  }
};
// @lc code=end
