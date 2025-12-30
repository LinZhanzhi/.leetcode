/*
 * @lc app=leetcode id=970 lang=cpp
 *
 * [970] Powerful Integers
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to find all integers  such that  = x^i + y^j where i, j >= 0 and  <= bound.
 * The result should contain unique integers.
 *
 * High-Level Summary:
 * -------------------
 * Since ound is limited to 10^6, the powers of x and y (if x, y > 1) grow very quickly.
 * Even for the smallest base 2, 2^20 > 10^6. Thus, we can simply iterate through all possible powers of x and y.
 * We use nested loops. The outer loop iterates through powers of x, and the inner loop through powers of y.
 * We stop when the sum exceeds ound.
 * Special care must be taken when x = 1 or y = 1, as 1^k is always 1, which would lead to an infinite loop if not handled.
 * We use a std::unordered_set to store the results to ensure uniqueness.
 *
 * Time Complexity: O(log_x(bound) * log_y(bound)). With bound=10^6, this is very small (approx 20*20 iterations).
 * Space Complexity: O(result size) to store the output.
 */

#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> unique_powerful_integers;
        
        // Iterate through powers of x: x^0, x^1, ...
        // i represents x^a. Start at 1 (x^0).
        // We stop if i >= bound because the smallest term for y is 1 (y^0), so i + 1 must be <= bound.
        for (int i = 1; i < bound; i *= x) {
            // Iterate through powers of y: y^0, y^1, ...
            // j represents y^b. Start at 1 (y^0).
            for (int j = 1; i + j <= bound; j *= y) {
                unique_powerful_integers.insert(i + j);
                if (y == 1) break; // If y is 1, powers don't increase, avoid infinite loop
            }
            if (x == 1) break; // If x is 1, powers don't increase, avoid infinite loop
        }
        
        return vector<int>(unique_powerful_integers.begin(), unique_powerful_integers.end());
    }
};
// @lc code=end
