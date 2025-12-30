/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start

#include <algorithm> // Include algorithm for std::max
#include <string> // Include string for function argument and string operations
#include <vector> // Include vector for the return type and storing results

using std::string;
using std::vector;

/*
 * Brief Digested Understanding:
 * ----
 * This problem challenges us to slice a string into as many chunks as possible
 * so that no letter is present in more than one chunk. That is, for any chosen
 * partition, if a character appears in a chunk, it can't appear in any other
 * chunk. Our goal is to report the size (length) of each such chunk, given this
 * maximal splitting scheme.
 */

/*
 * High-Level Summary:
 * ----
 * We'll solve this problem in two main steps:
 *   1. For each character, find the last index at which it appears in the input
 * string.
 *   2. Iterate through the string, expanding the current partition's end as
 * needed whenever we encounter a character that appears later. When our running
 * index matches the farthest "needed" end for encountered characters, we've
 * found a chunk! We record its size and start a new chunk.
 *
 * Key data structures:
 *   - A fixed-size array of length 26 (one for each lowercase letter) to hold
 * last occurrences.
 *
 * Time complexity: O(N), where N is the string length, since each step is
 * linear. Space complexity: O(1), because the extra storage is fixed for the
 * alphabet size.
 */
/*
 * Sample Input/Output Walkthrough:
 *
 * Input:  s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 *
 * Let's see step by step how the algorithm works for this example:
 *
 * 1. First, for every character, we record the last index at which it appears.
 *    For this input, some key last indices are:
 *      'a': 8  | 'b': 5  | 'c': 7  | 'd': 14 | 'e': 15
 *      'f': 11 | 'g': 13 | 'h': 19 | 'i': 22 | 'j': 23
 *      'k': 20 | 'l': 21
 *
 * 2. We start scanning the string, keeping track of our current partition's
 * possible end:
 *      - At i=0 ('a'), lastIndex['a']=8, so partitionEnd is set to 8.
 *      - At i=1 ('b'), lastIndex['b']=5, partitionEnd stays at 8.
 *      - Continue this way. Whenever a character appears whose last occurrence
 * is beyond our current partitionEnd, we extend partitionEnd.
 *      - When i reaches partitionEnd (i=8), we've closed off our first
 * partition: positions 0..8, length 9.
 *
 * 3. Next, start a new partition at i=9 ('d'):
 *      - The farthest last index among characters seen until i=15 is 15, so
 * partitionEnd = 15.
 *      - When i == 15, second partition is positions 9..15, length 7.
 *
 * 4. For i=16 ('h'), initialize partitionEnd = 19 ('h' last seen at 19), and as
 * we continue, the farthest go up to 23 because 'j' last seen at 23, and so on.
 *      - When i == 23, final partition is positions 16..23, length 8.
 *
 * 5. The partition sizes as computed: [9, 7, 8].
 *
 * Throughout the scan, you can visualize the assignment of partition end
 * boundaries, each time you reach that exact index, you know you can close the
 * chunk.
 */

class Solution {
public:
  vector<int> partitionLabels(string s) {
    // Helper function: Fill an array with the last index for each character in
    // s
    int lastIndex[26] = {0}; // Initialize last index for all lowercase letters

    fillLastOccurrenceIndices(s, lastIndex); // Modularity: separate detail

    // Result vector holding the sizes of the partitions
    vector<int> result;
    int partitionStart = 0; // Start index of current partition
    int partitionEnd =
        0; // End index (as far as we've seen for current chunk's chars)

    // Iterate through the string and decide partition ends
    for (int i = 0; i < s.size(); ++i) {
      // Update the current partition's end to the last occurrence of this
      // character
      partitionEnd = std::max(partitionEnd, lastIndex[s[i] - 'a']);

      // If our index equals the current partition's end, we've finished a chunk
      if (i == partitionEnd) {
        // Calculate size of the partition and save it in the result vector
        result.push_back(i - partitionStart + 1);
        // Set the new partition's start to next character
        partitionStart = i + 1;
      }
    }
    return result; // Contains sizes in the order of appearance
  }

private:
  // Helper: Record the last occurrence index for each character in the string
  void fillLastOccurrenceIndices(const string &s, int lastIndex[26]) {
    // Since characters are only lowercase letters, map 'a'-'z' to indices 0-25
    for (int i = 0; i < s.size(); ++i) {
      lastIndex[s[i] - 'a'] = i;
      // For example, if 'b' is at position 5, lastIndex[1] = 5.
    }
    // This pre-processing lets us always know the farthest "need" for any chunk
  }
};
// @lc code=end
