/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 */

// @lc code=start
#include <climits> // For INT_MAX to check for overflow
#include <string>  // For std::string for handling the input
#include <vector>  // For std::vector to store the sequence

using std::string;
using std::vector;

/**
 * Brief Digested Understanding:
 * ----
 * The core challenge in this problem is to split a given string of digits
 * into a sequence of integers that mimics the Fibonacci property: each number
 * (starting from the third) is the sum of the previous two, and the sequence
 * has at least three numbers. Each piece must not have extra leading zeroes,
 * and every number must fit in a 32-bit signed integer. The goal is to find
 * (any) such valid sequence or return an empty list if impossible.
 * The key ideas are careful handling of substring extraction, avoidance of
 * overflows, and recursive "try-and-backtrack" exploration for possible splits.
 *
 * High-Level Summary:
 * ----
 * We'll use a backtracking approach that tries all possible first and second
 * number splits, then recursively tries to build the rest, always obeying
 * the Fibonacci sum property. We'll check edge cases like integer overflow
 * and leading zeros at every step. The algorithm checks all splits with
 * nested loops and prunes search spaces once it's clear a valid sequence is
 * impossible. Complexity is O(N^2) for first two numbers, but is pruned
 * by Fibonacci constraints and string length (max 200), so it's tractable.
 * Space complexity is O(N) due to recursion and storage of the sequence.
 */

// Helper function to safely convert a substring to an integer,
// returning -1 if the substring would overflow 32-bit integer or has bad
// leading zeros.
int safeStringToInt(const string &s, int start, int end) {
  // s: the source string
  // start, end: inclusive indices [start, end] for the substring
  // Returns the integer value, or -1 if overflow or malformed
  if (start > end)
    return -1;
  if (s[start] == '0' && start != end)
    return -1; // Leading zeros not allowed (except single '0')
  long long val = 0;
  for (int i = start; i <= end; ++i) {
    val = val * 10 + (s[i] - '0');
    if (val > INT_MAX)
      return -1; // Overflow detected
  }
  return static_cast<int>(val);
}

// Helper recursive function to backtrack and try to build a Fibonacci sequence.
// Returns true if a valid split is found.
bool backtrack(const string &num, int pos, vector<int> &sequence) {
  // pos: current character position in string 'num' to be split next
  // sequence: current Fibonacci sequence we've built so far
  if (pos == num.size()) {
    // If we've used all digits and sequence has at least 3 numbers, it's valid
    return sequence.size() >= 3;
  }
  // Try all possible next number-endings for this position, up to 10 digits (to
  // fit 32 bits)
  for (int i = pos; i < num.size(); ++i) {
    // Prune numbers with leading zeroes
    if (num[pos] == '0' && i > pos)
      break;
    // Parse substring num[pos...i]
    int nextNum = safeStringToInt(num, pos, i);
    if (nextNum == -1)
      break; // Invalid parse or overflow: no need to continue extending further
    int seqLen = sequence.size();
    // If sequence has 2+ numbers, check if this number fulfills the Fibonacci
    // property
    if (seqLen >= 2) {
      long sum = (long)sequence[seqLen - 2] + (long)sequence[seqLen - 1];
      if (nextNum < sum)
        continue; // Need a bigger number, so keep growing i
      if (nextNum > sum)
        break; // Too big, going further will only get bigger - stop here
               // else, nextNum == sum: valid step, continue below
    }
    // Add nextNum to the sequence
    sequence.push_back(nextNum);
    // Recursively attempt the rest of the string
    if (backtrack(num, i + 1, sequence)) {
      return true; // Success: sequence in "sequence" is valid
    }
    // Otherwise, backtrack (remove last number and try next i)
    sequence.pop_back();
  }
  // No valid sequence found from this configuration
  return false;
}

class Solution {
public:
  vector<int> splitIntoFibonacci(string num) {
    vector<int> sequence;
    // Try to construct the sequence using backtracking from position 0
    if (backtrack(num, 0, sequence)) {
      return sequence;
    } else {
      // Return empty vector if not possible
      return {};
    }
  }
};
// @lc code=end
