/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

// Brief Digested Understanding:
// ----
// The problem asks us to reorder a list of log strings according to
// specific rules: Move all logs that use letters (called "letter-logs")
// to the front, sorted by their content (everything after the identifier).
// If two logs have the same content, order them by their identifier.
// All other logs ("digit-logs", which have numbers after their identifiers)
// go afterward, but must remain in their original order. The identifier
// is always the first word, and the rest of the log is either all words or all
// digits.

// High-Level Summary:
// ----
// We will tackle this by separating logs into two lists: letter-logs and
// digit-logs. Letter-logs are sorted with a custom comparator: first by their
// content, then by identifier on ties. Digit-logs simply maintain their
// encountered order (using a queue/list). After sorting letter-logs, we
// concatenate the letter-logs with the digit-logs to form the ordered result.
// We'll use helper functions to check log type and to split the log into its
// identifier/content, making the code modular and clear.
// - Time Complexity: O(N log N), where N is the number of logs (for sorting).
// - Space Complexity: O(N), for storing the separated and sorted logs.
// We use standard library data types such as std::string and std::vector
// from <string> and <vector>.

#include <algorithm> // For std::sort
#include <cctype>    // For std::isdigit to classify digit logs
#include <string>    // For std::string to handle log entries
#include <vector>    // For std::vector to store logs

using std::string;
using std::vector;

class Solution {
public:
  // Main function to reorder log files
  vector<string> reorderLogFiles(vector<string> &logs) {
    // Separate letter-logs and digit-logs
    vector<string> letterLogs;
    vector<string> digitLogs;
    for (const string &log : logs) {
      if (isDigitLog(log)) {
        digitLogs.push_back(log); // Maintain original order for digit-logs
      } else {
        letterLogs.push_back(log); // Will be sorted
      }
    }

    // Sort the letter-logs using the specified order
    std::sort(letterLogs.begin(), letterLogs.end(), letterLogComparator);

    // Concatenate letter-logs and digit-logs into a single result vector
    vector<string> reorderedLogs;
    reorderedLogs.reserve(logs.size()); // Pre-allocate space for efficiency

    reorderedLogs.insert(reorderedLogs.end(), letterLogs.begin(),
                         letterLogs.end());
    reorderedLogs.insert(reorderedLogs.end(), digitLogs.begin(),
                         digitLogs.end());
    return reorderedLogs;
  }

private:
  // Helper function to determine if log is a digit-log
  static bool isDigitLog(const string &log) {
    // Find the first space to get the start of log content
    size_t pos = log.find(' ');
    // Defensive check: If log doesn't have content, treat as letter-log (should
    // not happen by constraints)
    if (pos == string::npos || pos + 1 >= log.size())
      return false;
    return std::isdigit(
        log[pos + 1]); // Digit-logs start with a digit after space
  }

  // Helper function to extract content and identifier parts from a log
  static std::pair<string, string>
  splitIdentifierAndContent(const string &log) {
    size_t pos = log.find(' ');
    // Split log into identifier and content
    string identifier = log.substr(0, pos);
    string content = log.substr(pos + 1);
    return {identifier, content};
  }

  // Custom comparator for sorting letter-logs
  static bool letterLogComparator(const string &log1, const string &log2) {
    // Extract contents and identifiers
    auto [id1, cont1] = splitIdentifierAndContent(log1);
    auto [id2, cont2] = splitIdentifierAndContent(log2);
    if (cont1 == cont2) {
      return id1 < id2; // If contents are equal, compare identifiers
                        // lexicographically
    }
    return cont1 < cont2; // Otherwise, use the content for ordering
  }
};
// @lc code=end
