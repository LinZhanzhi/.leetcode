/*
 * @lc app=leetcode id=553 lang=cpp
 *
 * [553] Optimal Division
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given a list of integers, we want to insert parentheses into the division
 * expression formed by dividing the numbers in order, so that the result is as
 * large as possible. The goal is to return the string representation of this
 * maximized expression, with no unnecessary parentheses.
 *
 * The key insight is that, to maximize the result, we want the first number
 * divided by the smallest possible denominator. Since division is not
 * associative, grouping all numbers after the first into a single denominator
 * (i.e., first / (second / third / ... / last)) gives the largest value.
 *
 * High-Level Summary:
 * ----
 * - If there is only one number, return it as a string.
 * - If there are two numbers, return "a/b".
 * - For three or more numbers, the optimal expression is:
 *   "a/(b/c/d/.../z)" (i.e., the first number divided by the result of dividing
 *   all the rest in order).
 * - We build the string accordingly, ensuring no redundant parentheses.
 *
 * Time Complexity: O(n), where n is the number of elements in nums, since we
 * traverse the list once to build the string.
 * Space Complexity: O(n), for the output string and temporary string building.
 */

#include <sstream> // For std::ostringstream to build the result string
#include <string>  // For std::string
#include <vector>  // For std::vector

using std::ostringstream;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to generate the optimal division expression
  string optimalDivision(vector<int> &nums) {
    // Handle the case with only one number: just return it as a string
    if (nums.size() == 1) {
      return intToString(nums[0]);
    }
    // Handle the case with two numbers: return "a/b"
    if (nums.size() == 2) {
      return intToString(nums[0]) + "/" + intToString(nums[1]);
    }
    // For three or more numbers, group all but the first in parentheses
    // to maximize the result: "a/(b/c/d/...)"
    return buildOptimalExpression(nums);
  }

private:
  // Helper function to convert an integer to a string
  string intToString(int num) {
    // Use std::to_string for conversion
    return std::to_string(num);
  }

  // Helper function to build the optimal expression for n >= 3
  string buildOptimalExpression(const vector<int> &nums) {
    ostringstream oss;
    // Start with the first number
    oss << nums[0] << "/(";
    // Add the rest of the numbers, separated by '/'
    for (size_t i = 1; i < nums.size(); ++i) {
      if (i > 1) {
        oss << "/";
      }
      oss << nums[i];
    }
    oss << ")";
    // The parentheses are only around the denominator, as required
    return oss.str();
  }
};
// @lc code=end
