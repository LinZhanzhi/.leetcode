/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We start with a number startValue and want to reach 	arget.
 * Operations allowed: Multiply by 2, Subtract 1.
 * We want the minimum number of operations.
 *
 * High-Level Summary:
 * -------------------
 * It is easier to work backwards from 	arget to startValue.
 * The inverse operations are:
 * 1. Divide by 2 (if even).
 * 2. Add 1.
 *
 * Greedy Strategy:
 * - If 	arget > startValue:
 *   - If 	arget is even, we divide by 2. This reduces the number faster towards startValue than adding 1s.
 *   - If 	arget is odd, we are forced to add 1 to make it even, so we can divide in the next step.
 * - If 	arget <= startValue:
 *   - We can only increase 	arget by adding 1 (inverse of subtract 1).
 *   - The difference startValue - target is exactly the number of adds needed.
 *
 * Time Complexity: O(log(target)). We divide by 2 in roughly every other step.
 * Space Complexity: O(1).
 */

#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ops = 0;
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target++;
            }
            ops++;
        }
        // The remaining difference must be covered by subtractions (forward) / additions (backward)
        return ops + (startValue - target);
    }
};
// @lc code=end
