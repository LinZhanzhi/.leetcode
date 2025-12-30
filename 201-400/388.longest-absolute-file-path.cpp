/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a string that encodes a file system, where each line represents
 * either a directory or a file. The depth of each entry is indicated by the
 * number of leading tab characters ('\t'). Our task is to find the length of
 * the longest absolute path to any file (not directory) in this system. The
 * absolute path is the full path from the root to a file, using '/' as a
 * separator.
 *
 * For example, for the input "dir\n\tsubdir1\n\t\tfile1.ext", the absolute path
 * to the file is "dir/subdir1/file1.ext", and its length is 20.
 */

/*
 * High-Level Summary:
 * ----
 * The solution processes the input string line by line, keeping track of the
 * cumulative path length at each directory depth using a vector. For each line,
 * we determine its depth (number of '\t'), extract its name, and check if it's
 * a file (contains a '.'). If it's a file, we compute the total path length and
 * update the maximum if it's the longest so far. If it's a directory, we update
 * the path length at its depth for future files.
 *
 * The key fix is to ensure that we never access pathLen[depth-1] when depth is
 * 0, which would be out-of-bounds. We handle this by always ensuring pathLen
 * has at least depth+1 elements and by treating the root directory (depth 0)
 * carefully. The algorithm runs in O(N) time and uses O(D) space, where N is
 * the input length and D is the maximum directory depth.
 */

#include <algorithm> // For std::max
#include <string>    // For std::string
#include <vector>    // For std::vector

using std::max;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  int lengthLongestPath(string input) {
    // Vector to store the cumulative length of the path at each depth.
    // pathLen[depth] = total length of the path up to that depth (excluding the
    // current file/dir).
    vector<int> pathLen(1, 0); // pathLen[0] = 0 for the root level.
    int maxLen = 0; // To keep track of the maximum path length found.

    size_t i = 0; // Index to traverse the input string.
    while (i < input.size()) {
      // 1. Determine the depth (number of '\t' at the start of the line).
      int depth = 0;
      while (i < input.size() && input[i] == '\t') {
        ++depth;
        ++i;
      }

      // 2. Extract the name of the file or directory.
      size_t nameStart = i;
      bool isFile = false;
      while (i < input.size() && input[i] != '\n') {
        if (input[i] == '.') {
          isFile = true; // If there's a dot, it's a file.
        }
        ++i;
      }
      string name = input.substr(nameStart, i - nameStart);

      // 3. Move to the next line (skip the '\n' character if present).
      if (i < input.size() && input[i] == '\n') {
        ++i;
      }

      // 4. Ensure the pathLen vector is large enough for the current depth.
      //    This prevents out-of-bounds access.
      if (pathLen.size() <= static_cast<size_t>(depth)) {
        pathLen.resize(depth + 1);
      }

      // 5. Update the path length at this depth.
      //    For directories, add 1 for the '/' separator (except at root).
      //    For files, we don't add a trailing '/'.
      //    We must ensure depth > 0 before accessing pathLen[depth-1].
      int currLen = (depth > 0 ? pathLen[depth - 1] + 1 : 0) +
                    static_cast<int>(name.length());
      pathLen[depth] = currLen;

      // 6. If it's a file, check if this is the longest path so far.
      if (isFile) {
        maxLen = max(maxLen, pathLen[depth]);
      }
      // If it's a directory, we just update pathLen for future files.
    }

    // If no file was found, maxLen will be 0.
    return maxLen;
  }
};
// @lc code=end
