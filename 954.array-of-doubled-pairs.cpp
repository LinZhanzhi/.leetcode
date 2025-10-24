/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

/*
 * Brief Digested Understanding:
 * ----
 * The core concept of this problem is: Given an array, can we reorder its
 * elements in such a way that for every index i in the first half, one element
 * is double the other? Specifically, for each pair of indices (2 * i, 2 * i +
 * 1), the value at the second index must be exactly twice the value at the
 * first. The challenge lies in efficiently pairing up elements, even when
 * negative or zero values are present, and ensuring all elements are used up.
 *
 * High-Level Summary:
 * ----
 * The approach involves counting the occurrences (frequency) of each integer
 * value in the array. To pair elements correctly, we sort the values by their
 * absolute value to handle negatives and zeros properly. For each number x (in
 * order of increasing |x|), we greedily pair it with 2*x, decrementing the
 * frequencies appropriately. Special care is taken for zeros since they must be
 * paired among themselves. This method uses a hash map for counting and sorting
 * by absolute values, resulting in O(N log N) time for sorting and O(N) time
 * for the pairing process, where N is the size of the array. Space complexity
 * is O(N) for the count map.
 */

#include <algorithm>     // Import algorithm for std::sort and std::abs.
#include <unordered_map> // Import unordered_map for efficient counting.
#include <vector>        // Import vector for handling dynamic arrays.

using namespace std; // Allow access to std namespace for convenience.

// @lc code=start
class Solution {
public:
  // Main function that determines whether the array can be reordered into
  // doubled pairs.
  bool canReorderDoubled(vector<int> &arr) {
    // Step 1: Count the frequency of each number in the array for pairing
    // purposes.
    unordered_map<int, int> count = countFrequencies(arr);

    // Step 2: Sort the unique numbers by absolute value.
    vector<int> keys = getSortedKeysByAbs(count);

    // Step 3: Attempt to pair each value with its double.
    for (int x : keys) {
      // If there are not enough 2*x's to pair with x, pairing is impossible.
      if (count[2 * x] < count[x]) {
        return false;
      }
      // Reduce the count of 2*x by the number of pairs formed with x.
      count[2 * x] -= count[x];
      // (Do not reduce count[x]; we've handled them.)
    }
    // If all pairs formed successfully, return true.
    return true;
  }

private:
  // Helper function to count occurrences of each integer in the array.
  unordered_map<int, int> countFrequencies(const vector<int> &arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
      ++freq[num]; // Increment the count for the current number.
    }
    return freq;
  }

  // Helper function to return all unique keys from the map, sorted by absolute
  // value.
  vector<int> getSortedKeysByAbs(const unordered_map<int, int> &freq) {
    vector<int> keys;
    // Gather all unique numbers from the count map.
    for (const auto &kv : freq) {
      keys.push_back(kv.first);
    }
    // Sort the keys by their absolute value (handle negatives and zeros
    // correctly).
    sort(keys.begin(), keys.end(), [](int a, int b) {
      return abs(a) < abs(b); // This ensures proper pairing order.
    });
    return keys;
  }
};
// @lc code=end
