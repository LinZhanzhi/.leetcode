/*
 * @lc app=leetcode id=822 lang=cpp
 *
 * [822] Card Flipping Game
 */

// Brief Digested Understanding:
// -----
// You're given several double-sided cards; each side has a number. You can flip
// any cards over so their front/back numbers swap sides. For a number to be
// "good," it must appear as a face-down number on at least one card, and must
// not appear as a face-up number on any card (after your flips). Your job is to
// find the smallest such good number, or zero if none exists. Essentially, you
// want to find the smallest number that you could get by flipping cards, such
// that this number never appears face-up anywhere but is allowed to appear
// (at least once) face-down.

// High-Level Summary:
// -----
// The main idea is to rule out numbers that appear on both sides of the same
// card, because no matter how you flip, that number will always be face-up on
// some card. So, first collect all numbers that appear on both sides of some
// single card (these are impossible to be "good"). Next, check all numbers that
// appear on fronts or backs: for each, if it's not in the impossible set, it is
// a candidate for being a good number. Among all such candidates, we return the
// smallest one. We'll use C++ sets for fast lookup. Time complexity is O(n), as
// all loops are over n (n up to 1000). Space is O(n) for the sets used.
// The solution is modularized into helper functions for readability.

// Include necessary C++ standard libraries
#include <algorithm> // for std::min
#include <set>
#include <vector>

using std::min;
using std::set;
using std::vector;

// @lc code=start
class Solution {
public:
  // The main function that solves the problem
  int flipgame(vector<int> &fronts, vector<int> &backs) {
    // Step 1: Find all numbers that appear on both sides of the same card.
    set<int> impossible = collectImpossibleNumbers(fronts, backs);

    // Step 2: Consider all numbers (from both fronts and backs) that are not
    // impossible.
    int answer = findMinimalCandidate(fronts, backs, impossible);

    return answer;
  }

private:
  // Helper function to collect numbers that are on both sides of the same card.
  set<int> collectImpossibleNumbers(const vector<int> &fronts,
                                    const vector<int> &backs) {
    set<int> s;
    // For each card, if its front and back are the same, this number can never
    // be "good"
    for (size_t i = 0; i < fronts.size(); ++i) {
      if (fronts[i] == backs[i]) {
        s.insert(fronts[i]);
      }
    }
    return s;
  }

  // Helper function to find the smallest valid "good" candidate
  int findMinimalCandidate(const vector<int> &fronts, const vector<int> &backs,
                           const set<int> &impossible) {
    int minGood =
        2001; // Since 1 <= value <= 2000, so 2001 is safe initial "max"
    // Check all numbers that ever appear on fronts or backs
    for (int x : fronts) {
      if (impossible.count(x) == 0) {
        minGood = min(minGood, x);
      }
    }
    for (int x : backs) {
      if (impossible.count(x) == 0) {
        minGood = min(minGood, x);
      }
    }
    // If no candidate found, return 0
    return minGood == 2001 ? 0 : minGood;
  }
};
// @lc code=end
