/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start

#include <string> // Include string library for std::string
#include <vector> // Include vector library for std::vector

using std::string;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * The problem asks us to make as few column deletions as possible from a
 * given grid of strings (all same length), so that after deleting columns from
 * all strings, the resulting rows are sorted lexicographically from top to
 * bottom. We must decide the minimum number of columns to delete so that, if we
 * read the remaining columns of each string, the overall order of the strings
 * does not violate the lexicographical rule (i.e., no string comes after a
 * lexicographically smaller string).
 */

/*
 * High-Level Summary:
 * ----
 * We scan columns from left to right. For each column, we check if, by keeping
 * it, we might break lex order in any adjacent pair of rows that have not yet
 * been resolved as "definitely ordered" by previous columns. If yes, that
 * column must be deleted. Otherwise, we keep the column and update which row
 * pairs are now confirmed to be lex-ordered due to this column. We use a
 * "sorted" flag array to record between which adjacent pairs the lex order is
 * now fixed, skipping future checks for those. This greedy, left-to-right
 * approach guarantees minimal deletions. Time complexity is O(n*m), where n is
 * number of strings and m is their length. Space is O(n) for status flags.
 */

class Solution {
public:
  // Main function: returns the minimal number of columns to delete
  int minDeletionSize(vector<string> &strs) {
    int n = strs.size();    // Number of strings (rows)
    int m = strs[0].size(); // Length of each string (columns)
    int deletions = 0;      // Counter for columns to delete

    // "sorted" keeps track of whether each adjacent pair (i, i+1) is
    // already in proper order due to previous columns.
    // E.g., sorted[i] == true means strs[i] < strs[i+1] is already fixed
    vector<bool> sorted(n - 1, false);

    // Scan from leftmost to rightmost column
    for (int col = 0; col < m; ++col) {
      // We need to decide whether to delete column `col` or keep it.
      if (needDeleteColumn(col, strs, sorted)) {
        deletions++; // We must delete this column to restore order
      } else {
        // If not deleted, update "sorted" based on this column's values
        updateResolvedPairs(col, strs, sorted);
      }
    }

    return deletions; // Return the total number of deletions
  }

private:
  // Helper function to determine if we need to delete a given column.
  // Returns true if any unresolved adjacent pair is out of order by this
  // column.
  bool needDeleteColumn(int col, const vector<string> &strs,
                        const vector<bool> &sorted) {
    int n = strs.size();
    // For each pair (i, i+1), only look at pairs not already known sorted
    for (int i = 0; i < n - 1; ++i) {
      if (!sorted[i]) {
        // If prior columns were equal, check current column for lex order
        if (strs[i][col] > strs[i + 1][col]) {
          // This pair is not in order; column must be deleted
          return true;
        }
      }
    }
    // All non-sorted pairs are OK in this column; no need to delete
    return false;
  }

  // Helper function to update the "sorted" array.
  // Mark pairs as sorted if strictly resolved by this column.
  void updateResolvedPairs(int col, const vector<string> &strs,
                           vector<bool> &sorted) {
    int n = strs.size();
    for (int i = 0; i < n - 1; ++i) {
      // Only unresolved pairs can be newly sorted
      if (!sorted[i]) {
        if (strs[i][col] < strs[i + 1][col]) {
          // This column strictly fits i < i+1; mark as sorted
          sorted[i] = true;
        }
        // If equal, their ordering may still be determined by future columns
      }
    }
  }
};

// @lc code=end
