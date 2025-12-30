/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

/*
 * Brief Digested Understanding:
 * ----
 * This problem asks you to find the longest contiguous subarray in which there
 * are at most two different types of fruits (integers). The twist: you must
 * always pick consecutive fruits from any starting tree to the right and you
 * can't skip trees – and with only two baskets (so only two distinct fruit
 * types are allowed in the chosen sequence at any time). Essentially, you're
 * trying to compute the maximal length of a subarray with at most two distinct
 * integers.
 *
 * High-Level Summary:
 * ----
 * We'll use the sliding window technique for this problem. We'll maintain a
 * window (using two pointers, left and right) where at most two distinct fruit
 * types appear. We'll use a hash map (unordered_map) to keep count of each
 * fruit type in the window. When the window tries to hold more than two types,
 * we'll shrink the left edge until only two are left. We update our answer at
 * each step to record the maximal window length. This approach yields an O(n)
 * time and O(k) space complexity, where n is the number of fruits and k ≤ 2
 * (the number of unique types in the window).
 */

#include <algorithm> // For std::max (to compute the answer)
#include <unordered_map> // For std::unordered_map, which will be used for fruit counts
#include <vector>        // For std::vector

using std::max;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
  /**
   * Returns the maximum number of fruits that can be collected according
   * to the rules specified (from any starting tree, to the right, so that
   * at most two types of fruit are ever picked).
   */
  int totalFruit(vector<int> &fruits) {
    // Helper: Counts the frequency of fruit types currently within the window
    unordered_map<int, int> fruitCount;

    int left = 0;      // Left pointer for the sliding window
    int maxFruits = 0; // Max number of fruits collected so far

    // The right pointer iterates over each tree in the row
    for (int right = 0; right < fruits.size(); ++right) {
      int currFruit = fruits[right];

      // Add current fruit to the count/hash map
      fruitCount[currFruit]++;

      // While there are more than two types of fruits in our baskets,
      // shrink the window from the left
      while (fruitCount.size() > 2) {
        // Remove one fruit of the type at position 'left'
        int leftFruit = fruits[left];
        fruitCount[leftFruit]--;

        // If the count for that fruit type falls to zero,
        // remove that fruit type from our map
        if (fruitCount[leftFruit] == 0) {
          fruitCount.erase(leftFruit);
        }
        // Move left pointer forward to shrink the window
        left++;
      }

      // At this point, there are at most two types of fruits in the window
      // [left, right] Update maxFruits if this window is the largest we have
      // seen
      maxFruits = max(maxFruits, right - left + 1);
    }

    // Return the largest number of fruits that can be picked
    return maxFruits;
  }
};
// @lc code=end
