/*
 * @lc app=leetcode id=2511 lang=cpp
 *
 * [2511] Maximum Enemy Forts That Can Be Captured
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int captureForts(vector<int> &forts) {
    int n = forts.size();
    int ans = 0;
    int prev = -1; // Index of the last seen fort (either 1 or -1)
    for (int i = 0; i < n; ++i) {
      // Check if current position is a fort (either 1 or -1)
      if (forts[i] == 1 || forts[i] == -1) {
        // If there was a previous fort and the types are different (1 vs -1)
        if (prev != -1 && forts[i] != forts[prev]) {
          int cnt = 0;
          // Count the number of empty positions (0) between prev and i
          for (int k = prev + 1; k < i; ++k) {
            if (forts[k] == 0)
              ++cnt;
            else
              break; // If not empty, break (shouldn't happen in valid input)
          }
          // Only consider if all positions between prev and i are empty
          if (cnt == i - prev - 1) {
            ans = max(ans, cnt); // Update the answer with the maximum found
          }
        }
        prev = i; // Update prev to current fort position
      }
    }
    return ans;
  }
};
// @lc code=end
