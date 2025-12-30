/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
  // This function returns the starting gas station's index if you can travel
  // around the circuit once in the clockwise direction, otherwise returns -1.
  // The key idea is:
  // - If the total amount of gas is less than the total cost, it's impossible
  // to complete the circuit.
  // - Otherwise, there must be a solution, and we can find it by tracking the
  // current sum. If at any point the current sum drops below zero, we reset the
  // start position to the next station.
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0, curr = 0, start = 0;
    int n = gas.size();
    for (int i = 0; i < n; ++i) {
      int diff = gas[i] - cost[i]; // Calculate the net gas at station i
      total += diff;               // Accumulate the total net gas
      curr += diff; // Accumulate the current net gas for this segment
      // If current net gas is negative, cannot reach station i+1 from current
      // start
      if (curr < 0) {
        start = i + 1; // Set next station as new start
        curr = 0;      // Reset current net gas
      }
    }
    // If total net gas is negative, it's impossible to complete the circuit
    return total >= 0 ? start : -1;
  }
};
// @lc code=end
