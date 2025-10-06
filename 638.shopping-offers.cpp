/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */

// Brief Digested Understanding:
// ----
// This problem is about buying a set of items in exact quantities, where each
// item has a regular price, but there are also "special offers" that bundle
// several items together for a discounted price. The challenge is to find the
// minimum total cost to buy exactly the needed quantities, using any
// combination of regular purchases and special offers, but never buying more
// than needed of any item. You can use each special offer as many times as you
// want, as long as you don't exceed the needs for any item.

// High-Level Summary:
// ----
// The core approach is to use recursion with memoization (top-down dynamic
// programming) to explore all possible ways to fulfill the needs using both
// individual purchases and special offers.
//
// For each state (current needs), we try all valid special offers and also
// consider buying remaining items at regular price.
//
// We use a hash map to memoize the minimum cost for each unique needs state to
// avoid redundant calculations.
//
// The main data structure is a vector to represent the current needs, and the
// memoization key is a string or vector representation of needs.
//
// The time complexity is O((maxNeed+1)^n * s), where n is the number of items,
// maxNeed is the maximum need per item (<=10), and s is the number of specials.
//
// Space complexity is similar due to memoization.

// @lc code=start
#include <algorithm>     // For std::min
#include <string>        // For std::string (key generation)
#include <unordered_map> // For std::unordered_map (memoization)
#include <vector>        // For std::vector

using std::min;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  // The main function to compute the minimum cost to fulfill the needs
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                     vector<int> &needs) {
    // Memoization map: key is a string representation of needs, value is min
    // cost
    unordered_map<string, int> memo;
    return dfs(price, special, needs, memo);
  }

private:
  // Helper function to convert the needs vector to a string key for memoization
  string needsToKey(const vector<int> &needs) {
    // Concatenate each need with a separator to form a unique key
    string key;
    for (int n : needs) {
      key += std::to_string(n) + ",";
    }
    return key;
  }

  // Recursive DFS function with memoization to find the minimum cost
  int dfs(const vector<int> &price, const vector<vector<int>> &special,
          vector<int> &needs, unordered_map<string, int> &memo) {
    // Generate a unique key for the current needs
    string key = needsToKey(needs);

    // If we've already computed the minimum cost for this needs state, return
    // it
    if (memo.count(key)) {
      return memo[key];
    }

    // Calculate the cost without any special offers (i.e., buy all remaining
    // items at regular price)
    int minCost = directPurchase(price, needs);

    // Try every special offer to see if it can be applied
    for (const auto &offer : special) {
      // Check if the offer can be applied (i.e., does not exceed needs for any
      // item)
      if (canApplyOffer(offer, needs)) {
        // Apply the offer: subtract the offer quantities from needs
        for (int i = 0; i < needs.size(); ++i) {
          needs[i] -= offer[i];
        }
        // Recursively compute the cost for the new needs, adding the offer
        // price
        int offerCost = offer.back() + dfs(price, special, needs, memo);
        // Update the minimum cost if this path is better
        minCost = min(minCost, offerCost);
        // Backtrack: restore the needs vector for the next iteration
        for (int i = 0; i < needs.size(); ++i) {
          needs[i] += offer[i];
        }
      }
    }

    // Memoize and return the minimum cost for this needs state
    memo[key] = minCost;
    return minCost;
  }

  // Helper function to check if a special offer can be applied to the current
  // needs
  bool canApplyOffer(const vector<int> &offer, const vector<int> &needs) {
    for (int i = 0; i < needs.size(); ++i) {
      // If the offer requires more of any item than needed, it cannot be
      // applied
      if (offer[i] > needs[i]) {
        return false;
      }
    }
    return true;
  }

  // Helper function to compute the cost of buying all remaining needs at
  // regular price
  int directPurchase(const vector<int> &price, const vector<int> &needs) {
    int total = 0;
    for (int i = 0; i < price.size(); ++i) {
      total += price[i] * needs[i];
    }
    return total;
  }
};
// @lc code=end
