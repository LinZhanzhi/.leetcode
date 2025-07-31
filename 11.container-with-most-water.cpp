/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
/*
  This solution uses the two-pointer technique to find the maximum area of water
  that can be contained.
  - We start with two pointers, one at the beginning (left) and one at the end
  (right) of the height array.
  - The area is determined by the shorter of the two heights (since water cannot
  go above the shorter line) times the width (distance between the two
  pointers).
  - At each step, we calculate the area and update the maximum found so far.
  - To potentially find a larger area, we move the pointer pointing to the
  shorter line inward, hoping to find a taller line that could increase the
  area.
  - We repeat this process until the two pointers meet.
  - This approach ensures we check all possible widest containers and
  efficiently narrows down to the optimal solution in O(n) time.
*/
class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
      // Calculate the height and width between the two pointers
      int h = min(height[left], height[right]);
      int w = right - left;
      // Update the maximum area if the current area is larger
      max_area = max(max_area, h * w);
      // Move the pointer pointing to the shorter line inward
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return max_area;
  }
};
// @lc code=end
