/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 */

/*
 * Brief Digested Understanding:
 * -----------------------------
 * We are given a set of 2D points. We need to find four points from this set that form a rectangle.
 * Among all such rectangles, we want to find the one with the minimum area.
 * The rectangle can be rotated (not necessarily axis-aligned).
 * If no rectangle exists, return 0.
 *
 * High-Level Summary:
 * -------------------
 * The constraints are small (N <= 50). This allows for an O(N^3) approach.
 * 1. Store all points in a set for fast O(log N) or O(1) lookup.
 * 2. Iterate through every triplet of points (p1, p2, p3).
 * 3. Check if p1, p2, p3 form a right angle at p1 (i.e., dot product of vector p1->p2 and p1->p3 is 0).
 * 4. If they form a right angle, calculate the expected position of the 4th point p4 to complete the rectangle.
 *    - p4 = p2 + p3 - p1.
 * 5. Check if p4 exists in our set.
 * 6. If it does, calculate the area (|p1->p2| * |p1->p3|) and update the minimum area.
 *
 * Time Complexity: O(N^3) - We iterate through triplets of points.
 * Space Complexity: O(N) - To store points in a set for quick lookup.
 */

#include <vector>
#include <set>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
private:
    // Helper to check if vectors p1->p2 and p1->p3 are perpendicular.
    // Returns true if the dot product is 0.
    bool isRightAngle(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
        long long x1 = p2[0] - p1[0];
        long long y1 = p2[1] - p1[1];
        long long x2 = p3[0] - p1[0];
        long long y2 = p3[1] - p1[1];
        return (x1 * x2 + y1 * y2) == 0;
    }

    // Helper to calculate the area of the rectangle defined by corner p1 and adjacent vertices p2, p3.
    // Area = |vec(p1p2)| * |vec(p1p3)|
    double calculateArea(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
        long long x1 = p2[0] - p1[0];
        long long y1 = p2[1] - p1[1];
        long long x2 = p3[0] - p1[0];
        long long y2 = p3[1] - p1[1];
        
        double len1 = sqrt((double)(x1 * x1 + y1 * y1));
        double len2 = sqrt((double)(x2 * x2 + y2 * y2));
        return len1 * len2;
    }

public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0.0;

        // Use a set of pairs for easier lookup of points.
        set<pair<int, int>> pointSet;
        for (const auto& p : points) {
            pointSet.insert({p[0], p[1]});
        }

        double minArea = numeric_limits<double>::max();
        bool found = false;

        // Iterate through all triplets (p1, p2, p3)
        // We consider p1 as the vertex with the right angle.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                for (int k = j + 1; k < n; ++k) {
                    if (k == i) continue;

                    // Check if p1, p2, p3 form a right angle at p1
                    if (isRightAngle(points[i], points[j], points[k])) {
                        // Calculate expected 4th point p4 = p2 + p3 - p1
                        int p4x = points[j][0] + points[k][0] - points[i][0];
                        int p4y = points[j][1] + points[k][1] - points[i][1];

                        // Check if p4 exists in our set
                        if (pointSet.count({p4x, p4y})) {
                            double area = calculateArea(points[i], points[j], points[k]);
                            if (area < minArea) {
                                minArea = area;
                                found = true;
                            }
                        }
                    }
                }
            }
        }

        return found ? minArea : 0.0;
    }
};
// @lc code=end
