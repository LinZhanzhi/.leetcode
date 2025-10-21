/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// Brief Digested Understanding:
// ----
// This problem asks us to simulate placing students into a long row of seats
// (from 0 to n-1) such that each new student sits as far away from the nearest
// person as possible. If there are multiple optimal choices, they choose the
// seat with the smallest label. When a student leaves, that seat opens up for
// future seating. The task is to efficiently support many seat() and leave()
// operations. The challenge is maintaining seating efficiently, especially for
// very large n, without storing all empty seats explicitly.
//
// High-Level Summary:
// ----
// To efficiently simulate this, we use an ordered set (std::set) to keep track
// of all currently occupied seats. To seat a new student, we look at all
// "gaps" between seated students plus the "edges" (0 and n-1), and find the
// position that maximizes the minimal distance to the next person. Insertion
// and deletion into a set are O(log k) where k is the number of seated
// students (not O(n)). This means seat() is O(k) per call due to scanning the
// set, and leave() is O(log k). The approach is very space-efficient, storing
// only O(1e4) values even if n is up to 1e9, because the number of calls is
// small. All logic is broken out into helper functions for clarity and
// modularity.

// @lc code=start
#include <set> // Include set to keep track of occupied seats.
using std::set;

class ExamRoom {
private:
  int N; // Total number of seats (from 0 to N-1)
  set<int>
      occupied; // Stores the seat numbers that are currently occupied, sorted

  // Helper function to find the seat that maximizes distance from others
  int findBestSeat() {
    // If no seats are occupied, pick seat 0
    if (occupied.empty()) {
      return 0;
    }

    int maxDist = 0;
    int candidate = 0;

    // --- 1. Consider the first seat (from 0 to the first occupied seat)
    // The distance here is the gap from 0 to the first occupied seat
    int prev = -1;
    for (int seat : occupied) {
      if (prev == -1) {
        // If the first seat is farthest, prefer it
        if (seat != 0 && seat > maxDist) {
          maxDist = seat;
          candidate = 0;
        }
      } else {
        // --- 2. Consider seats between two occupied seats
        // The best place is the midpoint between prev and seat
        int dist = (seat - prev) / 2;
        int mid = prev + dist;
        if (dist > maxDist) {
          maxDist = dist;
          candidate = mid;
        }
      }
      prev = seat;
    }

    // --- 3. Consider the last seat (from last occupied seat to N-1)
    if (*occupied.rbegin() != N - 1) {
      int dist = (N - 1) - *occupied.rbegin();
      if (dist > maxDist) {
        candidate = N - 1;
      }
    }

    return candidate;
  }

public:
  // Constructor: Initializes with the number of seats.
  ExamRoom(int n) : N(n) {
    // No seats are occupied initially
  }

  // seat(): Seats a new student in the way to maximize distance to the nearest
  // person.
  int seat() {
    int seatPos = findBestSeat(); // Find the best position to seat the student

    // Insert this seat position into the set of occupied seats
    occupied.insert(seatPos);

    // Return the seat chosen
    return seatPos;
  }

  // leave(p): Student at seat p leaves, freeing it for the next seat() call
  void leave(int p) {
    // Remove seat p from the occupied set
    occupied.erase(p);
  }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end
