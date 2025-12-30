/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// Brief Digested Understanding:
// ----
// This LeetCode problem asks us to find the k words that occur most frequently
// in a list of words. The result should be ordered from most to least frequent.
// If two words have the same frequency, the word that comes first
// lexicographically is preferred. The challenge is to efficiently count
// frequencies, sort properly, and efficiently return the correct k items.
//
// High-Level Summary:
// ----
// We'll first count the frequency of every word using a hash map
// (unordered_map). To efficiently get the k most frequent words with correct
// ordering (by frequency, and by lexicographical order for ties), we can use a
// min-heap (priority_queue) where the custom comparator puts less frequent
// (or, for ties, greater lexicographical) words at the top. This heap is
// limited to k elements, resulting in O(n log k) time. At the end we extract
// the words from the heap into a result vector, reversing to get the correct
// order. Overall, this approach leverages hash maps and heaps, yielding
// O(n log k) time and O(n) space complexity.

// @lc code=start
#include <functional>    // For std::function and std::greater
#include <queue>         // For std::priority_queue
#include <string>        // For std::string
#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::pair;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    // Helper function to count frequencies of each word in the input.
    auto countFrequencies =
        [](const vector<string> &words) -> unordered_map<string, int> {
      unordered_map<string, int> freq;
      for (const string &word : words) {
        freq[word]++; // Increment count for each occurrence.
      }
      return freq;
    };

    // Custom comparator for the min-heap:
    // - Prioritize lower frequency.
    // - For ties, prioritize higher lex order (so when popping the heap,
    // lexically 'larger' comes first and will be removed before correct
    // answers).
    struct Compare {
      bool operator()(const pair<int, string> &a,
                      const pair<int, string> &b) const {
        // If frequency is different, lower frequency comes first in heap.
        if (a.first != b.first)
          return a.first > b.first;
        // If frequency is same, compare strings such that lexicographically
        // larger word comes first (so that smallest is on top).
        return a.second < b.second;
      }
    };

    // Step 1: Count the frequency of each word.
    unordered_map<string, int> freq = countFrequencies(words);

    // Step 2: Use a min-heap to get the k most frequent words.
    // Each heap entry is a pair (frequency, word).
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>
        minHeap;

    for (const auto &entry : freq) {
      // Push the (frequency, word) pair into the min-heap.
      minHeap.emplace(entry.second, entry.first);
      // If heap exceeds size k, remove the least frequent (or, for a tie, the
      // lexically last).
      if ((int)minHeap.size() > k) {
        minHeap.pop();
      }
    }

    // Step 3: Extract words from the heap.
    // The heap top is the least desirable of the k; extract and reverse later.
    vector<string> result;
    while (!minHeap.empty()) {
      result.push_back(minHeap.top().second);
      minHeap.pop();
    }

    // Since the words were extracted from lowest to highest frequency (and lex
    // order tie-breaker), reverse the vector to get most frequent and lex
    // smallest first.
    std::reverse(result.begin(), result.end());

    return result;
  }
};
// @lc code=end
