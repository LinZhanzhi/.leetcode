/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 */

// @lc code=start

#include <algorithm>
#include <unordered_map>
#include <vector>

using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * This problem simulates an ongoing election: each vote is recorded at a moment
 * in time, and for any query time t you need to quickly answer "who was the
 * (most-recent, in case of ties) leader by that time?" For every query, you
 * must efficiently return the person who had the highest vote count (and, if
 * tied, received their most recent vote most recently) up through time t. The
 * challenge is answering up to 10,000 queries efficiently while processing up
 * to 5,000 votes.
 *
 * High-Level Summary:
 * ----
 * The core idea is "pre-processing": as votes stream in (in chronological
 * order), we keep track of who is leading after each vote. We build a `leaders`
 * array such that leaders[i] records the leader at times[i], using the
 * tie-breaking rule (most recent win). To answer a query at time t, we binary
 * search to find the largest times[i] <= t, then return leaders[i]. This makes
 * query answering O(log n). Data structures: a frequency map to count votes per
 * person, two arrays for times and leaders. Time complexity: O(n)
 * preprocessing; O(log n) per query. Space: O(n) for arrays and hash map.
 */

// Modularized, educational implementation
class TopVotedCandidate {
private:
  vector<int> times_;   // Holds the times for each vote (sorted, as per input)
  vector<int> leaders_; // leaders_[i] is the leading person at times_[i]

  // Helper function: binary search to find index of largest time <= t
  int upperBound(int t) {
    // Finds the index such that times_[idx] <= t, and times_[idx + 1] > t (if
    // any)
    int left = 0, right = times_.size() - 1, ans = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (times_[mid] <= t) {
        ans = mid;
        left = mid + 1; // Try to find later candidate
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }

  // Helper function: builds leaders_ given persons and times
  void preprocessLeaders(const vector<int> &persons, const vector<int> &times) {
    std::unordered_map<int, int> count; // Tracks votes per person so far
    int currentLeader = -1;             // Current leading candidate
    int maxVotes = 0;                   // Highest current vote count

    for (size_t i = 0; i < persons.size(); ++i) {
      int p = persons[i];
      count[p]++;

      // If this person has as many or more votes than anyone else,
      // they become (or remain) the leader – in case of tie, latest wins
      if (count[p] >= maxVotes) {
        if (p != currentLeader) {
          currentLeader = p;
          maxVotes = count[p];
        } else {
          // Still count as leader, just update maxVotes in case it increased
          maxVotes = count[p];
        }
      }
      leaders_.push_back(currentLeader);
      // Each leaders_[i] matches times_[i]
    }
  }

public:
  // Constructor: handles preprocessing, prepares fast query lookups
  TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    // Store the times array for later binary search in queries
    times_ = times;
    // Preprocess to record leader at each vote time (handle tie-breaking: most
    // recent wins)
    preprocessLeaders(persons, times_);
  }

  // Answer query: who was leading at time t?
  int q(int t) {
    // Find the last time not after t, i.e., times_[idx] <= t
    int idx = upperBound(t);
    // If query time is before the first vote, behavior isn't specified by
    // problem, but we assume a valid t. Return the leader at that time. Inline
    // comment: upperBound returns -1 only if t < times_[0], which isn't
    // possible per constraints.
    return leaders_[idx];
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end
