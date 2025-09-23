/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

/*
 * Brief, Digested Understanding:
 * ----
 * We are given two rectangles on a 2D plane, each defined by their bottom-left
 * and top-right coordinates. The task is to compute the total area covered by
 * both rectangles, making sure not to double-count any overlapping region. In
 * other words, if the rectangles overlap, the area of the overlap should only
 * be counted once in the total.
 */

/*
 * High-Level Summary:
 * ----
 * The solution calculates the area of each rectangle separately, then
 * determines the area of their overlap (if any). The total area is the sum of
 * the two rectangle areas minus the overlapping area. To find the overlap, we
 * compute the intersection's width and height by taking the maximum of the
 * left/bottom edges and the minimum of the right/top edges. If the rectangles
 * do not overlap, the overlap area is zero.
 *
 * Time Complexity: O(1) — All operations are simple arithmetic.
 * Space Complexity: O(1) — No extra space is used.
 */

// @lc code=start
class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    // Calculate the area of the first rectangle.
    // (ax2 - ax1) is the width, (ay2 - ay1) is the height.
    int areaA = (ax2 - ax1) * (ay2 - ay1);

    // Calculate the area of the second rectangle.
    int areaB = (bx2 - bx1) * (by2 - by1);

    // Find the overlap boundaries.
    // The left boundary of the overlap is the maximum of the two left sides.
    int overlapLeft = std::max(ax1, bx1);
    // The right boundary of the overlap is the minimum of the two right sides.
    int overlapRight = std::min(ax2, bx2);
    // The bottom boundary of the overlap is the maximum of the two bottoms.
    int overlapBottom = std::max(ay1, by1);
    // The top boundary of the overlap is the minimum of the two tops.
    int overlapTop = std::min(ay2, by2);

    // Calculate the width and height of the overlapping area.
    // If the rectangles do not overlap, these will be negative or zero.
    int overlapWidth = overlapRight - overlapLeft;
    int overlapHeight = overlapTop - overlapBottom;

    // The area of overlap is only positive if both width and height are
    // positive.
    int overlapArea = 0;
    if (overlapWidth > 0 && overlapHeight > 0) {
      overlapArea = overlapWidth * overlapHeight;
    }

    // The total area is the sum of both rectangles minus the overlapping area.
    return areaA + areaB - overlapArea;
  }
};
// @lc code=end
