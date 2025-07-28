/*
 * @lc app=leetcode id=2200 lang=cpp
 *
 * [2200] Find All K-Distant Indices in an Array
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    vector<int> result;
    int n = nums.size();
    int lastAdded = -1;

    for (int i = 0; i < n; ++i) {
      if (nums[i] == key) {
        int start = max(lastAdded + 1, i - k);
        int end = min(n - 1, i + k);
        for (int j = start; j <= end; ++j) {
          result.push_back(j);
        }
        lastAdded = end;
      }
    }

    return result;
  }
};
// @lc code=end
