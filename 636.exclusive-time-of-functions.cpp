/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// Brief Digested Understanding:
// ----
// This problem is about simulating the execution of n functions on a
// single-threaded CPU, where each function call (including recursive and nested
// calls) is logged with a start or end event and a timestamp. The goal is to
// compute, for each function, the total time it spent actively running (its
// "exclusive time"), not counting time spent waiting while other functions it
// called were running. The logs are given in order, and each function's start
// and end events are properly paired.

// High-Level Summary:
// ----
// We'll process the logs in order, using a stack to simulate the call stack of
// the CPU. For each log, we parse the function id, event type ("start" or
// "end"), and timestamp. When a function starts, if another function was
// running, we add the time since the last timestamp to its exclusive time. We
// then push the new function onto the stack and update the last timestamp. When
// a function ends, we pop it from the stack and add its running time (including
// the end timestamp) to its exclusive time. We then update the last timestamp
// to the next time unit after the end. This approach ensures we correctly
// account for nested and recursive calls. Time complexity: O(L), where L is the
// number of logs. Space complexity: O(n + D), where D is the maximum call stack
// depth (at most L).

#include <sstream> // For std::stringstream
#include <stack>   // For std::stack
#include <string>  // For std::string
#include <vector>  // For std::vector

using std::stack;
using std::string;
using std::stringstream;
using std::vector;

class Solution {
public:
  // Main function to compute exclusive times for each function
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<int> result(
        n, 0); // Stores exclusive time for each function, initialized to 0
    stack<int> callStack; // Simulates the call stack, storing function ids
    int prevTime = 0;     // Tracks the previous timestamp processed

    // Helper function to parse a log string into function id, event type, and
    // timestamp
    auto parseLog = [](const string &log) -> std::tuple<int, string, int> {
      // The log format is "function_id:start|end:timestamp"
      stringstream ss(log);
      string idStr, type, timeStr;
      getline(ss, idStr, ':');
      getline(ss, type, ':');
      getline(ss, timeStr, ':');
      int id = std::stoi(idStr);
      int timestamp = std::stoi(timeStr);
      return {id, type, timestamp};
    };

    for (const string &log : logs) {
      int funcId, timestamp;
      string type;
      // Parse the log entry
      std::tie(funcId, type, timestamp) = parseLog(log);

      if (!callStack.empty()) {
        // If there is a function currently running, add the time since the last
        // event to its exclusive time For "start", the current function was
        // running from prevTime up to timestamp - 1 For "end", the current
        // function was running from prevTime up to timestamp (inclusive)
        result[callStack.top()] +=
            (type == "start" ? timestamp - prevTime : timestamp - prevTime + 1);
      }

      if (type == "start") {
        // A new function starts; push it onto the stack
        callStack.push(funcId);
        prevTime =
            timestamp; // Update prevTime to the start time of the new function
      } else {
        // A function ends; pop it from the stack
        // The time for this function has already been added above (including
        // the end timestamp)
        callStack.pop();
        prevTime =
            timestamp +
            1; // The next function (if any) resumes at the next time unit
      }
    }
    return result;
  }
};
// @lc code=end
