/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 */

/*
 * Brief, Digested Understanding:
 * ----
 * The goal is to randomly generate a point that lies inside a given circle,
 * defined by its center (x_center, y_center) and its radius. The point must
 * be chosen such that every location inside the circle (including the edge)
 * is equally likely to be picked. The function should return the coordinates
 * of this point as a vector of two doubles.
 *
 * High-Level Summary:
 * ----
 * To ensure uniform distribution, we use polar coordinates:
 * - Randomly pick an angle theta between 0 and 2*pi.
 * - Randomly pick a radius r, but to ensure uniformity, r should be chosen
 *   such that the probability density is proportional to the area (i.e.,
 *   r = sqrt(U) * radius, where U is a uniform random number in [0,1)).
 * - Convert (r, theta) to Cartesian coordinates (x, y), then shift by the
 *   circle's center.
 * - We use C++'s <random> library for high-quality random number generation.
 * - The class stores the circle's parameters and a random number generator.
 * - Time complexity: O(1) per call. Space complexity: O(1) (excluding RNG
 * state).
 */
/*
 * Why do we use r = sqrt(U) * radius for uniformity?
 * ----
 * If we simply chose r uniformly in [0, radius), points would be denser near
 * the center, because the area of a circle grows with the square of the radius.
 * To ensure every location inside the circle is equally likely, the probability
 * that a point falls within a distance r from the center must be proportional
 * to the area of the circle of radius r.
 *
 * Mathematical Proof:
 * ----
 * - The area of a circle of radius r is A = π * r^2.
 * - The probability that a random point falls within radius r (i.e., in the
 * disk of radius r) should be proportional to the area: P(R ≤ r) = (π * r^2) /
 * (π * radius^2) = (r^2) / (radius^2).
 * - Let U be a uniform random variable in [0, 1). We want to find a function
 * f(U) such that P(R ≤ r) = P(f(U) ≤ r) = (r^2) / (radius^2).
 * - Set f(U) = radius * sqrt(U). Then:
 *     P(f(U) ≤ r) = P(U ≤ (r / radius)^2) = (r^2) / (radius^2).
 * - This matches the required distribution, so sampling r = sqrt(U) * radius
 * ensures that the probability density is uniform over the area of the circle.
 *
 * In summary, using r = sqrt(U) * radius ensures that the density of points is
 * uniform across the entire area of the circle, not just along the radius.
 */
#include <cmath>  // For trigonometric functions and sqrt
#include <random> // For random number generation
#include <vector> // For std::vector to return the point

using std::vector;

// @lc code=start
class Solution {
private:
  double radius;    // The radius of the circle
  double x_center;  // The x-coordinate of the circle's center
  double y_center;  // The y-coordinate of the circle's center
  std::mt19937 gen; // Mersenne Twister random number generator
  std::uniform_real_distribution<double> dist_angle;  // For angle [0, 2*pi)
  std::uniform_real_distribution<double> dist_radius; // For radius [0, 1)

  // Helper function to generate a random point in polar coordinates,
  // then convert to Cartesian and shift by the center.
  vector<double> generateRandomPoint() {
    // Generate a random angle theta in [0, 2*pi)
    double theta = dist_angle(gen);

    // Generate a random radius with uniform distribution over the area
    // To ensure uniformity, use sqrt of a uniform random variable
    double u = dist_radius(gen);
    double r = std::sqrt(u) * radius;

    // Convert polar coordinates (r, theta) to Cartesian (x, y)
    double x = x_center + r * std::cos(theta);
    double y = y_center + r * std::sin(theta);

    // Return the point as a vector
    return {x, y};
  }

public:
  // Constructor: initializes the circle's parameters and random number
  // generator
  Solution(double radius, double x_center, double y_center)
      : radius(radius), x_center(x_center), y_center(y_center),
        gen(std::random_device{}()), // Seed the RNG with a random device
        dist_angle(0.0, 2 * M_PI),   // Angle in [0, 2*pi)
        dist_radius(0.0, 1.0)        // For uniform [0,1)
  {
    // No additional initialization needed
  }

  // Returns a random point inside the circle, uniformly distributed
  vector<double> randPoint() {
    // Delegate to the helper function for clarity and modularity
    return generateRandomPoint();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end
