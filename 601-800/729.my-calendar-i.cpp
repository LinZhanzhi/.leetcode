/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks you to implement a basic calendar. You can add events, each
 * defined by a start and end time ([startTime, endTime)). You can only add an
 * event if it does not overlap with any existing event. Overlapping means that
 * the intervals share at least some time. The challenge is to handle repeated
 * event bookings (up to 1000) efficiently and correctly.
 *
 * High-Level Summary:
 * ----
 * To solve this, we'll store the list of all booked events in a convenient data
 * structure, such as a vector of pairs, where each pair holds the start and end
 * of a booked interval. When a new booking request comes in, we iterate through
 * our booked intervals to check for overlap using the rule: two intervals [a,b)
 * and [c,d) overlap if max(a,c) < min(b,d). If no overlap is detected, we add
 * the new booking. Because the maximum number of bookings is small (1000), a
 * linear check suffices:
 *   - book: O(N) time per booking, where N is the number of booked events so
 * far.
 *   - Space: O(N), for storing all intervals.
 * For clarity and maintainability, the overlap checking is placed into its own
 * helper.
 */

// @lc code=start
#include <vector> // We use std::vector to maintain a dynamic list of bookings.
using std::make_pair;
using std::pair;
using std::vector;

class MyCalendar {
private:
  // bookings_ stores all booked intervals as pairs: (startTime, endTime)
  vector<pair<int, int>> bookings_;

  // Helper function to check if two intervals [s1, e1) and [s2, e2) overlap
  bool isOverlap(int s1, int e1, int s2, int e2) {
    // Two intervals overlap if max(s1, s2) < min(e1, e2)
    // This condition means there is a non-empty intersection.
    return std::max(s1, s2) < std::min(e1, e2);
  }

public:
  MyCalendar() {
    // Initialize an empty vector of bookings
    bookings_.clear();
  }

  bool book(int startTime, int endTime) {
    // Check all existing bookings for overlap
    for (const auto &booking : bookings_) {
      int bookedStart = booking.first;
      int bookedEnd = booking.second;
      if (isOverlap(bookedStart, bookedEnd, startTime, endTime)) {
        // If there is any overlap, we cannot book this event.
        return false;
      }
    }
    // If no overlap is found, save the new booking
    bookings_.emplace_back(startTime, endTime);
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
