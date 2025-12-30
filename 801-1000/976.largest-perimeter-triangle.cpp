/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 *
 * Greedy Algorithm Proof:
 * To form a triangle with sides a, b, c (a ≤ b ≤ c), the triangle inequality
 * requires a + b > c. To maximize the perimeter, we want the largest possible
 * values for a, b, and c. By sorting the array in descending order, we ensure
 * that we always consider the largest available sides first. The first triplet
 * (nums[i], nums[i+1], nums[i+2]) that satisfies nums[i] < nums[i+1] +
 * nums[i+2] will have the largest possible perimeter. This is because any other
 * combination with smaller sides will necessarily have a smaller perimeter.
 * Thus, the greedy approach of checking the largest sides first is optimal.
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (nums[i] < nums[i + 1] + nums[i + 2]) {
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }
    return 0;
  }
};
// @lc code=end
