/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to find all elements in an array that appear more than ⌊
 * n/3 ⌋ times, where n is the size of the array. Since n/3 can be at most 2
 * elements (because 3 * 2 < n * 2), there can be at most two such majority
 * elements. The challenge is to do this efficiently, ideally in linear time and
 * constant space.
 *
 * High-Level Summary:
 * ----
 * We use a modified version of the Boyer-Moore Voting Algorithm. The idea is to
 * keep track of up to two potential candidates for the majority element and
 * their counts. In the first pass, we identify these candidates. In the second
 * pass, we verify if they actually appear more than n/3 times. This approach
 * ensures O(n) time and O(1) space complexity.
 *
 * Example with Step-by-Step Simulation:
 * ----
 * Let's walk through the algorithm for input nums = [9,9,9,9,2,3,4,5,6,7]:
 *
 * First Pass (Finding Candidates):
 *   - Initialize: candidate1 = 0, count1 = 0; candidate2 = 1, count2 = 0
 *   - Step 1: num = 9
 *       - count1 == 0, so candidate1 = 9, count1 = 1
 *       - [candidate1 = 9, count1 = 1], [candidate2 = 1, count2 = 0]
 *   - Step 2: num = 9
 *       - num == candidate1, count1++
 *       - [candidate1 = 9, count1 = 2], [candidate2 = 1, count2 = 0]
 *   - Step 3: num = 9
 *       - num == candidate1, count1++
 *       - [candidate1 = 9, count1 = 3], [candidate2 = 1, count2 = 0]
 *   - Step 4: num = 9
 *       - num == candidate1, count1++
 *       - [candidate1 = 9, count1 = 4], [candidate2 = 1, count2 = 0]
 *   - Step 5: num = 2
 *       - count2 == 0, so candidate2 = 2, count2 = 1
 *       - [candidate1 = 9, count1 = 4], [candidate2 = 2, count2 = 1]
 *   - Step 6: num = 3
 *       - num != candidate1 and num != candidate2, both counts non-zero, so
 * count1--, count2--
 *       - [candidate1 = 9, count1 = 3], [candidate2 = 2, count2 = 0]
 *   - Step 7: num = 4
 *       - count2 == 0, so candidate2 = 4, count2 = 1
 *       - [candidate1 = 9, count1 = 3], [candidate2 = 4, count2 = 1]
 *   - Step 8: num = 5
 *       - num != candidate1 and num != candidate2, both counts non-zero, so
 * count1--, count2--
 *       - [candidate1 = 9, count1 = 2], [candidate2 = 4, count2 = 0]
 *   - Step 9: num = 6
 *       - count2 == 0, so candidate2 = 6, count2 = 1
 *       - [candidate1 = 9, count1 = 2], [candidate2 = 6, count2 = 1]
 *   - Step 10: num = 7
 *       - num != candidate1 and num != candidate2, both counts non-zero, so
 * count1--, count2--
 *       - [candidate1 = 9, count1 = 1], [candidate2 = 6, count2 = 0]
 *
 * After the first pass, candidates are candidate1 = 9, candidate2 = 6.
 *
 * Second Pass (Verifying Candidates):
 *   - Count occurrences of candidate1 (9) and candidate2 (6):
 *       - candidate1 (9) appears 4 times
 *       - candidate2 (6) appears 1 time
 *   - n = 10, n/3 = 3
 *   - Only candidate1 (9) appears more than 3 times.
 *
 * Final Output: [9]
 *
 */

#include <vector>  // Include vector for using std::vector
using std::vector; // Bring vector into the current namespace

// @lc code=start
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    // This function finds all elements that appear more than n/3 times in the
    // array. There can be at most two such elements.

    int n = nums.size(); // Get the size of the input array

    // Initialize two potential candidates and their counts.
    // We use arbitrary initial values for candidates.
    int candidate1 = 0,
        candidate2 = 1; // Use different initial values to avoid collision
    int count1 = 0, count2 = 0;

    // First pass: Find up to two candidates that could be majority elements.
    for (int num : nums) {
      if (num == candidate1) {
        // If current number matches candidate1, increment its count
        count1++;
      } else if (num == candidate2) {
        // If current number matches candidate2, increment its count
        count2++;
      } else if (count1 == 0) {
        // If count1 is zero, assign current number as candidate1
        candidate1 = num;
        count1 = 1;
      } else if (count2 == 0) {
        // If count2 is zero, assign current number as candidate2
        candidate2 = num;
        count2 = 1;
      } else {
        // If current number matches neither candidate and both counts are
        // non-zero, decrement both counts (this "cancels out" a set of three
        // different numbers)
        count1--;
        count2--;
      }
    }

    // Second pass: Verify the actual counts of the candidates
    count1 = 0;
    count2 = 0;
    for (int num : nums) {
      if (num == candidate1)
        count1++;
      else if (num == candidate2)
        count2++;
    }

    // Prepare the result vector
    vector<int> result;
    // Only add candidates that appear more than n/3 times
    if (count1 > n / 3)
      result.push_back(candidate1);
    if (count2 > n / 3)
      result.push_back(candidate2);

    return result;
  }
};
// @lc code=end
