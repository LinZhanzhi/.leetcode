/*
 * @lc app=leetcode id=833 lang=cpp
 *
 * [833] Find And Replace in String
 */

/*
 * Brief Digested Understanding:
 * ----
 * The problem wants us to do multiple replacements in a string. Each
 * replacement is described by a starting index, a pattern to match at that
 * index, and the string to replace if the pattern matches. All replacements
 * must be made at once; they should not interfere with each other, and the test
 * cases guarantee there are no overlaps. The goal is to perform these
 * simultaneous replacements efficiently and with careful attention to string
 * matching.
 *
 * High-Level Summary:
 * ----
 * We'll bundle each replacement operation into a helper struct (holding index,
 * source, and target). We then sort all replacement operations by their index
 * (ascending), which ensures we process from left to right. As we scan the
 * string `s`, we check if a replacement starts at the current index; if so, we
 * attempt to match the source substring. If it matches, we append the target to
 * the answer and skip over the matched portion in `s`. If not, or if there's no
 * operation at the current index, add the original character to the answer and
 * advance by one. Since operations are guaranteed not to overlap, this approach
 * is safe and efficient.
 *
 * The main data structures are: a struct to hold operations, and a sorted
 * vector of these. The process is linear in the length of `s` and the number of
 * operations
 * (`O(n + k * L)` at worst, where `n` is the string length, `k` is the number
 * of ops, and `L` the average length of each `source`).
 */

#include <algorithm> // For std::sort
#include <string>    // For std::string
#include <vector>    // For std::vector

using std::string;
using std::vector;

// @lc code=start
class Solution {
private:
  // Helper struct holding all data for one replacement operation.
  struct Operation {
    int index;     // Where this operation should try to match in 's'
    string source; // String to match at 'index' in 's'
    string target; // String to replace with if 'source' matches
    // Constructor for convenience
    Operation(int idx, const string &src, const string &tgt)
        : index(idx), source(src), target(tgt) {}
    // Comparator for sorting by index ascending
    bool operator<(const Operation &other) const { return index < other.index; }
  };

  // This helper converts the three parallel arrays into a sorted vector of
  // Operation structs
  vector<Operation> buildAndSortOps(const vector<int> &indices,
                                    const vector<string> &sources,
                                    const vector<string> &targets) {
    int n = indices.size();
    vector<Operation> ops;
    // Bundle the index, source, and target together for each operation
    for (int i = 0; i < n; ++i) {
      ops.emplace_back(indices[i], sources[i], targets[i]);
    }
    // Sort all operations by index (ascending) so we process left to right
    std::sort(ops.begin(), ops.end());
    return ops;
  }

  // Helper to check if s has 'source' at 'pos'
  bool matchesAt(const string &s, int pos, const string &source) {
    // Check if we can match source at pos (make sure not to run off end)
    int m = source.size();
    if (pos + m > s.size())
      return false;
    // Compare character by character for the source substring
    for (int i = 0; i < m; ++i) {
      if (s[pos + i] != source[i])
        return false;
    }
    return true;
  }

public:
  string findReplaceString(string s, vector<int> &indices,
                           vector<string> &sources, vector<string> &targets) {
    // Step 1: Build and sort all operations by index
    vector<Operation> ops = buildAndSortOps(indices, sources, targets);
    int n = s.size();
    string result; // String to accumulate the answer

    int op_ptr = 0; // Pointer into our sorted ops vector
    int i = 0;      // Pointer into original string s

    // Scan through s one character at a time
    while (i < n) {
      // if there is no operation at this index, just copy the character
      if (op_ptr >= ops.size() || ops[op_ptr].index > i) {
        result += s[i];
        i += 1;
        continue;
      }
      // update operation pointer to current index
      if (op_ptr < ops.size() && ops[op_ptr].index < i) {
        ++op_ptr;
        continue;
      }
      // If we have an operation ready at this index
      if (op_ptr < ops.size() && ops[op_ptr].index == i) {
        // Try to match the operation's source string at current index
        const Operation &op = ops[op_ptr];
        if (matchesAt(s, i, op.source)) {
          // Source matches: append the target string
          result += op.target;
          // Skip over the source substring in s
          i += op.source.size();
        }
        ++op_ptr;
      }
    }
    return result;
  }
};
// @lc code=end
