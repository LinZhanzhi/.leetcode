/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

/*
 * Brief Digested Understanding:
 * ----
 * The challenge is to minimize the number of bit flips required to transform a
 * given binary string into a "monotone increasing" string. A monotone
 * increasing binary string has all 0's (if any) to the left, followed by all
 * 1's (if any); the string never goes from '1' back to '0'. Each bit flip is a
 * change of any chosen '0' to '1' or vice versa, and we can flip any bits we
 * like.
 *
 * The heart of the problem is finding the optimal position to switch from 0's
 * to 1's—i.e., where to have the last '0' and first '1', so that the number of
 * necessary flips (fixing all 1's before to 0, all 0's after to 1) is
 * minimized.
 *
 * High-Level Summary:
 * ----
 * The main algorithm uses prefix sums:
 *   - Precompute for each index the running total of zeros—let cnt[i] be the
 *     number of zeros in s[0] to s[i-1] (exclusive).
 *   - For any split position i (from 0 up to n), consider making s[0:i] all 0's
 *     and s[i:n] all 1's.
 *   - Flips needed: For first part, flip all 1's to 0's (that's i minus the
 * count of zeros up to i), and for the second part, flip all 0's to 1's (that
 * is, the total number of zeros after position i, which is cnt[n] - cnt[i]).
 *   - The best solution is the minimum flip count over all possible splits.
 * This algorithm scans s just twice: once to build prefix counts, once to try
 * every split. Time complexity O(n), space complexity O(n) for the prefix
 * array.
 */

// @lc code=start

#include <algorithm> // For std::min
#include <string>    // Needed for std::string
#include <vector>    // For std::vector to store prefix sums

using std::min;
using std::string;
using std::vector;

class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int n = s.size();
    // Step 1: Build prefix sum of zeros
    vector<int> cnt = computeZeroPrefix(s);
    // Step 2: Find minimum flips required for all possible splits
    return calculateMinFlips(cnt, n);
  }

private:
  // Helper function: compute prefix sum of zeros; cnt[i] = number of '0's in
  // s[0..i-1]
  vector<int> computeZeroPrefix(const string &s) {
    int n = s.size();
    vector<int> cnt(n + 1, 0); // cnt[0]=0; cnt[i]=#zeros in s[0..i-1]
    for (int i = 1; i <= n; ++i) {
      // Add 1 to previous if s[i-1] is '0', else carry forward
      cnt[i] = cnt[i - 1] + (s[i - 1] == '0' ? 1 : 0);
    }
    return cnt;
  }
  // Helper function: find minimal flips by checking all splits
  int calculateMinFlips(const vector<int> &cnt, int n) {
    int result = n; // Initialize to maximal flips required
    // Try every split: first i chars as all 0's, rest as all 1's
    for (int i = 0; i <= n; ++i) {
      // Number of 1's to flip to 0 in prefix: i - cnt[i] (since cnt[i]=# of
      // 0's)
      int flips_ones_to_zero = i - cnt[i];
      // Number of 0's to flip to 1 in suffix: cnt[n] - cnt[i] (zeros after i)
      int flips_zeros_to_one = cnt[n] - cnt[i];
      int flips_needed = flips_ones_to_zero + flips_zeros_to_one;
      result = min(result, flips_needed);
    }
    return result;
  }
};
// @lc code=end
