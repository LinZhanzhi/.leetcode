/*
 * @lc app=leetcode id=2335 lang=cpp
 *
 * [2335] Minimum Amount of Time to Fill Cups
 *
 * Detailed Proof:
 *
 * Problem: You have three types of cups, each with a certain number of cups to
 * fill (amount[0], amount[1], amount[2]). Each second, you can fill up to two
 * cups of different types (or just one cup of any type). What is the minimum
 * number of seconds needed to fill all cups?
 *
 * Solution Explanation:
 *
 * Let a, b, c be the numbers in amount[], sorted so that a <= b <= c.
 *
 * At each second, you can fill two cups of different types, so the maximum you
 * can reduce the total sum by is 2 per second.
 *
 * 1. Lower Bound 1 (by total sum):
 *    - The total number of cups to fill is sum = a + b + c.
 *    - Since you can fill at most 2 cups per second, you need at least ceil(sum
 * / 2) seconds.
 *
 * 2. Lower Bound 2 (by largest pile):
 *    - You cannot fill more than one cup of the same type per second.
 *    - So, to fill the largest pile (say, c), you need at least c seconds.
 *
 * 3. The answer is the maximum of these two lower bounds:
 *    - If c > (a + b), then you will be left with only c cups of one type, and
 * you can only fill one per second.
 *    - If c <= (a + b), you can always pair the largest pile with the other
 * two, so the total time is ceil(sum / 2).
 *
 * Therefore, the answer is max(max(amount), (sum + 1) / 2).
 *
 * Example:
 *   amount = [1, 4, 2]
 *   sum = 7, max = 4
 *   (sum + 1) / 2 = 4
 *   max(4, 4) = 4
 *
 *   amount = [5, 4, 4]
 *   sum = 13, max = 5
 *   (13 + 1) / 2 = 7
 *   max(5, 7) = 7
 *
 * This formula always gives the minimum time.
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int fillCups(vector<int> &amount) {
    // See detailed proof above for why this formula is correct.
    int sum = amount[0] + amount[1] + amount[2];
    int mx = max({amount[0], amount[1], amount[2]});
    return max(mx, (sum + 1) / 2);
  }
};
// @lc code=end
