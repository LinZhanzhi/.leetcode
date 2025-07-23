/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

#include <vector>
using namespace std;

// @lc code=start
class NumArray {
private:
  // Use int32_t to minimize memory usage, and shrink to fit after construction
  std::vector<int32_t> prefixSums;

public:
  NumArray(const vector<int> &nums) {
    int n = nums.size();
    prefixSums.reserve(n + 1);
    prefixSums.push_back(0);
    int32_t sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      prefixSums.push_back(sum);
    }
    prefixSums.shrink_to_fit();
  }

  int sumRange(int left, int right) const {
    return static_cast<int>(prefixSums[right + 1] - prefixSums[left]);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
