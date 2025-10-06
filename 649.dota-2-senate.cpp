/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// Brief Digested Understanding:
// ----
// This problem is about simulating a voting and banning process between two
// parties (Radiant and Dire) in a round-based system. Each senator can either
// ban a senator from the opposing party or, if only their party remains,
// declare victory. The challenge is to predict which party will win if all
// senators play optimally, given the initial order of senators. The process
// continues in rounds, skipping banned senators, until one party is eliminated.

// High-Level Summary:
// ----
// We'll use two queues to track the indices of active Radiant and Dire
// senators. In each round, the senator with the lower index acts first and bans
// the next available senator from the opposing party. The acting senator is
// re-enqueued with their index incremented by the total number of senators (to
// simulate cycling to the next round). This continues until one queue is empty,
// at which point the other party wins. This approach efficiently simulates the
// process in O(n) time and O(n) space, where n is the number of senators.

// Include necessary headers for string and queue usage.
#include <queue>
#include <string>

using std::queue;
using std::string;

class Solution {
public:
  // Main function to predict which party will win
  string predictPartyVictory(string senate) {
    // Helper function to initialize the queues for both parties
    auto initializeQueues = [](const string &senate, queue<int> &radiant,
                               queue<int> &dire) {
      for (int i = 0; i < senate.size(); ++i) {
        if (senate[i] == 'R') {
          radiant.push(i); // Store index of Radiant senator
        } else {
          dire.push(i); // Store index of Dire senator
        }
      }
    };

    // Helper function to simulate the rounds until one party wins
    auto simulateRounds = [](queue<int> &radiant, queue<int> &dire,
                             int n) -> string {
      // Continue until one party has no senators left
      while (!radiant.empty() && !dire.empty()) {
        int rIndex = radiant.front();
        radiant.pop(); // Get next Radiant senator
        int dIndex = dire.front();
        dire.pop(); // Get next Dire senator

        // The senator with the lower index acts first and bans the other
        if (rIndex < dIndex) {
          // Radiant bans Dire; Radiant returns in next round
          radiant.push(rIndex + n);
        } else {
          // Dire bans Radiant; Dire returns in next round
          dire.push(dIndex + n);
        }
        // The banned senator is not re-enqueued, effectively removed
      }
      // If Radiant queue is not empty, Radiant wins; otherwise, Dire wins
      return radiant.empty() ? "Dire" : "Radiant";
    };

    // Queues to store indices of active senators for each party
    queue<int> radiant, dire;
    int n = senate.size(); // Total number of senators

    // Initialize the queues with the indices of each party's senators
    initializeQueues(senate, radiant, dire);

    // Simulate the rounds and return the winning party
    return simulateRounds(radiant, dire, n);
  }
};
// @lc code=end
