/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score) {
    vector<string> res(score.size());
    vector<int> sorted = score;
    sort(sorted.begin(), sorted.end(), greater<int>());
    for (int i = 0; i < score.size(); i++) {
      int rank =
          find(sorted.begin(), sorted.end(), score[i]) - sorted.begin() + 1;
      if (rank == 1) {
        res[i] = "Gold Medal";
      } else if (rank == 2) {
        res[i] = "Silver Medal";
      } else if (rank == 3) {
        res[i] = "Bronze Medal";
      } else {
        res[i] = to_string(rank);
      }
    }
    return res;
  }
};
// @lc code=end
