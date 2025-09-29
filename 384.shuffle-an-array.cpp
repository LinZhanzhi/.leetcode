/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The problem is to design a class that can shuffle an array of unique integers
 * so that every possible permutation is equally likely (true randomness), and
 * also allow resetting the array to its original state. The class should
 * support three operations: initialization with the array, resetting to the
 * original array, and shuffling the array randomly.
 *
 * High-Level Summary:
 * ----
 * The solution stores a copy of the original array for resetting. For
 * shuffling, it uses the Fisher-Yates algorithm, which ensures all permutations
 * are equally likely by swapping each element with a randomly chosen element
 * from the current position to the end. The class uses C++'s <random> library
 * for randomness. All operations are O(n) in time and O(n) in space, where n is
 * the array length.
 */

#include <algorithm> // For std::swap
#include <random>    // For random number generation
#include <vector>    // For std::vector to store the array

using std::vector;

// @lc code=start
class Solution {
private:
  vector<int> original; // Stores the original configuration of the array
  vector<int> current;  // Stores the current (possibly shuffled) array
  std::mt19937 rng;     // Mersenne Twister random number generator

public:
  // Constructor: Initializes the object with the input array.
  // Stores a copy of the original array for reset operations.
  Solution(vector<int> &nums)
      : original(nums), current(nums) // Initialize both vectors with nums
  {
    // Seed the random number generator with a random device for true randomness
    std::random_device rd;
    rng = std::mt19937(rd());
  }

  // Resets the array to its original configuration and returns it.
  vector<int> reset() {
    // Restore the current array to the original state
    current = original;
    return current;
  }

  // Returns a random shuffling of the array.
  vector<int> shuffle() {
    // Fisher-Yates shuffle algorithm:
    // For each position i, swap it with a random position j >= i
    int n = current.size();
    for (int i = 0; i < n; ++i) {
      // Generate a random index j in the range [i, n-1]
      std::uniform_int_distribution<int> dist(i, n - 1);
      int j = dist(rng);
      // Swap the elements at positions i and j
      std::swap(current[i], current[j]);
    }
    // Return the shuffled array
    return current;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/*
 * Educational Explanation:
 * ----
 * In this code, `rng` is a member variable of the Solution class, specifically
 * of type `std::mt19937`. `std::mt19937` is a Mersenne Twister pseudo-random
 * number generator provided by the C++ standard library. It is used to generate
 * high-quality random numbers, which are needed for shuffling the array in a
 * truly random way.
 *
 * How is `rng` initialized?
 * - In the constructor, `rng` is seeded using a value from
 * `std::random_device`, which is designed to provide non-deterministic random
 * numbers (often from hardware).
 * - This means that each time you create a new Solution object, `rng` will
 * likely be seeded differently, resulting in different shuffle sequences.
 *
 * Does the value of `rng` change?
 * - Yes, the internal state of `rng` changes every time you use it to generate
 * a random number.
 * - For example, in the `shuffle()` method, each call to `dist(rng)` advances
 * the state of `rng`, so the next random number will be different.
 * - However, the `rng` object itself (the generator) remains the same instance
 * throughout the lifetime of the Solution object; only its internal state
 * evolves as random numbers are generated.
 *
 * Why use `rng` this way?
 * - Using a member variable for the random number generator ensures that the
 * sequence of random numbers is independent for each Solution object.
 * - It also avoids issues that can arise from using global or static random
 * number generators, such as unintended correlations between different objects
 * or functions.
 */
// @lc code=end
