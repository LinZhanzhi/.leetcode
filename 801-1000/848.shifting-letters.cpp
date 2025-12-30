/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */

// @lc code=start

#include <string> // Include for std::string usage
#include <vector> // Include for std::vector usage

using std::string;
using std::vector;

/*
 * Brief Digested Understanding:
 * ------------
 * This problem is about applying a set of cumulative shift operations to a
 * string of lowercase letters. Each position in the 'shifts' array indicates
 * how many times the first i+1 characters (from the start to the ith letter)
 * should be shifted forward in the alphabet (with wraparound: 'z'→'a'). Shifts
 * are cumulative, so later shifts include all previous. The final result is the
 * letters after all shift operations have been applied.
 *
 * High-Level Summary:
 * ------------
 * We need to process the input efficiently, since a naive O(n^2) approach is
 * too slow for large n. The trick is to observe that, for each position, the
 * total shifts is the sum of all shifts starting from that position to the end.
 * So, we process the 'shifts' vector in reverse to compute cumulative sums.
 * Then, we shift each character accordingly, using modulo 26 to wrap around the
 * alphabet. We use helper functions to modularize the logic for computing
 * cumulative shifts and shifting characters. Time complexity is O(n) and space
 * complexity is O(n).
 */

// Helper function to compute cumulative shifts from right to left
vector<long long> computeCumulativeShifts(const vector<int> &shifts) {
  int n = shifts.size();
  vector<long long> cumShifts(n, 0); // Use long long for large shift sums
  long long total = 0;
  // Traverse from the end, accumulating the total shifts
  for (int i = n - 1; i >= 0; --i) {
    total += shifts[i];
    cumShifts[i] = total;
  }
  return cumShifts;
}

// Helper function to shift a lowercase letter by k positions (with wrap-around)
char shiftLetter(char original, long long shiftAmount) {
  // 'a' has ASCII code 97; 'z' is 122
  // Modulo 26 ensures wraparound if shiftAmount is large
  int alphaIndex = original - 'a';
  int shiftedIndex = (alphaIndex + shiftAmount) % 26;
  // Ensure proper wrap-around for very large shifts
  return static_cast<char>('a' + shiftedIndex);
}

class Solution {
public:
  string shiftingLetters(string s, vector<int> &shifts) {
    // Compute cumulative shifts for each letter from right to left
    vector<long long> cumShifts = computeCumulativeShifts(shifts);

    // Create a mutable copy of the result string, same as input
    string result = s;

    // Apply the shift to each character using precomputed shifts
    for (int i = 0; i < result.size(); ++i) {
      result[i] = shiftLetter(result[i], cumShifts[i]);
    }

    // Return the shifted string
    return result;
  }
};
// @lc code=end
