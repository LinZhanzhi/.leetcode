/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given a list of time points in "HH:MM" 24-hour format. Our goal is to
 * find the smallest difference in minutes between any two time points in the
 * list. Since the clock wraps around at midnight, we must also consider the
 * difference between the earliest and latest times across midnight.
 *
 * High-Level Summary:
 * ----
 * The solution converts each time string into the total number of minutes since
 * midnight, sorts these values, and then computes the minimum difference
 * between consecutive times. To handle the circular nature of the clock, we
 * also check the difference between the last and first time (across midnight).
 * If there are duplicate time points, the minimum difference is zero.
 *
 * Time Complexity: O(N log N), where N is the number of time points (for
 * sorting).
 * Space Complexity: O(N), for storing the converted minute values.
 */

#include <algorithm> // For std::sort, std::min
#include <climits>   // For INT_MAX
#include <string>    // For std::string
#include <vector>    // For std::vector

using std::string;
using std::vector;

class Solution {
public:
  // Main function to find the minimum time difference
  int findMinDifference(vector<string> &timePoints) {
    // Convert all time strings to minutes since midnight
    vector<int> minutes;
    for (const string &time : timePoints) {
      minutes.push_back(timeToMinutes(time));
    }

    // Sort the minutes to make it easy to compare consecutive times
    std::sort(minutes.begin(), minutes.end());

    // Initialize the minimum difference to the largest possible value
    int minDiff = INT_MAX;

    // Compare each pair of consecutive times
    for (size_t i = 1; i < minutes.size(); ++i) {
      int diff = minutes[i] - minutes[i - 1];
      minDiff = std::min(minDiff, diff);
    }

    // Handle the circular case: difference between the last and first time
    // across midnight There are 1440 minutes in a day
    int circularDiff = 1440 - (minutes.back() - minutes.front());
    minDiff = std::min(minDiff, circularDiff);

    return minDiff;
  }

private:
  // Helper function to convert "HH:MM" string to minutes since midnight
  int timeToMinutes(const string &time) {
    // Extract hours and minutes from the string
    int hours = std::stoi(time.substr(0, 2)); // First two characters are hours
    int mins =
        std::stoi(time.substr(3, 2)); // Characters at index 3 and 4 are minutes
    return hours * 60 + mins;
  }
};
// @lc code=end
