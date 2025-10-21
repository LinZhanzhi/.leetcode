/*
 * @lc app=leetcode id=900 lang=cpp
 *
 * [900] RLE Iterator
 */

/*
 * Brief Digested Understanding:
 * ---
 * The problem wants us to efficiently represent and iterate through a sequence
 * that is encoded using run-length encoding (RLE). The encoding array tells us:
 * at every even index i, encoding[i] is how many times encoding[i + 1] (the
 * value) should appear consecutively. We need to implement an iterator where
 * each call to next(n) skips forward n times through the sequence, consuming
 * and removing those elements, and returns the last value exhausted (or -1 if
 * the sequence runs out).
 *
 * In simpler terms: it's like having a compressed list, and each next(n) call
 * asks us to quickly spit out the value at the position after moving forward n
 * spots, updating our internal cursor, and always working with the compressed
 * form.
 *
 * High-Level Summary:
 * ---
 * We'll solve this by:
 * - Storing the encoding array and a position pointer that tells us where we
 * are (which run we're currently "standing" at).
 * - For each call to next(n), we'll consume as many runs as needed, subtracting
 *   from the counts in the encoding. We'll move forward from the current run to
 * the next until we've exhausted n elements or run out entirely.
 * - We'll modularize by using helper functions to check run availability and to
 *   advance through runs.
 * - Time complexity for each next(n) is O(K), where K is the number of RLE runs
 * passed through for that call (in practice, since there are few runs and few
 * calls, this is very efficient). Space is O(L), with L the length of the
 * encoding.
 */

// @lc code=start
#include <vector>
using std::vector;

class RLEIterator {
private:
  // rle holds the run-length encoded array,
  // where even indices are counts and odd indices are the values
  vector<int> rle;

  // index points to the count in the next run to use (always even indices)
  int idx;

  // Helper: move idx forward until we find a run with a positive count,
  // or reach the end of the array.
  void advanceToNextNonZeroRun() {
    while (idx < rle.size() && rle[idx] == 0) {
      idx += 2; // Skip to the next run (count,value) pair
    }
  }

public:
  // Constructor: copy the input encoding for internal use, set the starting
  // index
  RLEIterator(vector<int> &encoding) : rle(encoding), idx(0) {
    // Ensure idx is at the next valid run at construction
    advanceToNextNonZeroRun();
  }

  // Consumes the next n elements in the sequence.
  // Returns the last value consumed, or -1 if not enough elements remain.
  int next(int n) {
    int lastValue = -1; // To store the result

    // While there are more elements to consume and runs remain,
    // consume runs in order
    while (n > 0 && idx < rle.size()) {
      // If this run can't satisfy all n, partially consume it
      if (rle[idx] >= n) {
        rle[idx] -= n;            // Consume n elements from current run
        lastValue = rle[idx + 1]; // The value being exhausted
        // If after consumption, this run is empty, move to next run
        if (rle[idx] == 0)
          advanceToNextNonZeroRun();
        return lastValue; // Successfully exhausted n elements
      } else {
        // Otherwise, consume the entire run and move to the next one
        n -= rle[idx];
        // If the run was not empty, update lastValue to this run's value
        if (rle[idx] > 0)
          lastValue = rle[idx + 1];
        rle[idx] = 0; // This run is exhausted
        idx += 2;     // Move to the next run's count
        advanceToNextNonZeroRun();
        // Loop will continue with possibly more runs until n is depleted
      }
    }
    // If we couldn't finish consuming n elements (ran out), return -1
    return -1;
  }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
// @lc code=end
