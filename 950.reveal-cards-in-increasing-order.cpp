/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */

// Brief Digested Understanding:
// ----
// In this problem, you are given a set of unique cards, and you must reorder
// them such that, whenever you repeatedly "reveal the top card" and (if any
// cards remain) move the next top card to the bottom, the sequence of revealed
// cards appears in strictly increasing order. The goal is to find the *initial
// arrangement* of the deck to make this possible, given the rules of the
// revealing process. This is an exercise in simulation and reverse-engineering
// a queue process.
//
// High-Level Summary:
// ----
// The approach here is to observe that the revealing process can be simulated
// in reverse: rather than constructing the answer by simulating the reveal
// process from an arbitrary deck arrangement, we can reconstruct the necessary
// original order by starting from the largest card and simulating the reverse
// operations. We'll use a queue or deque to place each card at the position
// where it would have needed to be at the beginning for the final revealed
// order to be increasing. Specifically, for each sorted card (from largest to
// smallest), we move the last card of our 'worklist' to the front (as this
// simulates the "move the next card to the bottom" in reverse) then insert the
// current card at the front, repeating until all are placed. This ensures that
// the 'simulation' of the reveal process results in cards revealed in
// increasing order. The solution runs in O(N log N) for sorting and O(N) for
// the simulation, and uses O(N) space for the queue.

// @lc code=start
#include <algorithm> // For std::sort
#include <deque>     // For using std::deque to simulate the queue operations
#include <vector>    // For using std::vector for card storage and the answer

using std::deque;
using std::sort;
using std::vector;

class Solution {
public:
  // This function computes the deck order so that revealing as per the rules
  // yields increasing values
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    // Sort the input deck in increasing order
    sort(deck.begin(), deck.end());

    // This deque will represent the intended revealed order
    // We'll build it up in reverse (from largest card to smallest)
    deque<int> dq;

    // Iterate over each card, from the largest to the smallest
    // so that we can 'reverse build' the answer
    for (int i = deck.size() - 1; i >= 0; --i) {
      // If the deque already has cards, we simulate reversing the
      // operation of "take the next top card and put it at the bottom"
      if (!dq.empty()) {
        // Take the last card and move it to the front
        // This is because if a card was placed at the bottom in the original
        // process, in reverse, we take it from bottom (back) and put at the top
        // (front)
        int last = dq.back();
        dq.pop_back();
        dq.push_front(last);
      }
      // Place the current card at the top (front) of the deque
      dq.push_front(deck[i]);
    }

    // Transfer the result from the deque to a vector to return as the answer
    return vector<int>(dq.begin(), dq.end());
  }
};
// @lc code=end
