/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given a positive integer n, we want to find the next greater number that can
 * be formed by rearranging its digits. The new number must use exactly the same
 * digits as n, be strictly greater than n, and fit within a 32-bit signed
 * integer. If no such number exists (i.e., n is the largest permutation of its
 * digits), we return -1.
 *
 * High-Level Summary:
 * ----
 * The problem is a variant of the "next permutation" problem for arrays of
 * digits. The main steps are:
 *   1. Convert the integer n into a list of its digits for easy manipulation.
 *   2. Find the first digit (from right to left) that is smaller than a digit
 * to its right (the "pivot").
 *   3. If no such digit exists, n is the largest permutation, so return -1.
 *   4. Otherwise, find the smallest digit to the right of the pivot that is
 * larger than the pivot, and swap them.
 *   5. Reverse the digits to the right of the pivot to get the smallest
 * possible number greater than n.
 *   6. Convert the digits back to an integer and check if it fits in 32 bits.
 *   7. Return the result or -1 if it overflows.
 *
 * Time Complexity: O(k), where k is the number of digits in n (since each step
 * is linear in the number of digits). Space Complexity: O(k), for storing the
 * digits.
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  // Main function to find the next greater element with the same digits
  int nextGreaterElement(int n) {
    // Step 1: Convert integer n to a vector of its digits
    std::vector<int> digits = intToDigits(n);

    // Step 2: Find the pivot - the first digit from the right that is smaller
    // than its next digit
    int pivot = findPivot(digits);

    // If no pivot is found, the digits are in descending order (largest
    // permutation)
    if (pivot == -1) {
      return -1;
    }

    // Step 3: Find the smallest digit on the right of the pivot that is larger
    // than the pivot digit
    int swapIdx = findSmallestLarger(digits, pivot);

    // Step 4: Swap the pivot with this digit
    std::swap(digits[pivot], digits[swapIdx]);

    // Step 5: Reverse the digits to the right of the pivot to get the smallest
    // possible number
    std::reverse(digits.begin() + pivot + 1, digits.end());

    // Step 6: Convert the digits back to an integer
    long long result = digitsToInt(digits);

    // Step 7: Check if the result fits in 32 bits and is greater than n
    if (result > INT_MAX) {
      return -1;
    }
    return static_cast<int>(result);
  }

private:
  // Helper function to convert an integer to a vector of its digits
  std::vector<int> intToDigits(int n) {
    std::vector<int> digits;
    // Extract digits from right to left
    while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
    }
    // The digits are in reverse order, so reverse them to get the correct order
    std::reverse(digits.begin(), digits.end());
    return digits;
  }

  // Helper function to find the pivot index
  // Returns the index of the first digit from the right that is smaller than
  // its next digit
  int findPivot(const std::vector<int> &digits) {
    int n = digits.size();
    // Traverse from right to left
    for (int i = n - 2; i >= 0; --i) {
      if (digits[i] < digits[i + 1]) {
        return i;
      }
    }
    // No pivot found
    return -1;
  }

  // Helper function to find the smallest digit larger than digits[pivot] to the
  // right of pivot
  int findSmallestLarger(const std::vector<int> &digits, int pivot) {
    int n = digits.size();
    int idx = n - 1;
    // Find the rightmost digit greater than digits[pivot]
    while (idx > pivot && digits[idx] <= digits[pivot]) {
      --idx;
    }
    return idx;
  }

  // Helper function to convert a vector of digits back to an integer
  long long digitsToInt(const std::vector<int> &digits) {
    long long num = 0;
    for (int d : digits) {
      num = num * 10 + d;
    }
    return num;
  }
};
// @lc code=end
