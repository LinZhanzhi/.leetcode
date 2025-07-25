/*
 * @lc app=leetcode id=1534 lang=cpp
 *
 * [1534] Count Good Triplets
 */

#include <cstdlib>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    int n = arr.size();
    int count = 0;
    // Instead of three nested loops, we can try to reduce memory usage by not
    // using extra space, but the brute-force approach is already optimal for
    // this constraint (n <= 100). However, we can slightly optimize by caching
    // abs(arr[i] - arr[j]) and abs(arr[i] - arr[k])
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        int diff_ij = abs(arr[i] - arr[j]);
        if (diff_ij > a)
          continue;
        for (int k = j + 1; k < n; ++k) {
          int diff_jk = abs(arr[j] - arr[k]);
          if (diff_jk > b)
            continue;
          int diff_ik = abs(arr[i] - arr[k]);
          if (diff_ik <= c) {
            ++count;
          }
        }
      }
    }
    return count;
  }
};
// @lc code=end
