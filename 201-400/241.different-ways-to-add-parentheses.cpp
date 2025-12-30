/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to compute all possible results from different ways of
 * adding parentheses in a string expression containing numbers and the
 * operators '+', '-', and '*'. Each way of grouping the numbers and operators
 * (by adding parentheses) can yield a different result, and we need to return
 * all such possible results.
 *
 * In essence, for every operator in the expression, we can split the expression
 * into two parts (left and right of the operator), recursively compute all
 * possible results for each part, and then combine them using the operator. If
 * the expression is just a number (no operators), the result is the number
 * itself.
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses recursion (divide and conquer) to split the expression at
 * every operator, recursively solve the left and right sub-expressions, and
 * combine their results using the operator. This way, we explore all possible
 * ways to parenthesize the expression. To optimize repeated calculations, we
 * use memoization (caching) to store results for sub-expressions we've already
 * computed.
 *
 * - Main Algorithm: Recursively split at each operator, combine all left and
 * right results.
 * - Memoization: Use an unordered_map to cache results for sub-expressions.
 * - Time Complexity: Exponential in the number of operators (since each
 * operator can be a split point), but memoization helps avoid redundant work.
 * - Space Complexity: O(N * M), where N is the number of unique sub-expressions
 * and M is the average number of results per sub-expression.
 */

#include <string>        // For std::string to handle the expression.
#include <unordered_map> // For memoization (caching sub-expression results).
#include <vector>        // For std::vector to store results.

using std::string;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to compute all possible results for the given expression.
  vector<int> diffWaysToCompute(string expression) {
    // Memoization map to cache results for sub-expressions.
    unordered_map<string, vector<int>> memo;
    // Call the recursive helper function.
    return compute(expression, memo);
  }

private:
  // Helper function that recursively computes all possible results for expr.
  // Uses memoization to avoid redundant calculations.
  vector<int> compute(const string &expr,
                      unordered_map<string, vector<int>> &memo) {
    // If we've already computed results for this sub-expression, return them.
    if (memo.count(expr)) {
      return memo[expr];
    }

    vector<int> results; // To store all possible results for this expr.

    // Flag to check if we found any operator in the expression.
    bool hasOperator = false;

    // Iterate through the expression to find operators.
    for (size_t i = 0; i < expr.size(); ++i) {
      char c = expr[i];
      // If the current character is an operator, split and recurse.
      if (c == '+' || c == '-' || c == '*') {
        hasOperator = true;
        // Split the expression into left and right parts.
        string left = expr.substr(0, i);
        string right = expr.substr(i + 1);

        // Recursively compute all possible results for left and right.
        vector<int> leftResults = compute(left, memo);
        vector<int> rightResults = compute(right, memo);

        // Combine each result from left and right using the operator.
        for (int l : leftResults) {
          for (int r : rightResults) {
            int res = 0;
            if (c == '+') {
              res = l + r;
            } else if (c == '-') {
              res = l - r;
            } else if (c == '*') {
              res = l * r;
            }
            results.push_back(res);
          }
        }
      }
    }

    // If no operator was found, the expression is a number.
    if (!hasOperator) {
      // Convert the string to an integer and return as the only result.
      results.push_back(std::stoi(expr));
    }

    // Cache the results for this sub-expression.
    memo[expr] = results;
    return results;
  }
};
// @lc code=end
