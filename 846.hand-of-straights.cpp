/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// Brief Digested Understanding:
// ----
// The main goal is to decide if a deck of cards can be split into groups of the
// same size, such that each group contains consecutive card values (for
// example, [2, 3, 4] would be one such group). You need to form groups of
// 'groupSize' cards using all cards, with each group consisting of consecutive
// numbers. The core challenge is efficiently grouping the cards and checking
// for possible consecutive groups.

// High-Level Summary:
// ----
// We'll approach the problem by counting each card's occurrences, then forming
// groups starting from the lowest available card value each time, greedily
// building consecutive sequences of size groupSize. For this, we use a sorted
// data structure (like std::map) to maintain the card frequencies in order. At
// every step, for the smallest remaining value, we check if the next
// groupSize-1 consecutive values are available, decreasing their count as we
// go. If, at any point, we cannot find enough cards to build a group, we return
// false. This greedy method is efficient: Time complexity is O(N log N) since
// we sort and traverse the hand, and the space complexity is O(N) for the card
// frequency map, where N is the length of the hand.

// Required includes
#include <map>    // To use std::map for counting/ordering card values
#include <vector> // To use std::vector for the hand input

using std::map;
using std::vector;

class Solution {
public:
  // Main function: determines if cards can be arranged into consecutive groups
  // of given size
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    // Edge case: If hand size isn't divisible by groupSize, perfect grouping is
    // impossible
    if (hand.size() % groupSize != 0)
      return false;

    // Count each card's frequency, maintaining natural order
    map<int, int> count_map = countCards(hand);

    // Try to create groups as long as there are cards left in the map
    while (!count_map.empty()) {
      // Get the smallest card value available (the first key in map)
      int start = count_map.begin()->first;
      int cards_needed = count_map[start];

      // Attempt to build a group starting from 'start'
      if (!canFormGroup(count_map, start, groupSize, cards_needed))
        return false;
    }

    // If we successfully process all cards, return true
    return true;
  }

private:
  // Helper function: counts the occurrences of each card in the hand
  map<int, int> countCards(const vector<int> &hand) {
    map<int, int> count_map; // Key: card value, Value: count
    for (int card : hand) {
      ++count_map[card];
    }
    return count_map;
  }

  // Helper function: tries to form 'cards_needed' groups starting at 'start'
  // Returns false if unable to do so
  bool canFormGroup(map<int, int> &count_map, int start, int groupSize,
                    int cards_needed) {
    // For each value in the group sequence from 'start' upwards
    for (int i = 0; i < groupSize; ++i) {
      int currCard = start + i;
      // Check if enough cards of this value are available
      if (count_map[currCard] < cards_needed)
        return false;
      // Deduct the cards used in the current group
      count_map[currCard] -= cards_needed;
      // If no more cards of this value left, erase it from the map to keep
      // iteration efficient
      if (count_map[currCard] == 0)
        count_map.erase(currCard);
    }
    // Successfully formed this group
    return true;
  }
};
// @lc code=end
