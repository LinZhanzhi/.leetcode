/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// Brief Digested Understanding:
// ----
// The goal is to rearrange a string's characters so that no two adjacent
// letters are the same. If such a rearrangement isn't possible (for example, if
// one character occurs too frequently), we should return "" (an empty string).
// This is really testing: can we space out the most frequent characters so that
// they never touch another of their kind? If we can, output any such
// arrangement.

// High-Level Summary:
// ----
// We'll count the frequency of each character, then use a max heap (priority
// queue) to always pick the most frequent remaining character—ensuring no two
// adjacent characters are the same. We need to check in advance that no
// character's count is too large to ever be separated (i.e., ceiling(n/2)). Our
// algorithm uses a greedy approach, always placing the highest-count valid
// character and keeping track of the last-used character so we don't repeat it
// immediately. We'll modularize helpers for frequency counting, heap setup, and
// main rearrangement logic. The expected time complexity is O(n log k), where n
// is the string length and k is the number of unique characters; space is O(k).
#include <queue>         // For std::priority_queue (max heap)
#include <string>        // For using std::string
#include <unordered_map> // For frequency counting
#include <vector>

using std::pair;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  // Main function to reorganize the string such that no two
  // adjacent characters are the same. Returns "" if not possible.
  string reorganizeString(string s) {
    if (s.empty())
      return ""; // Handle empty input edge case

    // Step 1: Count the frequency of each character in the string
    unordered_map<char, int> freq = countFrequencies(s);

    // Step 2: Quick feasibility check.
    // If the count of any char > (n + 1) / 2, impossible to rearrange.
    int n = s.size();
    for (const auto &[ch, count] : freq) {
      if (count > (n + 1) / 2)
        return "";
    }

    // Step 3: Build a max heap where top has highest frequency char
    auto heap = buildMaxHeap(freq);

    // Step 4: Build the output string one char at a time
    return buildReorganizedString(heap, n);
  }

private:
  // Helper to count character frequencies in the input string
  unordered_map<char, int> countFrequencies(const string &s) {
    unordered_map<char, int> freq;
    for (char c : s) {
      freq[c]++;
    }
    return freq;
  }

  // Helper to create the max heap (priority_queue), storing pairs of (count,
  // char) Order is by highest count first, if tie, lexicographical order (not
  // essential here).
  using CharFreq = pair<int, char>;
  priority_queue<CharFreq> buildMaxHeap(const unordered_map<char, int> &freq) {
    priority_queue<CharFreq> maxHeap;
    for (const auto &[ch, cnt] : freq) {
      maxHeap.push({cnt, ch});
    }
    return maxHeap;
  }

  // Helper to build the reorganized string with heap
  string buildReorganizedString(priority_queue<CharFreq> &maxHeap,
                                int targetLength) {
    string result; // Resultant reorganized string
    // Hold the previous used (count, char) so we don't put same char twice
    CharFreq prev{0, '#'};

    while (!maxHeap.empty()) {
      CharFreq curr = maxHeap.top(); // Grab most frequent char
      maxHeap.pop();
      result.push_back(curr.second); // Place this char in the output

      // If prev has count > 0, push it back into the heap (it is now allowed
      // because it's skipped 1 spot)
      if (prev.first > 0) {
        maxHeap.push(prev);
      }

      // Decrement the count for this char and set it to prev for the next round
      curr.first--;
      prev =
          curr; // Prepare to maybe push this later after skipping one character
    }

    // If result's length equals original, we succeeded
    if ((int)result.length() == targetLength) {
      return result;
    } else {
      // Failed to reorganize, at some point no valid letters to pick
      // (impossible)
      return "";
    }
  }
};
/*
 * Example Step-by-Step Walkthrough:
 * ---------------------------------
 * Let's walk through the algorithm using the input: s = "aabbccddc"
 *
 * 1. Count character frequencies:
 *    - freq['a'] = 2
 *    - freq['b'] = 2
 *    - freq['c'] = 3
 *    - freq['d'] = 2
 *    (Other letters have freq = 0)
 *
 * 2. Build max-heap from these frequencies.
 *    The heap will contain: (3, 'c'), (2, 'd'), (2, 'b'), (2, 'a')
 *    (Here, the number is the frequency; highest frequency at the top.)
 *
 * 3. Repeatedly pick the most frequent character, ensuring no two same letters
 * are adjacent:
 *    - prev = {0, '#'}
 *    - Iteration 1:
 *        - Pop ('c', 3)  → Append 'c' → result = "c"
 *        - Decrement: ('c', 2), set as prev (to be skipped once)
 *    - Iteration 2:
 *        - Pop ('d', 2)  → Append 'd' → result = "cd"
 *        - Return prev ('c', 2) to heap for future use
 *        - Decrement: ('d', 1), set as prev
 *    - Iteration 3:
 *        - Pop ('c', 2)  → Append 'c' → result = "cdc"
 *        - Return prev ('d', 1) to heap
 *        - Decrement: ('c', 1), set as prev
 *    - Iteration 4:
 *        - Pop ('b', 2)  → Append 'b' → result = "cdcb"
 *        - Return prev ('c', 1) to heap
 *        - Decrement: ('b', 1), set as prev
 *    - Iteration 5:
 *        - Pop ('c', 1)  → Append 'c' → result = "cdcbc"
 *        - Return prev ('b', 1) to heap
 *        - Decrement: ('c', 0), set as prev
 *    - Iteration 6:
 *        - Pop ('a', 2)  → Append 'a' → result = "cdcbca"
 *        - (prev 'c', 0) not returned (count is zero)
 *        - Decrement: ('a', 1), set as prev
 *    - Iteration 7:
 *        - Pop ('b', 1)  → Append 'b' → result = "cdcbcab"
 *        - Return prev ('a', 1) to heap
 *        - Decrement: ('b', 0), set as prev
 *    - Iteration 8:
 *        - Pop ('a', 1)  → Append 'a' → result = "cdcbcaba"
 *        - (prev 'b', 0) not returned
 *        - Decrement: ('a', 0), set as prev
 *    - Iteration 9:
 *        - Pop ('d', 1)  → Append 'd' → result = "cdcbcabad"
 *        - (prev 'a', 0) not returned
 *        - Decrement: ('d', 0), set as prev
 *    - Heap is empty, all characters placed.
 *
 * 4. Final check:
 *    - Output's length is 9, which matches original input, so valid.
 *    - One possible reorganized string: "cdcbcabad"
 *    - In general, other rearrangements are possible as well, as long as no
 * identical adjacent letters.
 *
 * This demonstrates each algorithmic step using the example, showing the heap's
 * state and output growth.
 */
// @lc code=end
