/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to create a function rand10() that returns a random integer from
 * 1 to 10, with each number being equally likely. However, we are only allowed
 * to use rand7(), which gives a random integer from 1 to 7. We must combine
 * calls to rand7() in a way that produces a uniform distribution over 1 to 10,
 * without using any other random number generator.
 *
 * High-Level Summary:
 * ----
 * The main idea is to use rand7() to generate a larger range of random numbers,
 * specifically numbers from 1 to 49 (since 7*7=49), by combining two calls to
 * rand7(). We then map the numbers 1 to 40 to 1 to 10 (since 40 is the largest
 * multiple of 10 less than or equal to 49), and reject any result above 40 to
 * maintain uniformity. If we reject, we repeat the process. This is called
 * "rejection sampling." The expected number of rand7() calls is about 2.45 per
 * rand10() call.
 *
 * Time Complexity: O(1) expected (since the probability of rejection is low and
 * bounded). Space Complexity: O(1) (no extra space used).
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
  // Helper function to generate a random integer in [1, 49] using two rand7()
  // calls
  int rand49() {
    // rand7() - 1 gives a value in [0, 6]
    // Multiply by 7 to get [0, 42] in steps of 7
    // Add rand7() to get [1, 49]
    int row = rand7() - 1; // [0, 6]
    int col = rand7();     // [1, 7]
    return row * 7 + col;  // [1, 49]
  }

  // Main function to generate a random integer in [1, 10]
  int rand10() {
    while (true) {
      int num = rand49(); // Generate a number in [1, 49]
      // Only accept if num is in [1, 40] to ensure uniform mapping to [1, 10]
      if (num <= 40) {
        // Map 1-40 to 1-10 uniformly
        // (num - 1) % 10 gives [0, 9], add 1 to get [1, 10]
        return 1 + (num - 1) % 10;
      }
      // If num > 40, reject and repeat to avoid bias
      // This ensures each number in [1, 10] has equal probability
    }
  }
};
// @lc code=end
