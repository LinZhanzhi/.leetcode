/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */

// Brief, Digested Understanding:
//
// The problem asks us to randomly pick an integer point from the union of
// several non-overlapping rectangles, such that every integer point inside any
// rectangle is equally likely to be chosen. Each rectangle is defined by its
// bottom-left and top-right integer coordinates, and all rectangles are
// axis-aligned and do not overlap. The challenge is to ensure uniform
// randomness across all integer points in all rectangles, not just across
// rectangles themselves.
//
// High-Level Summary:
//
// The solution precomputes the total number of integer points in each rectangle
// and builds a prefix sum array to efficiently map a random integer (in the
// total number of points) to a specific rectangle. When picking a point, we
// randomly select an integer in the total range, use binary search to find
// which rectangle it falls into, and then randomly pick a point within that
// rectangle. This ensures every integer point is equally likely. Time
// complexity for initialization is O(N), and for each pick is O(log N) due to
// binary search, where N is the number of rectangles. Space complexity is O(N)
// for storing rectangles and prefix sums.

#include <algorithm> // For std::upper_bound
#include <random>    // For random number generation
#include <vector>    // For std::vector

using std::vector;

class Solution {
private:
  vector<vector<int>> rects_; // Stores the rectangles as given
  vector<int>
      prefixSums_;   // Prefix sum of the number of integer points in rectangles
  std::mt19937 rng_; // Mersenne Twister random number generator
  int totalPoints_;  // Total number of integer points in all rectangles

  // Helper function to compute the number of integer points in a rectangle
  // Each rectangle is [a, b, x, y], so the number of integer points is (x - a +
  // 1) * (y - b + 1)
  int countPoints(const vector<int> &rect) {
    int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
    return (x - a + 1) * (y - b + 1);
  }

  // Helper function to pick a random integer in [low, high] (inclusive)
  int randInt(int low, int high) {
    std::uniform_int_distribution<int> dist(low, high);
    return dist(rng_);
  }

public:
  // Constructor: Initializes the object with the given rectangles
  Solution(vector<vector<int>> &rects)
      : rects_(rects), rng_(std::random_device{}()), totalPoints_(0) {
    // Build the prefix sum array for the number of integer points in each
    // rectangle prefixSums_[i] = total number of points in rectangles [0, i]
    prefixSums_.reserve(rects.size());
    int sum = 0;
    for (const auto &rect : rects_) {
      sum += countPoints(rect);
      prefixSums_.push_back(sum);
    }
    totalPoints_ = sum;
  }

  // Picks a random integer point [u, v] inside the space covered by the
  // rectangles
  vector<int> pick() {
    // Step 1: Pick a random integer in [0, totalPoints_ - 1]
    int randPointIdx = randInt(0, totalPoints_ - 1);

    // Step 2: Use binary search to find which rectangle this point falls into
    // upper_bound returns the first index where prefixSums_[idx] > randPointIdx
    auto it =
        std::upper_bound(prefixSums_.begin(), prefixSums_.end(), randPointIdx);
    int rectIdx = it - prefixSums_.begin();

    // Step 3: Find the offset of the point within the chosen rectangle
    int prevSum = rectIdx == 0 ? 0 : prefixSums_[rectIdx - 1];
    int offset = randPointIdx - prevSum;

    // Step 4: Map the offset to a specific (x, y) point in the rectangle
    // Rectangle coordinates
    const vector<int> &rect = rects_[rectIdx];
    int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
    int width = x - a + 1; // Number of integer x-coordinates

    // The offset can be mapped to (dx, dy) where:
    // dx = offset % width, dy = offset / width
    int dx = offset % width;
    int dy = offset / width;
    int px = a + dx;
    int py = b + dy;

    // Return the randomly picked point
    return {px, py};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end
