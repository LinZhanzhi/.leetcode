/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to design a data structure that supports three operations—insert,
 * remove, and getRandom—each in average O(1) time.
 * - insert(val): Adds val if not present, returns true if inserted, false if
 * already present.
 * - remove(val): Removes val if present, returns true if removed, false if not
 * present.
 * - getRandom(): Returns a random element from the set, with each element
 * having equal probability. The challenge is to make all three operations
 * efficient, especially getRandom, which requires O(1) access to a random
 * element.
 *
 * High-Level Summary:
 * ----
 * To achieve O(1) for all operations, we use:
 *   - A vector<int> to store the elements, allowing O(1) access by index and
 * O(1) addition/removal at the end.
 *   - An unordered_map<int, int> to map each value to its index in the vector,
 * allowing O(1) lookup, insertion, and deletion. For removal, we swap the
 * element to be removed with the last element in the vector, update the map,
 * and then pop_back the vector. This ensures that all operations remain O(1) on
 * average.
 *
 * Time Complexity:
 *   - insert: O(1) average
 *   - remove: O(1) average
 *   - getRandom: O(1)
 * Space Complexity: O(N), where N is the number of elements in the set.
 */

// @lc code=start
#include <cstdlib>       // For rand() function.
#include <unordered_map> // For std::unordered_map to map values to indices.
#include <vector>        // For std::vector to store elements.

using namespace std;

class RandomizedSet {
private:
  vector<int> nums;                   // Stores the elements of the set.
  unordered_map<int, int> valToIndex; // Maps value to its index in nums.

public:
  // Constructor: Initializes the data structure.
  RandomizedSet() {
    // No initialization needed as vector and map are empty by default.
  }

  // Inserts a value into the set if not already present.
  // Returns true if the value was inserted, false if it was already present.
  bool insert(int val) {
    // Check if val is already in the set using the map.
    if (valToIndex.count(val)) {
      // Value already exists, do not insert.
      return false;
    }
    // Add val to the end of the vector.
    nums.push_back(val);
    // Record the index of val in the map.
    valToIndex[val] = nums.size() - 1;
    return true;
  }

  // Removes a value from the set if present.
  // Returns true if the value was removed, false if it was not present.
  bool remove(int val) {
    // Check if val exists in the set.
    if (!valToIndex.count(val)) {
      // Value does not exist, cannot remove.
      return false;
    }
    // Get the index of the value to remove.
    int idx = valToIndex[val];
    // Get the last element in the vector.
    int lastVal = nums.back();
    // Move the last element to the position of the element to remove,
    // but only if val is not already the last element.
    nums[idx] = lastVal;
    // Update the map for the moved element.
    valToIndex[lastVal] = idx;
    // Remove the last element from the vector.
    nums.pop_back();
    // Remove val from the map.
    valToIndex.erase(val);
    return true;
  }

  // Returns a random element from the set.
  // Each element must have the same probability of being returned.
  int getRandom() {
    // Generate a random index in the range [0, nums.size() - 1].
    int randIdx = rand() % nums.size();
    // Return the element at the random index.
    return nums[randIdx];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
