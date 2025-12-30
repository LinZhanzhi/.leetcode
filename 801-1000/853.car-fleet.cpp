/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// Brief Digested Understanding:
// ----
// In this problem, you need to determine how many distinct "fleets" of cars
// will reach a given destination, considering that cars start at different
// positions and move at different speeds toward the target. Cars cannot pass
// one another on the way; if a faster car catches up with a slower car or group
// of cars (a "fleet"), it joins that fleet and then moves at the slowest speed
// in that group. We're asked: how many groups ("fleets") will arrive, given all
// these cars?

// High-Level Summary:
// ----
// The main insight is that a car can only join (merge with) a fleet ahead of it
// if it catches up before or as both reach the target. We model each car by the
// time it will take to reach the target (target - position[i]) / speed[i], then
// sort cars by their starting position (from closest to farthest from the
// destination). We iterate from the closest to the farthest, building fleets:
// If a car would arrive later than the fleet ahead, it forms a new fleet;
// if it would arrive sooner or at the same time, it merges into the existing
// fleet. The solution uses sorting and a stack-like pattern, resulting in
// O(n log n) time (due to sort) and O(n) space for storing times and results.

#include <algorithm> // For std::sort
#include <vector>    // Include to use std::vector

using std::pair;
using std::vector;

class Solution {
public:
  // Main function to determine the number of car fleets reaching the target
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    // Helper function to combine car positions and speeds into a list of pairs.
    // Each pair is (position, speed).
    auto carsWithPositions = combinePositionAndSpeed(position, speed);

    // Sort cars by their starting position in descending order (closest to
    // target first).
    sortCarsByPositionDescending(carsWithPositions);

    // Calculate the arrival time at the target for each car.
    vector<double> arrivalTimes =
        computeArrivalTimes(carsWithPositions, target);

    // Use helper to count the number of fleets using the times and sorted
    // order.
    return countFleets(arrivalTimes);
  }

private:
  // Combines position and speed vectors into a single vector of (position,
  // speed) pairs
  vector<pair<int, int>> combinePositionAndSpeed(const vector<int> &position,
                                                 const vector<int> &speed) {
    vector<pair<int, int>> cars;
    // Assumes position and speed have the same size
    for (size_t i = 0; i < position.size(); ++i) {
      cars.emplace_back(position[i], speed[i]);
    }
    // Result: a vector where each entry is (position, speed)
    return cars;
  }

  // Sorts the cars so that the car with the largest starting position comes
  // first. This way, we process cars from closest to the target to farthest.
  void sortCarsByPositionDescending(vector<pair<int, int>> &cars) {
    std::sort(cars.begin(), cars.end(),
              [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.first > b.first;
              });
    // Now, cars[0] is the one starting closest to the target.
  }

  // Calculates the time taken for each car to reach the target.
  // Returns a vector of arrival times ordered according to the sorted
  // positions.
  vector<double> computeArrivalTimes(const vector<pair<int, int>> &cars,
                                     int target) {
    vector<double> times;
    for (const auto &car : cars) {
      int pos = car.first;
      int spd = car.second;
      // Calculate time to reach target for current car.
      // Use double to prevent integer division errors.
      double time = static_cast<double>(target - pos) / spd;
      times.push_back(time);
    }
    return times;
  }

  // Counts fleets: iterate through the times (sorted as cars are by position).
  // If a car's time > last fleet's arrival time, it cannot catch up; it starts
  // a new fleet. Otherwise, it merges into the existing fleet.
  int countFleets(const vector<double> &times) {
    int fleets = 0;
    double lastFleetTime = -1.0; // No fleets yet.
    // Process each car in order from closest to farthest
    for (const double &time : times) {
      // If car arrives later than any fleet in front, it starts a new fleet.
      if (time > lastFleetTime) {
        ++fleets;
        lastFleetTime = time; // Update latest fleet arrival time to this one
      }
      // If time <= lastFleetTime, car merges into fleet (do nothing)
    }
    return fleets;
  }
};
// @lc code=end
