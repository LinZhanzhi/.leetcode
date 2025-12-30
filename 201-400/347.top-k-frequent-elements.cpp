/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

/*
 * Brief, Digested Understanding:
 * ----
 * Given an array of integers, we want to find the k elements that appear most
 * frequently. The result can be in any order, but we must ensure that the k
 * most common elements are returned. The challenge is to do this efficiently,
 * ideally in linear time, rather than sorting all elements.
 */

/*
 * High-Level Summary:
 * ----
 * The solution uses a hash map to count the frequency of each number in the
 * input array. Then, it uses a "bucket sort" approach: it creates an array of
 * buckets, where the index represents frequency, and each bucket contains the
 * numbers that appear with that frequency. By iterating from the highest
 * frequency bucket down, we can collect the k most frequent elements
 * efficiently.
 *
 * Time Complexity: O(n), where n is the size of nums, since we count
 * frequencies and then bucket them. Space Complexity: O(n), for the hash map
 * and the buckets.
 */

#include <unordered_map> // For std::unordered_map
#include <vector>        // For std::vector

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // Step 1: Count the frequency of each number using a hash map.
    unordered_map<int, int> freqMap; // Maps number -> frequency
    for (int num : nums) {
      freqMap[num]++; // Increment the count for this number
    }

    // Step 2: Create buckets where index = frequency, and each bucket holds
    // numbers with that frequency. The maximum possible frequency is
    // nums.size(), so we need nums.size() + 1 buckets (index 0 unused).
    int n = nums.size();
    vector<vector<int>> buckets(
        n + 1); // buckets[i] holds numbers that appear i times

    for (const auto &pair : freqMap) {
      int number = pair.first;
      int frequency = pair.second;
      buckets[frequency].push_back(
          number); // Place number in its frequency bucket
    }

    // Step 3: Gather the k most frequent elements by iterating buckets from
    // high to low frequency.
    vector<int> result;
    // Start from the highest possible frequency and go down
    for (int freq = n; freq >= 1 && result.size() < k; --freq) {
      for (int num : buckets[freq]) {
        result.push_back(num); // Add this number to the result
        if (result.size() == k) {
          break; // Stop if we've collected k elements
        }
      }
    }
    // The result now contains the k most frequent elements
    return result;
  }
};
// @lc code=end
