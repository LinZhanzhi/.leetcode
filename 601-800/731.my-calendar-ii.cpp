/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

/**
 * Brief Digested Understanding:
 * ----
 * This problem centers around designing a calendar that allows you to book new
 * events as long as doing so does not create a triple booking. A triple booking
 * happens if at least three bookings overlap at any point. The system should
 * process a sequence of book(start, end) requests, allowing bookings if there
 * is never a moment with three or more overlapping intervals.
 *
 * The key concept is: keep track of single and double overlaps so you know if a
 * new booking would cause a triple overlap and should be rejected.
 */

/**
 * High-Level Summary:
 * ----
 * We'll solve this by keeping two collections:
 *  1. A vector for all existing events (booked_
 *  2. A vector for intervals representing double bookings (overlaps_)
 *
 * For each new booking request:
 *   - First, check if the requested interval would overlap with any
 * double-booked interval (anything in overlaps_). If so, reject, since that
 * would create a triple booking.
 *   - Then, for every existing event in booked_, if there is an overlap, add
 * that overlap interval to overlaps_ for future reference.
 *   - If there are no triple overlaps, allow the booking and store it in
 * booked_.
 *
 * This approach has O(N^2) time per booking in the worst case (since each
 * booking checks all previous bookings and their overlaps), but is efficient
 * enough for N ≤ 1000.
 *
 * We'll modularize the design with helper functions for overlap detection and
 * double-booking management, and use detailed comments to explain every step
 * clearly.
 */

#include <utility>
#include <vector>

using std::pair;
using std::vector;

/**
 * MyCalendarTwo keeps track of single and double bookings to reject triple
 * bookings.
 */
class MyCalendarTwo {
private:
  // Each booking is stored as a pair (start, end)
  vector<pair<int, int>> booked_; // List of all single-booked events
  vector<pair<int, int>>
      overlaps_; // List of all double-booked (overlap) intervals

  // Helper function to check if two intervals [s1,e1) and [s2,e2) overlap.
  // Returns true if they have a non-empty intersection.
  bool isOverlap(int s1, int e1, int s2, int e2) {
    // Intervals overlap if start of one is less than end of other and vice
    // versa
    return s1 < e2 && s2 < e1;
  }

  // Helper function to compute the intersection interval (as pair) of two
  // intervals.
  pair<int, int> getIntersection(int s1, int e1, int s2, int e2) {
    // The intersection interval is from max(s1, s2) to min(e1, e2)
    return {std::max(s1, s2), std::min(e1, e2)};
  }

public:
  // Constructor: Initialize without any booking
  MyCalendarTwo() {
    // No setup needed; vectors are empty by default
  }

  /**
   * Attempts to book a new interval [startTime, endTime).
   * Returns true if booking does not cause a triple booking; otherwise false.
   */
  bool book(int startTime, int endTime) {
    // First, check if this booking would overlap any existing double booking
    for (const auto &interval : overlaps_) {
      if (isOverlap(startTime, endTime, interval.first, interval.second)) {
        // Would cause a triple booking! Reject.
        return false;
      }
    }

    // For every prior single booking, see if this one overlaps, and record the
    // overlap as a double booking.
    for (const auto &event : booked_) {
      if (isOverlap(startTime, endTime, event.first, event.second)) {
        // Record the overlap interval as a new double booking for future checks
        pair<int, int> overlap =
            getIntersection(startTime, endTime, event.first, event.second);
        overlaps_.push_back(overlap);
      }
    }

    // It's safe to add this booking as it doesn't cause any triple overlapping
    booked_.emplace_back(startTime, endTime);
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
