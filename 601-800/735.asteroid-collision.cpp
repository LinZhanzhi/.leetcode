/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// ---------------- Explanation Sections ----------------

/**
 * Brief Digested Understanding:
 * ----
 * This problem is about simulating how asteroids, each with a direction and a
 * size, interact when they "crash" in a line: asteroids moving right (positive)
 * and asteroids moving left (negative) can annihilate each other when they
 * meet. The larger survives or both are destroyed if equal. Our job is to
 * report which asteroids remain after all possible collisions happen,
 * efficiently.
 */

/**
 * High-Level Summary:
 * ----
 * We'll use a stack (implemented as a vector) to simulate the sequence of
 * "active" asteroids as we scan from left to right. For each asteroid, we check
 * if it collides with those on the stack's top: left-moving asteroids meet
 * right-moving ones. We resolve all possible collisions at that moment before
 * adding the asteroid to the stack. All checks are direct and iterative, with
 * O(N) time and space complexity.
 */

// @lc code=start
#include <cstdlib> // For std::abs (abs function)
#include <vector>  // For std::vector

using std::vector;

class Solution {
public:
  // Main function to simulate asteroid collisions and return survivors
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int>
        stack; // Vector will be used as a stack to store surviving asteroids

    // Helper function to determine if a collision occurs
    // Returns true only if stackTop is moving right and current is moving left
    // NOTE: We pass stackTop and current explicitly - do not rely on outside
    // vector scope!
    auto willCollide = [](int stackTop, int current) -> bool {
      return (stackTop > 0 && current < 0);
    };

    // Iterate through each asteroid in the input list
    for (int asteroid : asteroids) {
      bool destroyed = false; // Track whether the current asteroid is destroyed
                              // in the process

      // As long as there's a potential for collision, keep checking
      while (!stack.empty() && willCollide(stack.back(), asteroid)) {
        int top =
            stack.back(); // The asteroid on top of the stack (latest survivor)

        // If both asteroids are the same size, both are destroyed
        if (std::abs(top) == std::abs(asteroid)) {
          stack.pop_back(); // Remove the right-moving asteroid
          destroyed = true; // The new (left-moving) asteroid is also destroyed
          break;            // No further processing for this asteroid
        }
        // Stack top is larger: the current asteroid is destroyed, stack top
        // survives
        else if (std::abs(top) > std::abs(asteroid)) {
          destroyed = true; // Current asteroid can't survive this collision
          break;
        }
        // Current asteroid is larger: pop and continue checking further
        // collisions
        else {
          stack.pop_back(); // Remove the smaller right-moving asteroid, keep
                            // checking
        }
      }
      // If not destroyed after all possible collisions, push the asteroid to
      // the stack
      if (!destroyed) {
        stack.push_back(asteroid);
      }
    }
    // Return the state of the stack, which now contains all surviving asteroids
    return stack;
  }
};
// @lc code=end
