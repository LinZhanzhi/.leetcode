/*
 * @lc app=leetcode id=2231 lang=cpp
 *
 * [2231] Largest Number After Digit Swaps by Parity
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  // Helper to extract digits from num in order (most significant to least)
  // and separate them by parity into odd and even vectors
  void extractDigitsAndSeparateByParity(int num, vector<int> &odd,
                                        vector<int> &odd_weight,
                                        vector<int> &even,
                                        vector<int> &even_weight) {
    int weight = 1;
    while (num > 0) {
      int digit = num % 10;
      if (digit % 2 == 0) {
        even.push_back(digit);
        even_weight.push_back(weight);
      } else {
        odd.push_back(digit);
        odd_weight.push_back(weight);
      }
      num /= 10;
      if (num > 0)
        weight *= 10;
    }
  }

  // Helper to reconstruct the largest integer by parity swaps
  int reconstructLargest(vector<int> &odd, vector<int> &odd_weight,
                         vector<int> &even, vector<int> &even_weight) {
    // small digits has small weight
    // large digits have large weight
    int res = 0;
    sort(odd.begin(), odd.end());
    for (int i = 0; i < odd.size(); i++) {
      res += odd[i] * odd_weight[i];
    }
    sort(even.begin(), even.end());
    for (int i = 0; i < even.size(); i++) {
      res += even[i] * even_weight[i];
    }
    return res;
  }

  int largestInteger(int num) {
    vector<int> odd, odd_weight, even, even_weight;
    extractDigitsAndSeparateByParity(num, odd, odd_weight, even, even_weight);
    return reconstructLargest(odd, odd_weight, even, even_weight);
  }
};
// @lc code=end
