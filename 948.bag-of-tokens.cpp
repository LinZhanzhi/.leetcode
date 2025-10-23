/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// Brief Digested Understanding:
// ----
// This problem is about maximizing your score by wisely spending and regaining
// "power" using tokens of varying "cost". You can spend power for score
// (face-up), or "spend" score for more power (face-down), but each token can
// only be used once and only in one way. The challenge is to sequence plays -
// sometimes regaining power via face-down play helps you reach a higher total
// score by unlocking more face-up moves. The goal is to plan plays for the best
// possible score, starting from zero score and an initial power value.
//
// High-Level Summary:
// ----
// The core algorithm sorts the tokens from smallest to largest, making it
// easier to identify which tokens are cheap to flip face-up and which are most
// rewarding to flip face-down. Using a two-pointer (greedy) approach:
// - Whenever possible, spend power on the lowest-cost available token (left
// pointer) for a score.
// - If you can't afford a face-up play but have at least 1 score, play the
// highest-cost remaining
//   token (right pointer) face-down to regain power.
// - Repeat as long as progress is possible, always tracking the max score seen.
// The process leverages sorting for a natural greedy progression, and two
// pointers to ensure tokens are never double-used. The expected time complexity
// is O(N log N) due to sorting, and space is O(1) beyond the input array (which
// we sort in-place).

#include <algorithm> // For std::sort
#include <vector>    // To use std::vector for the tokens input

using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to compute the max score achievable
  int bagOfTokensScore(vector<int> &tokens, int power) {
    // Sort tokens to allow two-pointer greedy strategy
    std::sort(tokens.begin(), tokens.end());

    // Helper: Simulate the greedy process
    return getMaxScore(tokens, power);
  }

private:
  // Helper function that uses two pointers to maximize score
  int getMaxScore(const vector<int> &tokens, int power) {
    int left = 0; // Start pointer (smallest tokens)
    int right =
        static_cast<int>(tokens.size()) - 1; // End pointer (largest tokens)
    int score = 0;                           // Current score in play
    int maxScore = 0; // Best score achieved during iteration

    // Continue as long as there are unplayed tokens
    while (left <= right) {
      // Face-up play: Use the smallest token, if affordable
      if (left <= right && power >= tokens[left]) {
        power -= tokens[left]; // Spend power for score
        score += 1;            // Gain a score point
        ++left;                // Move to next smallest token
        if (score > maxScore)  // Update max score seen
          maxScore = score;
      }
      // Face-down play: Use largest token to regain power, if you have score to
      // spend
      else if (score >= 1 && left < right) {
        power += tokens[right]; // Regain power by sacrificing a score
        score -= 1;
        --right; // Token cannot be reused
                 // maxScore does not increase in this branch
      }
      // No play is possible; break loop
      else {
        break;
      }
    }
    return maxScore; // Return the highest score reached
  }
};
// @lc code=end
