/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// Brief Digested Understanding:
// -----
// The problem wants us to construct an array of the numbers 1 through n (i.e.,
// a permutation) such that, between any two positions i < j, there's no index k
// in-between where the value at k is exactly the mean (average) of the values
// at i and j. In other words, we can't have three indices that make an
// arithmetic progression in the values. The goal is to return any such valid
// array; this is called a "beautiful array".

// High-Level Summary:
// -----
// The core idea is to construct the array recursively in such a way that the
// "beautiful" property is always maintained. We use divide-and-conquer: For a
// given size n, we recursively create two beautiful arrays—one for the odd
// indices and one for the even indices. We then combine them: the "odd" part is
// just the beautiful array of size (n+1)/2, with all its elements multiplied by
// 2 and subtracted by 1 (so they cover all odd numbers up to n); the "even"
// part is from n/2, with all its elements multiplied by 2 (covers even numbers
// up to n). The merge of those arrays is always beautiful because all possible
// triplets (i, k, j with i < k < j) will never satisfy the forbidden equation.
// This solution has time complexity O(n), as each element is generated just
// once, and space complexity O(n) for the output.

// Import required STL header for vector
#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function that returns a beautiful array of size n
  vector<int> beautifulArray(int n) {
    // Start the recursive construction
    return constructBeautifulArray(n);
  }

private:
  // Helper function to recursively build a beautiful array for numbers 1..n
  vector<int> constructBeautifulArray(int n) {
    // Base case: if the array has only one element, it's trivially beautiful
    if (n == 1) {
      return vector<int>{1};
    }

    // Step 1: Recursively construct the "odd" part (all odd positions)
    // The beautiful array for ceil(n/2) elements
    vector<int> odds = constructBeautifulArray((n + 1) / 2);
    // Step 2: Recursively construct the "even" part (all even positions)
    // The beautiful array for floor(n/2) elements
    vector<int> evens = constructBeautifulArray(n / 2);

    // Step 3: Transform recursive results to proper values for this level
    vector<int> res;
    // All odd indices: multiply by 2 then subtract 1 to get all odd numbers up
    // to n
    for (int x : odds) {
      res.push_back(2 * x - 1);
    }
    // All even indices: multiply by 2 to get all even numbers up to n
    for (int x : evens) {
      res.push_back(2 * x);
    }
    // The result array is now a permutation of [1..n], maintaining the
    // "beautiful" property
    return res;
  }
};
// @lc code=end
