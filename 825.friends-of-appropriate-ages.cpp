/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * [825] Friends Of Appropriate Ages
 */

// Brief Digested Understanding:
// -----
// This problem is about simulating a social network where people can send
// friend requests if certain age-based rules are met. For every person, we want
// to count all valid other people to whom they could send a friend request. The
// challenge is to efficiently count valid pairs without checking every possible
// pair (which would be too slow). The main constraints to check are: minimum
// and maximum bounds on age differences, and special rules for those over 100
// years old.

// High-Level Summary:
// -----
// We'll solve this problem by counting how many pairs of people compare as
// valid sender-receiver pairs, according to the given age rules. Instead of
// brute-forcing all possible pairs, we first count how many people there are of
// each age. Then, for each possible sender's age, we use prefix sums to quickly
// count, for all possible recipients, how many fall in the valid age range for
// this sender. We ensure people don't send requests to themselves, and handle
// the special "age > 100 && other < 100" case. This method achieves O(A) time,
// where A is the age range (max 120), and O(N+A) space. It's much faster than
// O(N^2) and is feasible for large inputs.
//
// Time Complexity: O(N + A)
// Space Complexity: O(A)   (A ≤ 120)
// (where N is the number of people, A is maximum age+1)

// @lc code=start
#include <algorithm> // For sorting and max/min.
#include <vector>    // Import the standard vector container for input.

using std::vector; // Bring vector into scope for brevity.

class Solution {
public:
  // Helper function to compute lower bound of valid friend recepient age
  int getMinAcceptableAge(int age) {
    // Based on the rule: recipient > 0.5 * age + 7
    // So the minimum age to receive a friend request is floor(0.5*age + 7) + 1
    return age / 2 + 8;
  }

  int numFriendRequests(vector<int> &ages) {
    // Step 1: Count how many people there are for each age
    // The ages range from 1 to 120 inclusive.
    const int MAX_AGE = 120;
    vector<int> ageCount(MAX_AGE + 1,
                         0); // ageCount[i] = number of people aged i
    for (int age : ages)
      ++ageCount[age];

    // Step 2: Build a prefix sum so we can count #people <= age in O(1) time
    vector<int> prefix(MAX_AGE + 1,
                       0); // prefix[i] = total #people with age <= i
    for (int i = 1; i <= MAX_AGE; ++i)
      prefix[i] = prefix[i - 1] + ageCount[i];

    int total = 0; // Holds the total number of friend requests

    // Step 3: For each possible sender's age, compute requests they make
    for (int ageA = 1; ageA <= MAX_AGE; ++ageA) {
      int countA = ageCount[ageA]; // Number of people of ageA
      if (countA == 0)
        continue; // No senders at this age

      // The youngest valid recipient this sender would consider
      int minB = getMinAcceptableAge(ageA);
      int maxB = ageA; // They can't send to anyone older than themselves

      if (minB > maxB)
        continue; // No valid recipients for this sender's age

      // Exclude recipients over 100 if sender is under 100:
      // This is handled automatically since for ageA < 100, no one with age >
      // 100 will be included.

      // For ageA > 100, it's allowed to send to age > 100.
      // For each age in [minB, maxB], sum up all recipients at that age.
      int possibleRecipients = prefix[maxB] - prefix[minB - 1];

      // Subtract one because a person cannot send a request to themselves
      // (i.e., person of ageA cannot send to themselves)
      // Each pair (x, y) where x != y: so for ageA, need to subtract the countA
      // (would-be self pairs) Each person of ageA can send to
      // (possibleRecipients - 1) * countA But since people of ageA can send to
      // people of that age (not themselves), for all pairs: For each person in
      // countA, there are (possibleRecipients - 1) other people, so total
      // requests:
      total += countA * (possibleRecipients - 1);
    }

    return total;
  }
};
// @lc code=end
