/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We need to compute a factorial-like expression where operations cycle through *, /, +, -.
 * The standard order of operations applies: * and / are processed before + and -.
 * Since * and / are left-associative and appear first in the cycle, we can process them immediately
 * as we iterate. + and - separate terms.
 *
 * High-Level Summary:
 * -------------------
 * We can simulate the evaluation using a stack (or vector) to handle operator precedence.
 * The stack will store terms that are to be summed up at the end.
 * - Initialize the stack with the first number \
\.
 * - Iterate from \
-1\ down to 1.
 * - Maintain an operation index (0 for *, 1 for /, 2 for +, 3 for -).
 * - If operation is * or /: Pop the top of the stack, perform the operation with the current number, and push the result back.
 *   This handles the higher precedence of multiplication and division.
 * - If operation is +: Push the current number.
 * - If operation is -: Push the negative of the current number. This effectively handles subtraction by adding a negative number later.
 * - Finally, sum all elements in the stack.
 *
 * Time Complexity: O(N), where N is the input integer. We iterate through numbers from N down to 1 once.
 * Space Complexity: O(N) in the worst case to store the terms in the stack.
 */

// @lc code=start
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int clumsy(int n) {
        vector<int> stack;
        stack.push_back(n);
        n--;

        int op = 0; // 0: *, 1: /, 2: +, 3: -

        while (n > 0) {
            if (op == 0) { // Multiplication
                int top = stack.back();
                stack.pop_back();
                stack.push_back(top * n);
            } else if (op == 1) { // Division
                int top = stack.back();
                stack.pop_back();
                stack.push_back(top / n);
            } else if (op == 2) { // Addition
                stack.push_back(n);
            } else { // Subtraction
                stack.push_back(-n);
            }

            n--;
            op = (op + 1) % 4;
        }

        // Sum up all terms in the stack
        return accumulate(stack.begin(), stack.end(), 0);
    }
};
// @lc code=end
