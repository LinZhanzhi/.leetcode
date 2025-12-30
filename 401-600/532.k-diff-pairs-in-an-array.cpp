/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem asks us to count the number of unique pairs (i, j) in an array
 * such that the absolute difference between nums[i] and nums[j] is exactly k,
 * and i != j. A pair is considered unique if the two numbers (nums[i], nums[j])
 * are unique as a set, regardless of their order or how many times they appear
 * in the array. For k = 0, we are looking for numbers that appear at least
 * twice (duplicates). For k > 0, we are looking for pairs of numbers where one
 * is exactly k apart from the other, and each such pair is only counted once.
 *
 * High-Level Summary:
 * ----
 * The solution uses a hash map (unordered_map) to efficiently count the
 * frequency of each number in the array.
 * - For k > 0: For each unique number, we check if (number + k) exists in the
 * map. If so, we count this as a unique pair.
 * - For k == 0: We count how many numbers appear at least twice, since only
 * duplicates can form a 0-diff pair.
 * - For k < 0: The answer is always 0, since absolute difference cannot be
 * negative. This approach ensures O(N) time complexity, where N is the size of
 * the array, and O(N) space for the hash map.
 */

#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

class Solution {
public:
  // Main function to find the number of unique k-diff pairs in the array
  int findPairs(vector<int> &nums, int k) {
    // Edge case: If k is negative, absolute difference cannot be negative
    if (k < 0)
      return 0;

    // Build a frequency map to count occurrences of each number
    unordered_map<int, int> freqMap = buildFrequencyMap(nums);

    // Use a helper function to count unique pairs based on the value of k
    if (k == 0) {
      // For k == 0, count numbers that appear at least twice
      return countZeroDiffPairs(freqMap);
    } else {
      // For k > 0, count unique pairs (num, num + k)
      return countKDiffPairs(freqMap, k);
    }
  }

private:
  // Helper function to build a frequency map from the input array
  unordered_map<int, int> buildFrequencyMap(const vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
      // Increment the count for each number
      freq[num]++;
    }
    return freq;
  }

  // Helper function to count unique 0-diff pairs (duplicates)
  int countZeroDiffPairs(const unordered_map<int, int> &freqMap) {
    int count = 0;
    // Iterate through the frequency map
    for (const auto &entry : freqMap) {
      // If a number appears at least twice, it forms a 0-diff pair
      if (entry.second >= 2) {
        count++;
      }
    }
    return count;
  }

  // Helper function to count unique k-diff pairs for k > 0
  int countKDiffPairs(const unordered_map<int, int> &freqMap, int k) {
    int count = 0;
    // For each unique number, check if (number + k) exists in the map
    for (const auto &entry : freqMap) {
      int num = entry.first;
      if (freqMap.count(num + k)) {
        // (num, num + k) is a unique k-diff pair
        count++;
      }
    }
    return count;
  }
};
// @lc code=end
