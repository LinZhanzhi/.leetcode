/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    // Sort boxTypes by numberOfUnitsPerBox in descending order
    sort(
        boxTypes.begin(), boxTypes.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] > b[1]; });

    int totalUnits = 0;
    for (const auto &box : boxTypes) {
      int boxesToTake = min(truckSize, box[0]);
      totalUnits += boxesToTake * box[1];
      truckSize -= boxesToTake;
      if (truckSize == 0)
        break;
    }
    return totalUnits;
  }
};
// @lc code=end
