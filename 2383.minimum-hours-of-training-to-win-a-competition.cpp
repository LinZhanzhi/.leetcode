/*
 * @lc app=leetcode id=2383 lang=cpp
 *
 * [2383] Minimum Hours of Training to Win a Competition
 */

// @lc code=start
class Solution {
public:
  int minNumberOfHours(int initialEnergy, int initialExperience,
                       vector<int> &energy, vector<int> &experience) {
    int n = energy.size();
    int totalEnergyNeeded = 0;
    for (int i = 0; i < n; ++i) {
      totalEnergyNeeded += energy[i];
    }
    // To have strictly greater energy than sum of all energy[i], need at least
    // totalEnergyNeeded + 1
    int energyTraining = 0;
    if (initialEnergy <= totalEnergyNeeded) {
      energyTraining = totalEnergyNeeded + 1 - initialEnergy;
    }

    int expTraining = 0;
    int currExp = initialExperience;
    for (int i = 0; i < n; ++i) {
      if (currExp <= experience[i]) {
        expTraining += (experience[i] + 1 - currExp);
        currExp = experience[i] + 1;
      }
      currExp += experience[i];
    }

    return energyTraining + expTraining;
  }
};
// @lc code=end
