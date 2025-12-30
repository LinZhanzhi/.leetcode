/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem is about figuring out how many unique ways the bulbs can be
 * on/off after a certain number of button presses, given four different
 * flipping operations. Each button flips a specific subset of bulbs, and you
 * can press any button any number of times (up to the total allowed presses).
 * The challenge is to count the number of unique bulb patterns you can get
 * after exactly the given number of presses, not to enumerate them.
 *
 * The key insight is that for large n, the effect of the buttons repeats in a
 * pattern, so you only need to consider the first few bulbs (up to 6) to
 * capture all possible unique states. Also, pressing the same button twice
 * cancels its effect, so only the parity (odd/even) of presses for each button
 * matters.
 */

/*
 * High-Level Summary:
 * ----
 * We model the problem as a state space where each state is a possible on/off
 * pattern of the bulbs. Since the effect of the buttons repeats every 6 bulbs,
 * we only need to consider the first min(n, 6) bulbs. Each button can be
 * pressed or not (parity matters), so there are at most 2^4 = 16 possible
 * button press combinations. For each combination, if the total number of
 * presses used matches the allowed presses (modulo 2), we simulate the effect
 * and record the resulting bulb pattern. The answer is the number of unique
 * patterns generated this way.
 *
 * Time Complexity: O(1) (since n and presses are capped by 6 and 4,
 * respectively) Space Complexity: O(1) (since the number of possible states is
 * constant)
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  // Helper function to apply a button operation to the bulbs
  void applyButton(std::vector<int> &bulbs, int button) {
    int sz = bulbs.size();
    if (button == 0) {
      // Button 1: Flip all bulbs
      for (int i = 0; i < sz; ++i)
        bulbs[i] ^= 1;
    } else if (button == 1) {
      // Button 2: Flip even-labeled bulbs (1-based: 2,4,...; 0-based: 1,3,...)
      for (int i = 1; i < sz; i += 2)
        bulbs[i] ^= 1;
    } else if (button == 2) {
      // Button 3: Flip odd-labeled bulbs (1-based: 1,3,...; 0-based: 0,2,...)
      for (int i = 0; i < sz; i += 2)
        bulbs[i] ^= 1;
    } else if (button == 3) {
      // Button 4: Flip bulbs with label j = 3k+1 (1-based: 1,4,7,...; 0-based:
      // 0,3,6,...)
      for (int i = 0; i < sz; ++i) {
        if (i % 3 == 0)
          bulbs[i] ^= 1;
      }
    }
  }

  // Helper function to convert bulb vector to a string for uniqueness
  std::string bulbsToString(const std::vector<int> &bulbs) {
    std::string s;
    for (int b : bulbs)
      s += (b ? '1' : '0');
    return s;
  }

  int flipLights(int n, int presses) {
    // For n > 6, the pattern repeats, so only first 6 bulbs matter
    int sz = std::min(n, 6);

    // Use a set to store unique bulb patterns
    std::unordered_set<std::string> seen;

    // There are 4 buttons, so 2^4 = 16 possible press combinations
    for (int mask = 0; mask < 16; ++mask) {
      // Count how many buttons are pressed in this combination
      int cnt = __builtin_popcount(mask);
      // The total number of presses used must have the same parity as 'presses'
      // and must not exceed 'presses'
      if (cnt > presses || (cnt % 2 != presses % 2))
        continue;

      // Start with all bulbs on (1)
      std::vector<int> bulbs(sz, 1);

      // For each button, if it's pressed in this combination, apply its effect
      for (int btn = 0; btn < 4; ++btn) {
        if (mask & (1 << btn)) {
          applyButton(bulbs, btn);
        }
      }

      // Convert the bulbs' state to a string and add to the set
      seen.insert(bulbsToString(bulbs));
    }

    // The number of unique patterns is the answer
    return seen.size();
  }
};
// @lc code=end
