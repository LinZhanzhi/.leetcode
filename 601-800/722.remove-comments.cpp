/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */

// @lc code=start

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about simulating how a C++ compiler removes comments from
 * source code. There are two comment types: (1) Line comments, started by "//",
 * causing the rest of the line to be ignored. (2) Block comments, started with
 * "/ *" and ended with "* / ", and can span multiple lines. For each input
 * line, you must carefully skip over comment regions and preserve all other
 * code or whitespace. Only non-empty lines of actual code, after stripping all
 * comments, should be output.
 *
 * Key constraints: Block comments are not nested (i.e., there is no "/*" inside
 * a block comment that would require recursive parsing). Whitespaces and blank
 * lines are only kept if they're part of a non-empty line after comments are
 * removed.
 */

/*
 * High-Level Summary:
 * ----
 * The core approach is to iterate through the entire source code line by line,
 * character by character, tracking whether we are inside a block comment.
 * When not in a block comment:
 *   - If we find "//", we skip the remainder of the current line (line
 * comment).
 *   - If we find "/*", we enter block comment mode (skip until the next "* /").
 *   - Otherwise, we append the character to the output buffer.
 * When inside a block comment:
 *   - Skip everything until "* /" is found, then exit block mode.
 * At the end of a line, if we're not in a block comment and the output buffer
 * is not empty, add it as a processed output line.
 * Time complexity is O(N * M) for N source lines and average M characters per
 * line, with O(N * M) space for the output. This solution also modularizes
 * repetitive tasks like appending non-empty lines.
 */

#include <string>
#include <vector>
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // The main function to remove comments from the given source code.
  vector<string> removeComments(vector<string> &source) {
    vector<string> result; // Stores lines of code after comment removal
    string buf; // Accumulates current line's code (may continue across lines if
                // inside block comment)
    bool inBlock = false; // Are we currently inside a block comment?

    // Appends non-empty lines to the result vector.
    auto appendIfNonEmpty = [&](const string &line) {
      // We only want to keep lines that are not empty after removing comments.
      if (!line.empty())
        result.push_back(line);
    };

    // Process each line.
    for (const string &line : source) {
      int i = 0; // Index for iterating through characters in the line
      int n = line.size();
      // If not inside a block comment, clear the buffer for a new potential
      // code line.
      if (!inBlock)
        buf.clear();

      // Walk through characters one-by-one for this line
      while (i < n) {
        if (!inBlock) {
          // Check for start of a line comment ("//")
          if (i + 1 < n && line[i] == '/' && line[i + 1] == '/') {
            // Everything after "//" on this line is ignored.
            break;
          }
          // Check for start of a block comment ("/*")
          else if (i + 1 < n && line[i] == '/' && line[i + 1] == '*') {
            // Enter block mode: ignore everything until "*/" is found.
            inBlock = true;
            i += 2; // Skip over "/*"
          } else {
            // Regular character outside any comment, keep it for output.
            buf += line[i];
            i++;
          }
        } else {
          // Already in block comment, look for the block end ("*/")
          if (i + 1 < n && line[i] == '*' && line[i + 1] == '/') {
            inBlock = false; // Exit block comment mode
            i += 2;          // Skip over "*/"
          } else {
            // Skip all characters inside block comment
            i++;
          }
        }
      }

      // If a code line has been collected and we're not in block comment, flush
      // it.
      if (!inBlock && !buf.empty()) {
        appendIfNonEmpty(buf);
      }
    }
    // Output the list of non-empty code lines, comment-free.
    return result;
  }
};
// @lc code=end
