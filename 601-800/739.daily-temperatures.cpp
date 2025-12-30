/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about, for each day, figuring out how many days you'd have
 * to wait to encounter a warmer temperature. If there’s never a warmer day
 * after a particular day, the answer for that day is zero. At its core,
 * this is a "next greater element" search, performed efficiently for an array
 * of daily temperature values.
 *
 * Key constraints:
 * - The temperature array can be large (up to 100,000).
 * - We need an efficient method to quickly check for the first warmer
 * temperature after each day.
 */

/*
 * High-Level Summary:
 * ----
 * To solve this problem, we will use a monotonic decreasing stack (stores
 * indices of days in decreasing order of temperature). As we move through the
 * temperatures, we check if the current day's temperature is higher than the
 * temperature for the index on the top of the stack. If so, we know we've found
 * the next warmer day for those earlier days and update their answers. We do
 * this in a single left-to-right pass for O(n) time and O(n) space, where n
 * is the number of days. This uses a stack to store indices whose answers
 * have not yet been found.
 */

#include <stack>  // Required for using std::stack
#include <vector> // Required for using std::vector

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
  // This function returns a vector where each index represents
  // the number of days until a warmer temperature.
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    // The result vector, initialized to 0 (means no warmer day found yet for
    // all).
    vector<int> answer(temperatures.size(), 0);
    // Stack to store indices of the days.
    // The stack will store indices in decreasing order of temperature.
    stack<int> pendingDays;

    // Process each day's temperature.
    for (int today = 0; today < temperatures.size(); ++today) {
      // Use a helper function to update answers for all days whose
      // unresolved warmer day is today (current temperature > stack top's
      // temperature).
      resolvePreviousColderDays(temperatures, answer, pendingDays, today);
      // Push current day's index to stack for future resolving.
      pendingDays.push(today);
    }
    // After the loop, the stack may contain indices for which
    // there is no warmer day; their answer remains 0 by initialization.
    return answer;
  }

private:
  // Helper that pops from the stack and computes "number of days until
  // warmer temperature" for previous days, if today's temperature is warmer
  // than the day at stack's top.
  void resolvePreviousColderDays(const vector<int> &temperatures,
                                 vector<int> &answer, stack<int> &pendingDays,
                                 int today) {
    // While there are unresolved colder days and today's temperature is warmer
    while (!pendingDays.empty() &&
           temperatures[today] > temperatures[pendingDays.top()]) {
      // Get the index of the previous colder day
      int prevDay = pendingDays.top();
      pendingDays.pop();
      // The answer for prevDay is the difference in days
      answer[prevDay] = today - prevDay;
    }
  }
};
// @lc code=end
