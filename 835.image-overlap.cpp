/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// Brief Digested Understanding:
// ----
// This problem presents two n x n binary images and asks for the largest
// possible overlap of "1"s (on both images) achievable by sliding (translating)
// one image over the other in any direction (without rotation). At any
// translation, the overlap score is the count of (i, j) positions where both
// images have a 1 after translation. The translation can move the 1s in one
// image off the grid; any 1s sliding past the boundary are lost. The goal is to
// find the translation (in terms of horizontal/vertical shifts) that produces
// the maximal overlap between the two images.

// High-Level Summary:
// ----
// To solve this, for every possible translation (shifting img1 relative to
// img2), we calculate how many "1"s overlap. Since each translation is defined
// by (dx, dy) for -n+1 to n-1, the brute-force way is to check every possible
// shift, counting overlapping 1s each time. However, to optimize, we can use a
// hash map to count how many times each translation-vector between a pair of 1s
// in img1 and img2 occurs. The translation vector that occurs the most
// corresponds to the maximum overlap. This approach leverages the fact that we
// care about 1s only, making the process efficient for n up to 30. Time
// complexity is O(n^4) worst-case with brute-force, but the hashing approach
// makes it much faster in practice.

// We'll:
//   - Extract coordinates of all 1s in both images.
//   - For each 1 in img1, for each 1 in img2, compute their translation vector,
//     and count in a hash map.
//   - The answer is the maximal value seen in the map.
//   - All helper/low-level logic (like overlap computation, coordinate
//     extraction) is modularized into separate functions for educational
//     clarity.
//   - Time complexity: O(k1*k2), where k1 and k2 are the number of 1s in img1
//     and img2 (bounded by n^2 each). This is acceptable for n<=30.
//   - Space complexity: O(n^2), for storing coordinates and translation counts.

#include <algorithm>     // For std::max
#include <unordered_map> // For std::unordered_map
#include <utility>       // For std::pair
#include <vector>        // For std::vector

using std::max;
using std::pair;
using std::unordered_map;
using std::vector;

class Solution {
public:
  // This is the main function to solve the image overlap problem.
  int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
    // Step 1: Extract the coordinates of all '1's in both images.
    // We use helpers to modularize this logic.
    vector<pair<int, int>> ones_img1 = getOneCoordinates(img1);
    vector<pair<int, int>> ones_img2 = getOneCoordinates(img2);

    // Step 2: For each pair (1 in img1, 1 in img2), compute translation vector
    //         (delta row, delta col) needed to align them.
    //         Count frequency of each such translation in a hash map.
    unordered_map<long long, int> translationCount;
    int maxOverlap = 0;

    for (const auto &pt1 : ones_img1) {
      for (const auto &pt2 : ones_img2) {
        int dr = pt2.first - pt1.first;    // Row shift needed
        int dc = pt2.second - pt1.second;  // Column shift needed
        long long key = mapToLong(dr, dc); // Composite key to hash 2D delta

        // Increase count of this translation vector
        translationCount[key] += 1;

        // Update the result; maximal overlap encountered so far
        maxOverlap = max(maxOverlap, translationCount[key]);
      }
    }
    // Result is the translation with the most overlap
    return maxOverlap;
  }

private:
  // Helper to get coordinates of all '1's in a binary image (grid).
  vector<pair<int, int>> getOneCoordinates(const vector<vector<int>> &img) {
    vector<pair<int, int>> coords;
    int n = img.size();
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (img[r][c] == 1) {
          coords.emplace_back(r, c);
        }
      }
    }
    return coords;
  }

  // Helper to encode (dr, dc) into single long long key for hash map.
  // This prevents issues with negative coordinates by using an offset.
  long long mapToLong(int dr, int dc) {
    // Offset to ensure that both dr, dc are non-negative (max range is -29 to
    // 29 for n=30)
    return static_cast<long long>(dr + 60) << 32 | (dc + 60);
    // Adding 60 ensures positive values (since -29+60=31, 29+60=89)
    // Shift and or-combine to map (dr, dc) to a unique key
  }
};
// @lc code=end
